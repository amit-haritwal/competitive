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
  return v1.second > v2.second;
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
  vector<pair<ll, ll>> v1(m);
  vector<vector<ll>> v2(n, vector<ll>(m, 0));
  rep(i, 0, n)
  {

    vector<ll> v3(m);
    rep(j, 0, m)
    {
      ll t = 0;
      cin >> t;
      if (i == 0)
      {
        v2[i][j] = t;
        v1[j] = {j, t};
      }
      v3[j] = t;
    }
    if (i != 0)
    {
      sort(v3.begin(), v3.end());
      ll flag = 0, k = 0;
      rep(j, 0, m)
      {
        ll t = v3[j];
        if (v1[k].second > t)
        {
          // cout << v1[k].first << " " << k << " " << v1[k].second << endl;
          v2[i][v1[k].first] = t;
          v1[k] = {v1[k].first, t};

          k++;
        }
        else
        {
          rep(r, 0, m)
          {
            if (v2[i][r] == 0)
            {
              v2[i][r] = t;
              break;
            }
          }
        }
        // rep(i, 0, n)
        // {
        //   rep(j, 0, m)
        //   {
        //     cout << v2[i][j] << " ";
        //   }
        //   cout << endl;
        // }
        // cout << "hi" << endl;
        // for (auto i : v1)
        // {
        //   cout << i.second << " ";
        // }
        // cout << endl;
        // cout << endl;
      }
    }
    sort(v1.begin(), v1.end(), compPairS);
  }
  rep(i, 0, n)
  {
    rep(j, 0, m)
    {
      cout << v2[i][j] << " ";
    }
    cout << endl;
  }
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