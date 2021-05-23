#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define res(i, a, b) for (ll i = a; i >= b; i--)
#define all(n) n.begin(), n.end()
#define mod 1000000007
typedef long long ll;
const long long INF = 1e18 + 42;
// vector<ll> primes(10005, 1);
template <typename T>
void pop_front(std::vector<T> &vec)
{
  assert(!vec.empty());
  vec.erase(vec.begin());
}
bool compPairF(pair<ll, ll> v1, pair<ll, ll> v2)
{
  return v1.first < v2.first;
}
bool compPairS(pair<ll, ll> v1, pair<ll, ll> v2)
{
  return v1.second < v2.second;
}
//void sieveWithCount(ll n)
//{
//  vector<bool> v1(n, 1);
//  for (ll i = 2; i * i < n; i++)
//  {
//    if (primes[i] != 0)
//    {
//      for (ll j = i * i; j < n; j = j + i)
//      {
//        primes[j] = 0;
//      }
//    }
//  }
//}
#define MAXN 200002
int spf[MAXN];

void sieve()
{
  spf[1] = 1;
  for (int i = 2; i < MAXN; i++)
    spf[i] = i;
  for (int i = 4; i < MAXN; i += 2)
    spf[i] = 2;

  for (int i = 3; i * i < MAXN; i++)
  {
    if (spf[i] == i)
    {
      for (int j = i * i; j < MAXN; j += i)

        if (spf[j] == j)
          spf[j] = i;
    }
  }
}

vector<ll> getFactorization(ll x)
{
  vector<ll> ret;
  while (x != 1)
  {
    ret.push_back(spf[x]);
    x = x / spf[x];
  }
  return ret;
}
ll gcd(ll a, ll b)
{
  if (b == 0)
  {
    return a;
  }
  else
  {
    return gcd(b, a % b);
  }
}
ll power(ll x, ll y)
{
  ll temp;
  if (y == 0)
    return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
void sol()
{
  ll n;
  cin >> n;
  vector<ll> v1(n + 1);
  vector<vector<ll>> primesfact(n);
  rep(i, 0, n)
  {
    cin >> v1[i + 1];
  }
  ll pre[100005], suf[100005];
  pre[1] = v1[1];
  suf[n] = v1[n];
  for (int i = 2; i <= n; i++)
    pre[i] = gcd(pre[i - 1], v1[i]);
  for (int i = n - 1; i >= 1; i--)
    suf[i] = gcd(suf[i + 1], v1[i]);
  ll ans = 0;
  for (int i = 0; i <= n - 1; i++)
  {
    if (i == 0)
      ans = suf[2];
    else if (i == n - 1)
      ans = ans * pre[n - 1] / gcd(pre[n - 1], ans);
    else
      ans = ans * gcd(pre[i], suf[i + 2]) / gcd(gcd(pre[i], suf[i + 2]), ans);
  }
  cout << ans << endl;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a = 1;
  // cin >> a;
  while (a--)
  {
    sol();
  }
}