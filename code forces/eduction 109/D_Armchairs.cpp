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
vector<ll> dp(5005, -1);
vector<ll> counter(5005, 50000);
ll solve(vector<ll> v1, vector<ll> v2, ll index)
{
  if (index == v1.size())
  {
    return 0;
  }
  if (dp[index] != -1 && counter[index] == 0)
  {
    return dp[index];
  }
  if (v1[index] == 0)
  {
    counter[index]--;
    return dp[index] = solve(v1, v2, index + 1);
  }

  if (v1[index] == 1)
  {
    ll min1 = 5005;
    ll min2 = 5005;
    for (int j = index + 1; j < v1.size(); j++)
    {
      if (v2[j] == 0)
      {
        min1 = min(min1, abs(index - j));
        break;
      }
    }
    for (int j = index - 1; j >= 0; j--)
    {
      if (v2[j] == 0)
      {
        min2 = min(min2, abs(index - j));
        break;
      }
    }
    ll t1 = 9999999, t2 = 9999999;
    if (min1 < 5005)
    {
      v2[index + min1] = 1;
      t1 = solve(v1, v2, index + 1) + min1;
      v2[index + min1] = 0;
    }
    if (min2 < 5005)
    {
      v2[index - min2] = 1;
      t2 = solve(v1, v2, index + 1) + min2;
      v2[index - min2] = 0;
    }
    counter[index]--;
    dp[index] = min(t1, t2);
    return min(t1, t2);
  }
  return 0;
}
void sol()
{
  ll n;
  cin >> n;
  vector<ll> v1(n);
  vector<ll> v2(n);
  rep(i, 0, n)
  {
    cin >> v1[i];
    if (v1[i])
      v2[i] = 1;
  }
  ll ans = 0;
  cout << solve(v1, v2, 0) << endl;
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