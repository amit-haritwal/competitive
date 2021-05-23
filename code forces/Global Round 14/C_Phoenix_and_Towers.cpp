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
  return v1.first > v2.first;
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
vector<ll> solve(vector<ll> v1, vector<ll> ans, ll index, vector<ll> values, ll x)
{
  if (index == v1.size())
  {
    ll min1 = *min_element(values.begin(), values.end());
    ll max1 = *max_element(values.begin(), values.end());
    if (max1 - min1 <= x)
    {
      return ans;
    }
    else
    {
      vector<ll> fatu;
      return fatu;
    }
  }
  rep(i, 0, values.size())
  {
    values[i] += v1[index];
    ans[index] = i + 1;
    vector<ll> v2 = solve(v1, ans, index + 1, values, x);
    if (v2.size() != 0)
    {
      return v2;
    }
    values[i] -= v1[index];
    ans[index] = 0;
  }
  vector<ll> fatu;
  return fatu;
}
void sol()
{
  ll n, m, x;
  cin >> n >> m >> x;
  vector<pair<ll, ll>> v1(n);
  ll sum = 0;
  rep(i, 0, n)
  {
    ll t;
    cin >> t;
    v1[i] = {t, i};
    sum += t;
  }
  sort(v1.begin(), v1.end(), compPairF);
  if (m == 1)
  {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
    {
      cout << 1 << " ";
    }
    cout << endl;
    return;
  }
  ll tocom = sum / m;
  ll j = 0;
  vector<ll> ans(n), values(m);
  ll t = 1;
  // rep(i, 0, m)
  // {
  //   if (j == n)
  //   {
  //     break;
  //     t = 0;
  //   }
  //   while ((v1[j].first + values[i]) <= tocom || values[i] == 0)
  //   {

  //     values[i] += v1[j].first;
  //     ans[v1[j].second] = i + 1;
  //     j++;
  //     if (j == n)
  //     {
  //       break;
  //     }
  //   }
  // }
  // if (!t)
  // {
  //   cout << "NO" << endl;
  //   return;
  // }
  ll flag = 1;
  while (flag)
  {
    if (values[0] > values[m - 1])
      for (ll i = m - 1; i >= 0; i--)
      {
        if (j == n)
        {
          flag = 0;
          break;
        }
        values[i] += v1[j].first;
        ans[v1[j].second] = i + 1;
        j++;
        if (j == n)
        {
          flag = 0;
          break;
        }
      }
    else
      for (ll i = 0; i < m; i++)
      {
        if (j == n)
        {
          flag = 0;
          break;
        }
        values[i] += v1[j].first;
        if (j == n)
        {
          flag = 0;
          break;
        }
        ans[v1[j].second] = i + 1;
        j++;
        if (j == n)
        {
          flag = 0;
          break;
        }
      }
  }
  cout << "YES" << endl;
  for (auto i : ans)
  {
    cout << i << " ";
  }
  cout << endl;
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