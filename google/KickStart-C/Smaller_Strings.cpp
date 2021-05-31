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
    return (temp % mod * temp % mod) % mod;
  else
    return (x % mod * (temp % mod * temp % mod) % mod) % mod;
}
ll LexicoLesserStrings(string s, ll k)
{
  ll count = 0;
  ll len;
  len = s.size();
  for (ll i = 0; i < len; i++)
  {
    count += ((s[i] - 'a') * power(k, len - i - 1) % mod) % mod;
    count %= mod;
  }

  return count;
}
bool pla(string str)
{
  string str2 = str;
  reverse(str2.begin(), str2.end());
  if (str == str2)
    return true;
  return false;
}
void sol()
{
  ll n, k;

  string str;
  cin >> n >> k >> str;
  char maxvalur = 96 + k;
  // cout << maxvalur << endl;
  if (n == 1)
  {
    cout << str[0] - 'a' << endl;
    return;
  }
  ll ans = 0;
  ll flag = 0;

  if (n % 2 == 0)
  {
    string str1 = str.substr(0, n / 2), str2 = str.substr(n / 2, n / 2);
    reverse(str2.begin(), str2.end());
    string min1 = str1;
    for (auto &i : min1)
    {
      if (i - 'a' > k - 1)
      {
        i = maxvalur;
      }
    }
    string str3 = min1;

    ans = LexicoLesserStrings(min1, k);
    reverse(min1.begin(), min1.end());
    str3 += min1;
    if (pla(min1) && min1 < str)
      ans++;
  }
  else
  {
    string str1 = str.substr(0, n / 2), str2 = str.substr(n / 2 + 1, n / 2);
    reverse(str2.begin(), str2.end());
    str1 += str[(n) / 2];
    str2 += str[(n) / 2];
    string min1 = str1;
    for (auto &i : min1)
    {
      if (i - 'a' > k - 1)
        i = maxvalur;
    }
    string str3 = min1;

    ans = LexicoLesserStrings(min1, k);
    min1.pop_back();
    reverse(min1.begin(), min1.end());

    str3 += min1;
    if (pla(str3) && str3 < str)
      ans++;
  }
  cout << ans << endl;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a = 1;
  cin >> a;
  int i = 1;
  while (a--)
  {
    cout << "Case #" << i << ':' << ' ';
    sol();
    i++;
  }
}