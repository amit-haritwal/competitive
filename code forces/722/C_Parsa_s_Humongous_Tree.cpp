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
struct node
{
  vector<node *> v1;
  ll l, r;
};
vector<vector<ll>> graph;
vector<pair<ll, ll>>
    v1;
pair<ll, ll> dfs(ll prev, ll current)
{
  // cout << "hi" << endl;
  if (graph[current].size() == 1 && prev != -1)
  {
    return {0, 0};
  }

  ll min1 = 0, max1 = 0;
  for (auto i : graph[current])
  {
    if (i != prev)
    {

      pair<ll, ll> ans = dfs(current, i);
      min1 += max(abs(v1[i - 1].second - v1[current - 1].first) + ans.second,
                  abs(v1[i - 1].first - v1[current - 1].first) + ans.first);
      max1 += max(abs(v1[i - 1].first - v1[current - 1].second) + ans.first,
                  abs(v1[i - 1].second - v1[current - 1].second) + ans.second);
    }
  }
  return {min1, max1};
}
void sol()
{
  ll n;
  cin >> n;
  v1.resize(n);
  rep(i, 0, n)
  {
    cin >> v1[i].first >> v1[i].second;
  }
  graph.resize(n + 5);
  rep(i, 0, n - 1)
  {
    ll l, r;
    cin >> l >> r;
    graph[l].push_back(r);
    graph[r].push_back(l);
  }
  pair<ll, ll> ans = dfs(-1, 1);
  cout << max(ans.first, ans.second) << endl;
  graph.clear();
  v1.clear();
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