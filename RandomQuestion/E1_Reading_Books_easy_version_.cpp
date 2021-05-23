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
bool comp(vector<ll> v1, vector<ll> v2)
{
  return v1[0] < v2[0];
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
  ll n, k;
  cin >> n >> k;
  vector<vector<ll>> v1;
  rep(i, 0, n)
  {
    vector<ll> v2(3);
    cin >> v2[0] >> v2[1] >> v2[2];
    if (v2[1] != 0 || v2[2] != 0)
      v1.push_back(v2);
  }
  sort(v1.begin(), v1.end(), comp);
  vector<ll> ans;
  priority_queue<ll, vector<ll>, greater<ll>> a;
  priority_queue<ll, vector<ll>, greater<ll>> b;

  for (auto i : v1)
  {
    if (i[1] == 1 && i[2] == 1)
    {
      ans.push_back(i[0]);
    }
    else if (i[1] == 1)
    {
      if (a.empty())
      {
        b.push(i[0]);
      }
      else
      {
        ll t = a.top();
        a.pop();
        ans.push_back(t + i[0]);
      }
    }
    else
    {
      if (b.empty())
      {
        a.push(i[0]);
      }
      else
      {
        ll t = b.top();
        b.pop();
        ans.push_back(t + i[0]);
      }
    }
  }
  sort(ans.begin(), ans.end());
  ll final = 0;
  for (auto i : ans)
  {
    if (k == 0)
    {
      break;
    }
    k--;
    final += i;
  }
  if (k == 0)
    cout << final << endl;
  else
    cout << -1 << endl;
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