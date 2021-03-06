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
  ll n, m;
  cin >> n >> m;
  map<ll, vector<ll>> mp, mp1;
  vector<ll> v1(n), v2(n), v3(m);
  vector<ll> ans(m);
  ll flag = -1;
  rep(i, 0, n)
  {
    cin >> v1[i];
  }
  rep(i, 0, n)
  {
    cin >> v2[i];
    if (v1[i] != v2[i])
    {
      mp[v2[i]].push_back(i);
    }
    else
    {
      mp1[v2[i]].push_back(i);
    }
  }
  rep(i, 0, m)
  {
    cin >> v3[i];
    if (mp[v3[i]].size() == 0 && mp1[v3[i]].size() == 0)
    {
      if (flag == -1)
        flag = i;
    }
    else
    {
      if (mp[v3[i]].size() != 0)
      {
        ans[i] = mp[v3[i]][mp[v3[i]].size() - 1];
        mp[v3[i]].pop_back();
      }
      else
      {

        ans[i] = mp1[v3[i]][mp1[v3[i]].size() - 1];
        // mp1[v3[i]].pop_back();
      }
      if (flag != -1)
        rep(k, flag, i + 1)
        {
          ans[k] = ans[i];
        }
      flag = -1;
    }
  }
  if (flag != -1)
  {
    cout << "NO" << endl;
    return;
  }
  for (auto i : mp)
  {
    if (i.second.size() != 0)
    {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
  for (auto i : ans)
  {
    cout << i + 1 << " ";
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