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
ll binarySearch(vector<ll> arr, ll l, ll r, ll x)
{
  while (l <= r)
  {
    ll m = l + (r - l) / 2;

    // Check if x is present at mid
    if (arr[m] == x)
      return m;

    // If x greater, ignore left half
    if (arr[m] < x)
      l = m + 1;

    // If x is smaller, ignore right half
    else
      r = m - 1;
  }

  // if we reach here, then element was
  // not present
  return -1;
}

void sol()
{
  ll n, k;
  cin >> n >> k;
  vector<ll> v1(n), v2;
  rep(i, 0, n)
  {
    cin >> v1[i];
  }
  v2 = v1;
  sort(v2.begin(), v2.end());
  ll j = 0;
  map<ll, ll> mp;
  for (auto i : v2)
  {
    mp[i] = j;
    j++;
  }
  ll i = 0;
  while (true)
  {
    if (i == n)
    {
      break;
    }
    if (k == 0)
    {
      cout << "No" << endl;
      return;
    }
    ll t = mp[v1[i]];
    // cout << i << " " << t << endl;
    rep(j, i, n)
    {
      if (v1[j] != v2[t])
      {
        k--;
        break;
      }
      i++;
      t++;
    }
  }
  cout << "Yes" << endl;
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