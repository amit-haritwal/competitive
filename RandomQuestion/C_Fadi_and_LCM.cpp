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
vector<ll> primefactorisation(ll n)
{
  vector<ll> ans;
  ll t = 2;
  while (n > 1)
  {
    if (n % t == 0)
    {
      ans.push_back(t);
      n = n / t;
    }
    else
    {
      t++;
    }
  }
  return ans;
}

ll lcm(ll a, ll b)
{
  return (a / gcd(a, b)) * b;
}
vector<pair<ll, ll>> dp(1000000, {-1, -1});
pair<ll, ll> solve(vector<ll> v1, ll sum1, ll sum2, ll index)
{
  if (index == v1.size())
  {
    return {sum1, sum2};
  }
  pair<ll, ll> v3 = solve(v1, sum1 * v1[index], sum2, index + 1);
  pair<ll, ll> v2 = solve(v1, sum1, sum2 * v1[index], index + 1);
  if (max(v3.first, v3.second) > max(v2.first, v2.second))
  {
    dp[index] = v2;
    return v2;
  }
  else
  {
    dp[index] = v3;
    return v3;
  }
}
void sol()
{
  ll n;
  cin >> n;

  ll current1 = 999999999999;
  ll ans1 = 1, ans2 = n;
  rep(i, 1, sqrt(n))
  {
    if (n % i == 0 && lcm(i, n / i) == n && max(i, n / i) < current1)
    {
      current1 = max(i, n / i);
      ans1 = i;
      ans2 = n / i;
    }
  }
  cout << ans1 << " " << ans2 << endl;
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