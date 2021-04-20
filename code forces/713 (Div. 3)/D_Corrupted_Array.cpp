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
  ll n, sum = 0;
  cin >> n;
  vector<ll> v1(n + 2);
  map<ll, ll> mp;
  rep(i, 0, n + 2)
  {
    cin >> v1[i];
    mp[v1[i]]++;
    sum += v1[i];
  }
  sort(v1.begin(), v1.end());
  if (mp[sum - 2 * v1[n + 1]])
  {
    ll flag = 0;
    rep(i, 0, n + 2)
    {
      if ((flag == 0 && v1[i] == sum - 2 * v1[n + 1]) || i == n + 1)
      {
        if (v1[i] == sum - 2 * v1[n + 1])
          flag = 1;
        continue;
      }
      cout << v1[i] << " ";
    }
    cout << endl;
  }
  else if (mp[sum - 2 * v1[n]])
  {
    ll flag = 0;
    rep(i, 0, n + 2)
    {
      if ((flag == 0 && v1[i] == sum - 2 * v1[n]) || i == n)
      {
        if (v1[i] == sum - 2 * v1[n])
          flag = 1;
        continue;
      }
      cout << v1[i] << " ";
    }
    cout << endl;
  }
  else
  {
    cout << -1 << endl;
  }
  // if (sum -=)
  // rep(i, 0, n + 2)
  // {
  //   rep(j, i + 1, n + 2)
  //   {
  //     ll remaing = sum - v1[i] - v1[j];
  //     if (remaing == v1[i] || remaing == v1[j])
  //     {
  //       rep(k, 0, n + 2)
  //       {
  //         if (k != i && k != j)
  //         {
  //           cout << v1[k] << " ";
  //         }
  //       }
  //       cout << endl;
  //       return;
  //           }
  //   }
  // }
  // cout << -1 << endl;
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