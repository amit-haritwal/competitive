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
vector<ll> precomputed;
void sol()
{
  ll n, k;
  cin >> n >> k;
  ll tempn = n, tempk = k;
  string str1 = "", str2 = "";
  if (k % n != 0)
  {
    cout << -1 << endl;
    return;
  }
  ll ans = 0, flag = 0;
  k = k / n;
  while (k > 0)
  {
    ll co = 0;
    for (int i = 0; i < 64; i++)
    {

      if (k < precomputed[i])
        break;
      co++;
    }
    k = k - precomputed[co - 1];
    // cout << k << " " << precomputed[co] << endl;
    ans += co;
    if (k > 0)
      ans++;
  }
  cout << ans << endl;
  // ll count = 0;
  // while (k > 0)
  // {
  //   if (k % 2)
  //   {
  //     str2 += '1';
  //   }
  //   else
  //   {
  //     str2 += '0';
  //   }
  //   count++;
  //   k = k / 2;
  // }
  // n = 1;
  // k = tempk;

  // rep(i, 1, str2.size())
  // {
  //   if (str2[i] != str2[i - 1])
  //     ans++;
  // }
  // rep(i, 0, str2.size())
  // {
  //   if (str2[i] == '1')
  //   {
  //     if (flag)
  //     {
  //       ans += i + 1;
  //     }
  //     else
  //     {
  //       ans++;
  //     }
  //   }
  //   else
  //   {
  //     flag = 1;
  //   }
  // }

  // cout << ans << endl;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a = 1;
  cin >> a;
  rep(i, 0, 63)
  {
    precomputed.push_back(power(2, i + 1) - 1);
  }
  while (a--)
  {
    sol();
  }
}