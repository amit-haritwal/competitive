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
constexpr int N = 110;
int a[N][N];
int sum(int i, int j)
{
  if ((i & 1) ^ (j & 1))
  {
    return 1;
  }
  return 2;
}
void sol()
{
  std::ios::sync_with_stdio(false);
  int n;
  std::cin >> n;
  for (int i = n * n; i; i--)
  {
    int ban;
    std::cin >> ban;
    bool flag = true;
    for (int i = 1; flag && i <= n; i++)
    {
      for (int j = 1; flag && j <= n; j++)
      {
        const auto &color = sum(i, j);
        if (color == ban)
        {
          continue;
        }
        if (a[i][j] == 0)
        {
          a[i][j] = color;
          std::cout << color << " "
                    << i << " "
                    << j << std::endl;
          flag = false;
          break;
        }
      }
    }
    for (int i = 1; flag && i <= n; i++)
    {
      for (int j = 1; flag && j <= n; j++)
      {
        const auto &color = sum(i, j);
        if (color != ban)
        {
          continue;
        }
        if (a[i][j] == 0)
        {
          a[i][j] = 3;
          std::cout << 3 << " "
                    << i << " "
                    << j << std::endl;
          flag = false;
          break;
        }
      }
    }
    if (flag)
    {
      for (;;)
      {
      }
    }
  }
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