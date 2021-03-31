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
pair<ll, ll> predict(vector<ll> &v1)
{
  ll n = v1.size();
  ll first = v1[0], last = v1[1];
  vector<ll> v2;
  rep(i, 0, n - 2)
  {
    cout << first << " " << last << " " << v1[i + 2] << endl;
    ll t;
    cin >> t;
    if (t == first)
    {
      v2.push_back(first);
      first = v1[i + 2];

      continue;
    }
    if (t == last)
    {
      v2.push_back(last);
      last = v1[i + 2];
      continue;
    }
    else
    {
      v2.push_back(v1[i + 2]);
    }
  }
  v1 = v2;
  return {first, last};
}
void sol()
{
  ll n, q;
  cin >> n >> q;
  vector<ll> v1(n, 0);
  rep(i, 0, n)
  {
    v1[i] = i + 1;
  }
  vector<ll> v2, v3;
  while (v1.size() > 0)
  {
    if (v1.size() == 1)
    {
      v2.push_back(v1[0]);
      break;
    }

    else
    {
      pair<ll, ll> t = predict(v1);
      ll last = t.second;
      ll first = t.first;
      v2.push_back(first);
      v3.push_back(last);
    }
  }
  for (auto i : v2)
  {
    cout << i << " ";
  }
  reverse(v3.begin(), v3.end());
  for (auto i : v3)
  {
    cout << i << " ";
  }
  cout << endl;
  ll t;
  cin >> t;
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