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
vector<vector<ll>> pre(vector<vector<ll>> v1, ll n, ll m)
{
  vector<vector<ll>> dp(n, vector<ll>(m, 0));
  rep(i, 0, n)
  {
    rep(j, 0, m)
    {
      dp[i][j] = j - 1 >= 0 ? dp[i][j - 1] + v1[i][j] : v1[i][j];
    }
  }
  rep(i, 1, n)
  {
    rep(j, 0, m)
    {
      dp[i][j] += dp[i - 1][j];
    }
  }

  return dp;
}
ll sum(vector<vector<ll>> dp, ll r1, ll c1, ll r2, ll c2)
{
  ll sub1 = r1 - 1 < 0 ? 0 : dp[r1 - 1][c2];
  ll sub2 = c1 - 1 < 0 ? 0 : dp[r2][c1 - 1];
  ll add1 = r1 - 1 < 0 || c1 - 1 < 0 ? 0 : dp[r1 - 1][c1 - 1];
  return dp[r2][c2] - sub1 - sub2 + add1;
}
ll presolve(vector<vector<ll>> dp, ll l, ll r, ll hr, ll t, ll i, ll j)
{
  if (l > r || l < 0 || r > t + 1)
  {
    return 0;
  }
  ll mid = (l + r) / 2;
  ll a = sum(dp, i + mid - t, j + mid - t, i, j);
  // cout << i << " " << j << " " << l << " " << r << " " << mid << " " << t - mid + 1 << endl;

  if (a <= (t - mid + 1) * (t - mid + 1) * hr)
  {
    return max(t - mid + 1, presolve(dp, l, mid - 1, hr, t, i, j));
  }
  else
  {
    return presolve(dp, mid + 1, r, hr, t, i, j);
  }
}
void sol()
{
  ll n, m, hr;
  cin >> n >> m >> hr;
  vector<vector<ll>> v1(n);
  rep(i, 0, n)
  {
    vector<ll> v2(m);
    rep(j, 0, m)
    {
      cin >> v2[j];
    }
    v1[i] = v2;
  }

  vector<vector<ll>> v2 = pre(v1, n, m);
  // for (auto i : v2)
  // {
  //   for (auto j : i)
  //   {
  //     cout << j << " ";
  //   }
  //   cout << endl;
  // }
  ll ans = 0;
  for (ll i = n - 1; i >= 0; i--)
  {
    for (ll j = m - 1; j >= 0; j--)
    {
      ll t = min(i, j);
      // for (ll k = 0; k <= t; k++)
      // {
      //   ll a = sum(v2, i + k - t, j + k - t, i, j);
      //   if (a >= (t - k + 1) * (t - k + 1) * hr)
      //   {
      //     ans += t - k + 1;
      //     break;
      //   }
      // }
      ans += presolve(v2, 0, t + 1, hr, t, i, j);
    }
  }
  cout << ans << endl;
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