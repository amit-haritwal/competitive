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
bool isvalid(vector<string> v1, ll x, ll y, ll n, ll m)
{
  if (x < 0 || y < 0 || x >= n || y >= m || v1[x][y] != '.')
  {
    return false;
  }
  return true;
}
int convert(vector<string> v1, ll x, ll y, ll n, ll m)
{
  if (x < 0 || y < 0 || x >= n || y >= m)
  {
    return 1;
  }
  if (v1[x][y] == '.')
  {
    return 0;
  }
  return 1;
}
void solve(vector<string> &v1, ll x, ll y, ll &k, ll n, ll m)
{
  if (k == 0)
  {
    return;
  }
  if (v1[x][y] == '.')
  {
    if ((convert(v1, x + 1, y, n, m) + convert(v1, x, y + 1, n, m) + convert(v1, x - 1, y, n, m) + convert(v1, x, y - 1, n, m)) >= 3)
    {
      v1[x][y] = 'X';
      k--;
    }
    if (k > 0 && isvalid(v1, x + 1, y, n, m))
    {
      solve(v1, x + 1, y, k, n, m);
    }
    if (isvalid(v1, x, y + 1, n, m))
    {
      solve(v1, x, y + 1, k, n, m);
    }
    if (isvalid(v1, x, y - 1, n, m))
    {
      solve(v1, x, y - 1, k, n, m);
    }
    if (isvalid(v1, x - 1, y, n, m))
    {
      solve(v1, x - 1, y, k, n, m);
    }
  }

  if (v1[x][y] != '.')
  {

    if (isvalid(v1, x + 1, y, n, m))
    {
      solve(v1, x + 1, y, k, n, m);
    }
    if (isvalid(v1, x, y + 1, n, m))
    {

      solve(v1, x, y + 1, k, n, m);
    }
    if (isvalid(v1, x, y - 1, n, m))
    {
      solve(v1, x, y - 1, k, n, m);
    }
    if (isvalid(v1, x - 1, y, n, m))
    {
      solve(v1, x - 1, y, k, n, m);
    }
  }
}
void sol()
{
  ll n, m, k;
  cin >> n >> m >> k;
  vector<string> v1(n);
  rep(i, 0, n)
  {
    cin >> v1[i];
  }
  solve(v1, 0, 2, k, n, m);
  for (auto i : v1)
  {
    cout << i << endl;
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