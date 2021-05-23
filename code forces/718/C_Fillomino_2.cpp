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
  vector<vector<ll>> v1(n, vector<ll>(n, 0));
  rep(i, 0, n)
  {
    cin >> v1[i][i];
  }

  rep(i, 0, n)
  {

    ll k = v1[i][i];
    ll t = v1[i][i];
    ll x = i, j = i;
    while (k > 1)
    {
      if (j - 1 >= 0 && v1[x][j - 1] == 0)
      {
        v1[x][j - 1] = t;
        // cout << "l" << endl;
        j--;
        k--;
      }
      else if (x + 1 < n && v1[x + 1][j] == 0)
      {
        v1[x + 1][j] = t;
        k--;
        x++;
        // cout << "b" << endl;
      }
      else if (j + 1 < i && v1[x][j + 1] == 0)
      {
        v1[x][j + 1] = t;
        j++;
        k--;
        // cout << "r" << endl;
      }

      else if (x - 1 > i && v1[x - 1][j] == 0)
      {
        v1[x - 1][j] = t;
        k--;
        // cout << "t" << endl;

        x--;
      }

      else
      {
        cout << -1 << endl;
        return;
      }
      // rep(i, 0, n)
      // {
      //   rep(j, 0, n)
      //   {
      //     cout << v1[i][j] << " ";
      //   }
      //   cout << endl;
      // }
      // cout << endl;
    }
  }

  rep(i, 0, n)
  {
    rep(j, 0, i + 1)
    {
      cout << v1[i][j] << " ";
    }
    cout << endl;
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