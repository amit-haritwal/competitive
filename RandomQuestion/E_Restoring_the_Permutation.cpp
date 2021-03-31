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
void sol()
{
  ll n;
  cin >> n;
  vector<ll> v1(n), pre(n, 0), post(n, 0);
  vector<ll> ans(n), ans2(n);
  rep(i, 0, n)
  {
    cin >> v1[i];
    ans[i] = 1;
    ans2[i] = 1;
  }
  rep(i, 0, n)
  {
    if (i == 0)
    {
      pre[i] = v1[i];
      post[i] = v1[i];
      ans[v1[i] - 1] = 0;
      ans2[v1[i] - 1] = 0;
    }
    else if (v1[i] != v1[i - 1])
    {
      pre[i] = v1[i];
      post[i] = v1[i];
      ans[v1[i] - 1] = 0;
      ans2[v1[i] - 1] = 0;
    }
  }
  ll t = 0;
  rep(i, 0, n)
  {

    if (pre[i] == 0)
    {

      rep(j, t, n)
      {

        if (ans[j] != 0)
        {
          ans[j] = 0;
          pre[i] = j + 1;
          t = j;
          break;
        }
      }
    }
  }
  for (auto i : pre)
  {
    cout << i << " ";
  }
  cout << endl;
  ll first = v1[0];
  rep(i, 0, n)
  {
    if (post[i] == 0)
    {
      for (ll j = first - 1; j >= 0; j--)
      {
        if (ans2[j] != 0)
        {
          // cout << i << " " << j << " " << first << endl;
          post[i] = j + 1;
          ans2[j] = 0;
          break;
        }
      }
    }
    else
    {
      first = post[i];
    }
  }
  for (auto i : post)
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