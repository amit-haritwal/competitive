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
ll anssize(ll a)
{
  ll t = 0;
  while (a > 0)
  {
    a = a / 10;
    t++;
  }
  return t;
}
void sol()
{
  string str;
  ll n;
  cin >> str >> n;
  ll ans = 0;
  stack<ll> st;
  stack<ll> v1;
  rep(i, 0, str.size())
  {
    st.push(n);
    v1.push(int(str[i]) - 48);
  }
  while (!st.empty())
  {
    ans++;
    ll no = v1.top(), toadd = st.top();
    st.pop();
    v1.pop();
    vector<ll> v2;
    ll o = no + toadd;
    while (o > 0)
    {
      v2.push_back(o % 10);
      o = o / 10;
    }
    for (auto i : v2)
    {
      cout << i << " ";
    }
    cout << endl;
    cout << v2.size() << " " << no << " " << toadd << " " << anssize(no + toadd) - 1 << endl;
    rep(i, 0, anssize(no + toadd) - 1)
    {
      st.push(toadd - 1);
      v1.push(v2[i]);
    }
  }
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