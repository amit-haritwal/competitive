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
void binser(ll l, ll r, vector<ll> v1, vector<ll> v2, ll n)
{
  if (l > r)
  {
    return;
  }
  cout << "? " << l + 1 << endl;
  cin >> v1[l];
  v2[l]++;
  if (v1[l] == 1)
  {
    cout << "! " << l + 1 << endl;
    return;
  }
  cout << "? " << r + 1 << endl;
  cin >> v1[r];
  v2[r]++;
  if (v1[r] == 1)
  {
    cout << "! " << r + 1 << endl;
    return;
  }
  ll mid = (l + r) / 2;
  cout << "? " << mid + 1 << endl;
  cin >> v1[mid];
  if (v1[mid] == 1)
  {
    cout << "! " << mid << endl;
    return;
  }
  return binser(mid + 1, r - 1, v1, v2, n);
  return binser(l + 1, mid - 1, v1, v2, n);
}
void sol()
{
  ll n, t = 100;
  cin >> n;
  vector<ll> v1(n, 0), v2(n);
  ll l = 0, r = n - 1, mid;
  cout << "? " << l + 1 << endl;
  cin >> v1[l];
  v2[l]++;
  if (v1[l] == 1)
  {
    cout << "! " << l + 1 << endl;
  }
  cout << "? " << r + 1 << endl;
  cin >> v1[r];
  v2[r]++;
  if (v1[r] == 1)
  {
    cout << "! " << r + 1 << endl;
  }
  binser(l + 1, r - 1, v1, v2, n);
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
  cout.flush();
}