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
bool digit(ll n)
{
  ll ans = n % 10;
  while (n > 0)
  {
    if (ans != n % 10)
      return false;
    n = n / 10;
  }
  return true;
}
void sol()
{
  ll n;
  cin >> n;
  ll t = n;
  ll ans = 0;
  ll min1 = t % 10, flag = 0;
  ll ans1 = 0;
  // rep(i, 1, n + 1)
  // {
  //   if (digit(i))
  //   {
  //     ans1++;
  //   }
  // }
  // cout << ans1 << " ";
  while (t > 0)
  {
    if (t % 10 != min1)
    {
      flag = 1;
    }
    t = t / 10;
    ans += 9;
  }
  ans -= 9;
  // cout << ans << endl;
  t = n;
  while (t >= 10)
  {
    t = t / 10;
  }
  ll a = t;
  ll yy = n;
  while (n >= 10)
  {
    a = a * 10 + t;
    n = n / 10;
  }
  if (yy >= a)
  {
    ans++;
  }
  // cout << ans << " " << t << endl;

  cout << ans + t - 1 << endl;
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