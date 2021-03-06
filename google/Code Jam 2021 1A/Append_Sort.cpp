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
  vector<ll> v1(n);
  rep(i, 0, n)
  {
    cin >> v1[i];
  }
  // cout << endl;
  ll current = 0, j = 0, ans = 0;
  rep(i, 0, n)
  {
    if (v1[i] == current)
    {
      ans++;
      v1[i] = v1[i] * 10;
    }
    else if (v1[i] < current)
    {
      ll zero = 0, toadd = 0, t = v1[i];
      while (t > 0)
      {
        current = current / 10;
        t = t / 10;
      }
      while (current > 0)
      {
        zero++;
        current = current / 10;
        v1[i] = v1[i] * 10;
        ans++;
      }
      ll k = v1[i - 1] - v1[i];
      if (k >= 0)
      {
        while (k > 0)
        {
          toadd++;
          k = k / 10;
        }
        if (toadd > zero)
        {
          v1[i] = v1[i] * 10;
          ans++;
        }
        else if (zero > toadd)
        {
          v1[i] += v1[i - 1] - v1[i] + 1;
        }
        else
        {
          k = v1[i - 1] - v1[i];
          ll flag = 0;
          while (k > 0)
          {
            if (k % 10 != 9)
            {
              flag = 1;
              break;
            }
            k = k / 10;
          }

          if (0 == v1[i - 1] - v1[i] || flag)
          {
            v1[i] += v1[i - 1] - v1[i] + 1;
          }
          else
          {
            v1[i] = v1[i] * 10;
            ans++;
          }
        }
      }
    }
    current = v1[i];
  }
  // for (auto i : v1)
  // {
  //   cout << i << " ";
  // }
  // cout << endl;
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