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
#define MAXN 1000001

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
  ll t = sqrt(x);
  ll i = 0;
  ll k = 2;
  while (x > 1 && t > i)
  {
    i++;
    if (x % t == 0)
    {
      ret.push_back(t);
      x = x / t;
    }
    else
    {
      t++;
    }
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
  vector<ll> t = getFactorization(n);
  if (t.size() == 0 || t[0] == n)
  {
    cout << "NO" << endl;
    return;
  }
  if (t.size() > 2 || t.size() == 0)
  {
    cout << "NO" << endl;
  }
  else if (t.size() == 2)
  {
    if (t[0] == t[1] && t[0] * t[1] == n)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  else
  {
    cout << "YES" << endl;
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  sieve();
  ll a = 1;
  cin >> a;
  while (a--)
  {
    sol();
  }
}