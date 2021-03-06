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
  ll n, k;
  cin >> n >> k;
  if (n == k)
  {
    rep(i, 0, k)
            cout
        << 1 << " ";
    cout << endl;
    return;
  }
  if (n % k == 0)
  {
    rep(i, 0, k)
            cout
        << n / k << " ";
    cout << endl;
    return;
  }
  if (k == 3)
  {
    if (n % 2 == 0)
    {
      if (n % 4 == 0)
        cout << n / 2 << " " << n / 4 << " " << n / 4 << endl;
      else
        cout << 2 << " " << n / 2 - 1 << " " << n / 2 - 1 << endl;
    }
    else
    {
      cout << 1 << " " << n / 2 << " " << n / 2 << endl;
    }
    return;
  }
  else
  {
    vector<ll> v2(k, 1);
    if ((n - k) % 2 == 0)
    {
      v2[0] += (n - k) / 2;
      v2[1] += (n - k) / 2;
      for (auto i : v2)
        cout
            << i << " ";
      cout << endl;
      return;
    }
    else
    {
      if (((n - k) / 2) % 2 == 0)
      {
        if (k == 4)
        {
          cout << 2 << " " << 3 << " " << ((n) / 2) - 2 << " " << ((n) / 2) - 1 << endl;
          return;
        }
        else
        {
          v2[0] += (n - k) / 2 - 1;
          v2[1] += (n - k) / 2 - 1;
          v2[2]++;
          v2[3]++;
          v2[4]++;
          for (auto i : v2)
            cout
                << i << " ";
          cout << endl;
        }
        return;
      }
      else
      {
        v2[0] += (n - k) / 2;
        v2[1] += (n - k) / 2;
        v2[2]++;
        for (auto i : v2)
          cout
              << i << " ";
        cout << endl;
        return;
      }
    }
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