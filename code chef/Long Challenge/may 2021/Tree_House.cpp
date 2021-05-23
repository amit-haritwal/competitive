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
const int maxn = 3E5 + 5;

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
vector<ll> adj[maxn], dp, v1;
vector<pair<ll, ll>> traking;
void count(ll current, ll prev = -1)
{
  for (auto x : adj[current])
  {
    if (x != prev)
      count(x, current);
  }
  traking.clear();
  for (auto x : adj[current])
  {
    if (x != prev)
      traking.emplace_back(dp[x], x);
  }
  sort(traking.begin(), traking.end());
  reverse(traking.begin(), traking.end());
  ll tok = 1;
  for (auto i : traking)
  {
    ll _v1 = i.first;
    ll id = i.second;
    v1[id] = tok++;
  }
  for (auto x : adj[current])
  {
    if (x != prev)
      dp[current] += v1[x] * dp[x];
  }
}
void sol()
{
  ll N, X;
  cin >> N >> X;

  dp.assign(N, 1), v1.assign(N, 0);
  for (ll i = 0; i < N; ++i)
    vector<ll>().swap(adj[i]);

  for (ll i = 0; i < N - 1; ++i)
  {
    ll u, v;
    cin >> u >> v;
    --u;
    --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  count(0);

  cout << dp[0] % mod * X % mod << "\n";
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