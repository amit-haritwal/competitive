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
int solve(vector<ll> &choosen, vector<ll> &pre, vector<vector<ll>> v1, ll n, ll m, ll i)
{
  ll j = i - 1;
  while (true)
  {
    if (j < 0)
    {
      return -1;
    }
    rep(k, 0, v1[i].size())
    {
      if (choosen[j] == v1[i][k])
      {
        rep(l, 0, v1[j].size())
        {
          if (v1[j][l] != choosen[j] && pre[v1[j][l] - 1] < m / 2)
          {
            choosen[i] = choosen[j];
            pre[v1[j][l] - 1]++;
            choosen[j] = v1[j][l];
            return 1;
          }
        }
      }
    }
    j--;
  }
}
void sol()
{
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> v1(m);
  rep(i, 0, m)
  {
    ll l;
    cin >> l;
    vector<ll> v2(l);
    rep(j, 0, l)
    {
      cin >> v2[j];
    }
    v1[i] = v2;
  }
  if (n * 2 < m)
  {
    cout << "NO" << endl;
    return;
  }
  vector<ll> choosen(m, -1);
  vector<ll> pre(n, 0);
  ll i = 0;
  while (true)
  {
    cout << i << endl;
    if (i == m)
    {
      break;
    }
    if (i < 0)
    {
      cout << "NO" << endl;
      return;
    }
    ll flag = 0;

    if (choosen[i] == -1)
      rep(j, 0, v1[i].size())
      {
        if (pre[v1[i][j] - 1] < m / 2)
        {
          choosen[i] = v1[i][j];
          pre[v1[i][j] - 1]++;
          flag = 1;
          break;
        }
      }
    else
      flag = 1;
    if (solve(pre, choosen, v1, n, m, i) == -1)
    {
      cout << "NO" << endl;
    }
    if (flag != 0)
    {
      i++;
    }
  }
  cout << "YES" << endl;
  rep(i, 0, m)
  {
    cout << choosen[i] << " ";
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