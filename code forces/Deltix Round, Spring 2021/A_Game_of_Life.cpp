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
  string str;
  cin >> n >> m >> str;
  vector<ll> v1(n, 0);
  rep(i, 0, n)
  {
    if (str[i] == '1')
    {
      rep(j, 0, m + 1)
      {
        if (i - j < 0)
          break;
        v1[i - j] = 1;
      }
      break;
    }
  }
  rep(i, 0, n)
  {
    if (str[n - i - 1] == '1')
    {
      // cout << n - i - 1 << endl;
      rep(j, 0, m + 1)
      {
        if (n - i - 1 + j >= n)
          break;
        v1[n - i - 1 + j] = 1;
      }
      break;
    }
  }
  rep(i, 0, n)
  {

    if (str[i] == '1')
    {
      v1[i] = 1;
      rep(j, i + 1, n)
      {
        if (str[j] == '1')
        {
          // cout << i << " " << j;
          if ((j - i) / 2 > m)
          {
            // cout << "hi" << endl;
            rep(k, i, i + m + 1)
            {
              if (k >= n)
                break;
              v1[k] = 1;
            }
            rep(k, 0, m + 1)
            {
              if (k < 0)
                break;
              v1[j - k] = 1;
            }
          }
          else if ((j - i - 1) % 2 == 0)
          {
            // cout << "hi1" << endl;
            rep(k, i, j + 1)
            {
              v1[k] = 1;
            }
          }
          else
          {
            // cout << "hi2" << endl;
            rep(k, i, j + 1)
            {
              // cout << k << " " << i << " " << j << endl;
              if (k == (j + i) / 2)
              {

                continue;
              }

              v1[k] = 1;
            }
          }
          break;
        }
      }
    }
  }

  for (auto i : v1)
    cout << i;
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