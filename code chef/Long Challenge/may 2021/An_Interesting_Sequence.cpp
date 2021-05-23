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
int primes[40010];
int coun[40010];
void sieveWithCount()
{
  int n = 40001;
  rep(i, 0, n + 3)
  {
    primes[i] = i;
    coun[i] = 0;
  }
  rep(i, 2, n + 1)
  {
    if (primes[i] == i)
    {
      primes[i] = i - 1;
      rep(j, 2 * i, n + 1)
      {
        primes[j] = (primes[j] / i) * (i - 1);
        j += i - 1;
      }
    }
  }
  rep(i, 0, 100)
  {
    cout << primes[i] << " ";
  }
  cout << endl;
  rep(i, 1, n + 1)
  {
    coun[i] += i - 1;
    rep(j, 2 * i, n + 1)
    {
      coun[j] += i * ((1 + primes[j / i]) / 2);
      j += i - 1;
    }
  }
}
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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a = 1;
  sieveWithCount();
  cin >> a;
  while (a--)
  {
    ll n;
    cin >> n;
    cout << coun[4 * n + 1] << "\n";
  }
}