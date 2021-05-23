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
#define PER(i, s, t) for (ll i = (s); i >= (t); --i)
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
  vector<ll> v1(n + 1), fl(n + 1), fr(n + 1);
  rep(i, 1, n + 1) cin >> v1[i];
  ll ans = 1;
  rep(i, 1, n + 1)
  {
    if (v1[i] > v1[i - 1] && i > 1)
      fl[i] = fl[i - 1] + 1;
    else
      fl[i] = 1;
    ans = max(ans, min(fl[i] + 1, n));
  }
  PER(i, n, 1)
  {
    if (v1[i] < v1[i + 1] && i < n)
      fr[i] = fr[i + 1] + 1;
    else
      fr[i] = 1;
    ans = max(ans, min(fr[i] + 1, n));
  }
  for (int mid = 2; mid < n; ++mid)
  {
    int x = v1[mid - 1], y = v1[mid + 1];
    if (x + 1 < y)
    {
      ans = max(ans, fl[mid - 1] + fr[mid + 1] + 1);
    }
  }
  printf("%d\n", ans);
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