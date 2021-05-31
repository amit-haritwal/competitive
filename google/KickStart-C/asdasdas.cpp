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
string alpha = "abcdefghijklmnopqrstuvwxyz";
bool pla(string str)
{
  string str2 = str;
  reverse(str2.begin(), str2.end());
  if (str == str2)
    return true;
  return false;
}
ll ans = 0;
void solve(string str, int index, string current, ll k)
{
  if (index == str.size())
  {

    if (pla(current) && current < str)
      ans++;
    return;
  }
  for (auto i : alpha)
  {
    if (i - 'a' <= k - 1)
    {
      solve(str, index + 1, current + i, k);
    }
  }
}
void sol()
{
  ll n, k;
  ans = 0;
  string str;
  cin >> n >> k >> str;
  solve(str, 0, "", k);
  cout << ans << endl;
  // cout << 10 << endl;
  // rep(i, 0, 10)
  // {
  //   cout << 5 << " " << 5 << endl;
  //   rep(i, 0, 5)
  //   {
  //     cout << alpha[rand() % 5];
  //   }
  //   cout << endl;
  // }
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