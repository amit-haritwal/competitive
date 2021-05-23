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
ll bfs(map<ll, vector<ll>> graph, ll prev, ll tofind, ll current)
{
  if (tofind == current)
  {
    return 0;
  }
  vector<ll> v1 = graph[current];
  for (auto i : v1)
  {
    if (i == tofind)
    {
      return 1;
    }
  }
  for (auto i : v1)
  {
    if (i != prev)
    {

      ll t = bfs(graph, current, tofind, i);
      if (t != -1)
      {
        return t + 1;
      }
    }
  }
  return -1;
}
void sol()
{
  ll n, k, a;
  cin >> n >> k >> a;
  vector<ll> v1(k);
  rep(i, 0, k)
  {
    cin >> v1[i];
  }
  map<ll, vector<ll>> graph;

  rep(i, 0, n - 1)
  {
    ll t1, t2;
    cin >> t1 >> t2;
    graph[t1].push_back(t2);
    graph[t2].push_back(t1);
  }
  map<pair<ll, ll>, ll> pre;
  rep(i, 0, n)
  {
    rep(j, 0, k)
    {
      if (!pre[{v1[j], i + 1}] && !pre[{i + 1, v1[j]}])
      {
        pre[{v1[j], i + 1}] = bfs(graph, -1, v1[j], i + 1);
        pre[{i + 1, v1[j]}] = pre[{v1[j], i + 1}];
      }
      if (!pre[{v1[j], a}] && !pre[{a, v1[j]}])
      {
        pre[{v1[j], a}] = bfs(graph, -1, v1[j], a);
        pre[{a, v1[j]}] = pre[{v1[j], a}];
      }
    }
  }
  vector<pair<ll, ll>> ans;
  rep(i, 0, n)
  {
    ll min1 = 9999999, min2 = 0, valu1 = -1;
    rep(j, 0, k)
    {
      ll t1 = pre[{v1[j], i + 1}];
      ll t2 = pre[{v1[j], a}];
      if (t1 == -1 || t2 == -1)
      {
        continue;
      }
      if (min2 - min1 < t2 - t1)
      {
        min2 = t2;
        min1 = t1;
        valu1 = v1[j];
      }
    }
    ans.push_back({min2 - min1, valu1});
  }
  rep(i, 0, n)
  {
    cout << ans[i].first << " ";
  }
  cout << endl;
  rep(i, 0, n)
  {
    cout << ans[i].second << " ";
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