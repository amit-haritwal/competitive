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
void amit_is_best()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define res(i, a, b) for (ll i = a; i >= b; i--)
#define all(n) n.begin(), n.end()
#define mod 1000000007
template <typename T>
void pop_front(std::vector<T> &vec)
{
  assert(!vec.empty());
  vec.erase(vec.begin());
}
typedef long long ll;
const long long INF = 1e18 + 42;
bool comp(pair<ll, ll> v1, pair<ll, ll> v2)
{
  return v1.first < v2.first;
}
bool primes[1000005];
int lp[1000006];
void sec()
{
  const int N = 1000005;

  vector<int> pr;

  for (int i = 2; i <= N; ++i)
  {
    if (lp[i] == 0)
    {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
      lp[i * pr[j]] = pr[j];
  }
}
void sieveWithCount(ll n)
{
  rep(i, 0, n)
  {
    primes[i] = 1;
  }
  for (ll i = 2; i * i < n; i++)
  {
    if (primes[i] != 0)
    {
      for (ll j = i * i; j < n; j = j + i)
      {
        primes[j] = 0;
      }
    }
  }
  primes[0] = 0;
  primes[1] = 0;
  // ll j = 0;
  // rep(i, 2, v1.size())
  // {
  //   if (v1[i])
  //   {
  //     primes.push_back(i);
  //     j++;
  //   }
  // }
}
void sol()
{
  ll n;
  cin >> n;
  if (n < 5)
  {
    cout << 0 << endl;
    return;
  }
  ll ans = 0;
  rep(i, 3, n - 1)
  {
    if (lp[i] == i && lp[i + 2] == i + 2)
    {
      ans++;
    }
  }
  cout << ans << endl;
}
int main()
{
  amit_is_best();
  // sieveWithCount(1000005);
  sec();
  int a = 1;
  cin >> a;
  while (a--)
  {
    sol();
  }
}