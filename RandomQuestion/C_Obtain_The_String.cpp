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
const int N = int(2e5) + 99;
int nxt[N][26];
void sol()
{
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < s.size() + 5; ++i)
    for (int j = 0; j < 26; ++j)
      nxt[i][j] = 9999999;

  for (int i = int(s.size()) - 1; i >= 0; --i)
  {
    for (int j = 0; j < 26; ++j)
      nxt[i][j] = nxt[i + 1][j];
    nxt[i][s[i] - 'a'] = i;
  }

  int res = 1, pos = 0;
  for (int i = 0; i < t.size(); ++i)
  {
    if (pos == s.size())
    {
      pos = 0;
      ++res;
    }
    if (nxt[pos][t[i] - 'a'] == 9999999)
    {
      pos = 0;
      ++res;
    }
    if (nxt[pos][t[i] - 'a'] == 9999999 && pos == 0)
    {
      res = 9999999;
      break;
    }
    pos = nxt[pos][t[i] - 'a'] + 1;
  }

  if (res >= 9999999)
    cout << -1 << endl;
  else
    cout << res << endl;
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