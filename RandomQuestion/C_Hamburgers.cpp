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
  ll nb, ns, nc, pb, ps, pc, r;
  cin >> str >> nb >> ns >> nc >> pb >> ps >> pc >> r;
  ll b = 0, c = 0, s = 0;
  rep(i, 0, str.size())
  {
    if (str[i] == 'B')
      b++;
    if (str[i] == 'S')
      s++;
    if (str[i] == 'C')
      c++;
  }
  ll ans = 0;
  while (nb >= b && ns >= s && nc >= c)
  {
    ans++;
    nb -= b;
    ns -= s;
    nc -= c;
  }
  // cout << ans << endl;
  while (r > 0 && ((nb != 0 && b > 0) || (ns != 0 && s > 0) || (nc != 0 && c > 0)))
  {
    // cout << r << endl;
    // cout << nb << " " << ns << " " << nc << " " << ans << endl;
    if (nb < b)
    {
      r -= pb * abs(nb - b);
      nb = b;
    }
    if (ns < s)
    {
      r -= ps * abs(ns - s);
      ns = s;
    }
    if (nc < c)
    {
      r -= pc * abs(nc - c);
      nc = c;
    }
    if (r < 0)
    {
      break;
    }
    // cout << nb << " " << ns << " " << nc << " " << ans << endl;
    nb -= b;
    ns -= s;
    nc -= c;
    ans++;
    // cout << nb << " " << ns << " " << nc << " " << ans << endl;
  }
  // cout << nb << " " << ns << " " << nc << " " << ans << endl;
  // cout << ans << endl;
  if (r <= 0)
  {
    cout << ans << endl;
  }
  else
  {
    ll totol = b * pb + s * ps + c * pc;
    ans += r / totol;
    cout << ans << endl;
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