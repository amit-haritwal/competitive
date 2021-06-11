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
vector<int> v1[200005];
int height[200005], nochilds[200005];
void findans(ll current, ll parent)
{
  nochilds[current] = 1;
  rep(i, 0, v1[current].size())
  {
    if (v1[current][i] == parent)
      continue;
    height[v1[current][i]] = height[current] + 1;

    findans(v1[current][i], current);
    nochilds[current] += nochilds[v1[current][i]];
  }
}
void sol()
{
  int n, k;
  cin >> n >> k;
  for (int i = 1; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    v1[a - 1].push_back(b - 1);
    v1[b - 1].push_back(a - 1);
  }
  vector<ll> ans(n);
  findans(0, -1);
  rep(i, 0, n)
  {
    ans[i] = nochilds[i] - height[i] - 1;
  }
  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  ll sum = 0;
  rep(i, 0, n - k)
  {
    sum += ans[i];
  }
  cout << sum << endl;
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