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
#include <unordered_map>
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
typedef std::numeric_limits<double> dbl;
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
};
void sol()
{
  ll n, k;
  cin >> n >> k;
  unordered_map<ll, ll> mp;
  rep(i, 0, n)
  {
    ll t;
    cin >> t;
    mp[t]++;
  }
  ll fg = 0, bg = 0;
  ll i = 1;
  while (!mp[i])
  {
    i++;
    fg++;
  }
  i = k;
  while (!mp[i])
  {
    i--;
    bg++;
  }
  ll ans = fg + bg;
  ll max1 = max(bg, fg);
  ll max2 = min(bg, fg);
  ll t = 1;
  while (!mp[t])
  {
    t++;
  }
  rep(i, t, k)
  {
    if (!mp[i])
    {
      ll temp = 0;
      while (!mp[i] && i <= k)
      {
        i++;
        temp++;
      }
      // cout << temp << " " << i << endl;
      if (i <= k)
      {
        ll why = (temp + 1) / 2;
        if (why > max1)
        {
          max2 = max1;
          max1 = why;
        }
        else if (why > max2)
        {
          max2 = why;
        }
        ans = max({ans, temp, max1 + max2});
      }
    }
  }
  cout << (double)ans / k << endl;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a = 1;
  cin >> a;
  int i = 1;
  while (a--)
  {
    cout << "Case #" << i << ':' << ' ';
    sol();
    // printf("Case #%d: %.9lf\n", i, 1. * t.first / t.second);
    i++;
  }
}