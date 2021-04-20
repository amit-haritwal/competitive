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
ll check(vector<ll> v1, ll i, ll j)
{
  ll ans = 1, ans2 = 0;
  rep(k, 0, v1.size())
  {
    if (k < i || k > j)
    {
      ans *= v1[k];
    }
    else
    {
      ans2 += v1[k];
    }
  }
  if (ans == ans2)
    return ans;
  return -1;
}
void sol()
{
  ll n;
  cin >> n;
  vector<ll> v1;
  rep(i, 0, n)
  {
    ll l, t;
    cin >> l >> t;

    while (t > 0)
    {
      v1.push_back(l);
      t--;
    }
  }
  ll ans = 0;
  // for (auto i : v1)
  // {
  //   cout << i << " ";
  // }
  // cout << endl;
  rep(i, 0, v1.size())
  {
    rep(j, i, v1.size())
    {
      ans = max(ans, check(v1, i, j));
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
  int i = 1;
  while (a--)
  {
    cout << "Case #" << i << ':' << ' ';
    sol();
    i++;
  }
}