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
// vector<ll> primes(10005, 1);
// void sieveWithCount(ll n)
// {
//   vector<bool> v1(n, 1);
//   for (ll i = 2; i * i < n; i++)
//   {
//     if (primes[i] != 0)
//     {
//       for (ll j = i * i; j < n; j = j + i)
//       {
//         primes[j] = 0;
//       }
//     }
//   }
// }
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
bool isPrime(ll n)
{
  ll flag = 0;
  for (int i = 2; i <= n / 2; ++i)
  {
    if (n % i == 0)
    {
      flag = 1;
      break;
    }
  }
  return !flag;
}
void sol()
{
  ll n;
  cin >> n;
  ll prev = 0;
  ll ans = 0;
  ll t = int(pow(n, 0.5));
  // cout << t << endl;

  ll flag = 0;
  ans = 1;
  ll temp = 0, l = t + 1;
  while (l)
  {

    if (isPrime(l))
    {
      temp = l;
      break;
    }
    l++;
  }
  while (t)
  {

    if (flag == 1)
    {
      if (ans * temp <= n)
      {
        ans = ans * temp;
        break;
      }
    }
    if (flag == 2)
    {
      break;
    }
    if (isPrime(t))
    {
      flag++;
      ans = ans * t;
    }
    t--;
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