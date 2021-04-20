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
  string str;
  ll n, m;
  cin >> n >> m >> str;
  if (n % 2 != 0 && m % 2 != 0)
  {
    cout << -1 << endl;
    return;
  }
  rep(i, 0, str.size())
  {
    if (str[i] == '0')
      n--;
    else if (str[i] == '1')
      m--;
  }
  ll i = 0, j = str.size() - 1;
  while (i <= j)
  {
    if (str[i] == str[j])
    {
      i++;
      j--;
      continue;
    }
    else if (str[i] == '?')
    {
      if (str[j] == '0')
      {
        n--;
        str[i] = '0';
      }
      else
      {
        m--;
        str[i] = '1';
      }
      i++;
      j--;
    }
    else if (str[j] == '?')
    {
      if (str[i] == '0')
      {
        n--;
        str[j] = '0';
      }
      else
      {
        m--;
        str[j] = '1';
      }
      i++;
      j--;
    }
    else
    {
      cout << -1 << endl;
      return;
    }
  }
  // cout << str << " " << n << " " << m << endl;
  if (n < 0 || m < 0)
  {
    cout << -1 << endl;
    // cout << "hi";
    return;
  }
  i = 0;
  j = str.size() - 1;
  while (i <= j)
  {
    if (str[i] == '?')
    {
      if (n > m)
      {
        str[i] = '0';
        str[j] = '0';
        n -= 2;
        if (i == j)
          n++;
      }
      else
      {
        str[i] = '1';
        str[j] = '1';
        m -= 2;
        if (i == j)
          m++;
      }
    }
    i++;
    j--;
  }
  if (n != 0 || m != 0)
  {

    cout << -1 << endl;
    return;
  }
  rep(i, 0, str.size() - 1)
  {
    if (str[i] != str[str.size() - 1 - i])
    {
      cout << -1 << endl;
      return;
    }
  }
  cout << str << endl;
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