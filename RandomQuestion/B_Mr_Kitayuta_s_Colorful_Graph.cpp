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
ll ans = 0;
map<ll, ll> mp;
void bfs(ll current, ll dest, ll color, vector<vector<pair<ll, ll>>> v1, vector<ll> visited)
{
  if (current == dest)
  {
    ans++;
    mp[color]++;
    return;
  }
  visited[current] = 1;
  for (auto i : v1[current])
  {
    if (!visited[i.first])
    {
      if (color == -1)
      {
        visited[i.first] = 1;
        bfs(i.first, dest, i.second, v1, visited);
        visited[i.first] = 0;
      }
      else
      {
        if (!mp[color] && i.second == color)
        {
          visited[i.first] = 1;
          bfs(i.first, dest, i.second, v1, visited);
          visited[i.first] = 0;
        }
      }
    }
  }
  visited[current] = 0;
}
void sol()
{
  ll n, m;
  cin >> n >> m;

  vector<vector<pair<ll, ll>>> v1(n + 10);
  rep(i, 0, m)
  {
    ll l, r, c;
    cin >> l >> r >> c;
    v1[l].push_back({r, c});
    v1[r].push_back({l, c});
  }
  ll t;
  cin >> t;
  rep(i, 0, t)
  {
    ll l, r;
    ans = 0;
    mp.clear();
    cin >> l >> r;
    vector<ll> visited(n + 10, 0);
    bfs(l, r, -1, v1, visited);
    cout << ans << endl;
  }
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