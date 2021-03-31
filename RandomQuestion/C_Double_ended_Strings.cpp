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
int LCSubStr(string X, string Y, int m, int n)
{
  // Create a table to store
  // lengths of longest
  // common suffixes of substrings.
  // Note that LCSuff[i][j] contains
  // length of longest common suffix
  // of X[0..i-1] and Y[0..j-1].

  int LCSuff[m + 1][n + 1];
  int result = 0; // To store length of the
                  // longest common substring

  /* Following steps build LCSuff[m+1][n+1] in
        bottom up fashion. */
  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      // The first row and first column
      // entries have no logical meaning,
      // they are used only for simplicity
      // of program
      if (i == 0 || j == 0)
        LCSuff[i][j] = 0;

      else if (X[i - 1] == Y[j - 1])
      {
        LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
        result = max(result, LCSuff[i][j]);
      }
      else
        LCSuff[i][j] = 0;
    }
  }
  return result;
}
void sol()
{
  string str1, str2;
  cin >> str1 >> str2;
  ll ans = 0, i = 0, j = 0, count;
  ans = LCSubStr(str1, str2, str1.size(), str2.size());
  // cout << str1 << " " << str2 << " " << ans << endl;
  ans = str1.size() + str2.size() - 2 * ans;
  cout << ans << endl;
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