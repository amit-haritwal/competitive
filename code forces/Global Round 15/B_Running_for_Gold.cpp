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
  vector<vector<ll>> v1;
  rep(i, 0, n)
  {
    ll a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    v1.push_back({a, b, c, d, e});
  }
  ll ans = -1;
  ll preans = 0;
  rep(i, 1, n)
  {

    ll temp = 0;
    if (v1[i][0] < v1[preans][0])
    {
      temp++;
    }
    if (v1[i][1] < v1[preans][1])
    {
      temp++;
    }
    if (v1[i][2] < v1[preans][2])
    {
      temp++;
    }
    if (v1[i][3] < v1[preans][3])
    {
      temp++;
    }
    if (v1[i][4] < v1[preans][4])
    {
      temp++;
    }
    if (temp >= 3)
    {
      preans = i;
    }
  }
  ans = preans;
  rep(i, 0, n)
  {

    ll temp = 0;
    if (v1[i][0] < v1[preans][0])
    {
      temp++;
    }
    if (v1[i][1] < v1[preans][1])
    {
      temp++;
    }
    if (v1[i][2] < v1[preans][2])
    {
      temp++;
    }
    if (v1[i][3] < v1[preans][3])
    {
      temp++;
    }
    if (v1[i][4] < v1[preans][4])
    {
      temp++;
    }
    if (temp >= 3)
    {
      cout << -1 << endl;
      return;
    }
  }

  cout << ans + 1 << endl;
  // cout << endl;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a = 1;
  cin >> a;
  while (a--)
  {
    sol();
  }
}