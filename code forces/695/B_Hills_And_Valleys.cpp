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
void sol()
{
  ll n;
  cin >> n;
  vector<ll> v1(n);
  rep(i, 0, n)
  {
    cin >> v1[i];
  }
  ll ans = 0, ans2 = 0, prev = 0, flag = 0;
  rep(i, 1, n - 1)
  {
    if (v1[i - 1] > v1[i] && v1[i + 1] > v1[i])
    {
      ans++;
      prev++;
    }
    else if (v1[i - 1] < v1[i] && v1[i + 1] < v1[i])
    {
      ans++;
      prev++;
    }
    else
    {
      prev = 0;
    }
    flag = max(flag, prev);

    if (prev == 3)
    {

      prev = 2;
    }
  }
  ans = max(ll(0), ans - flag);
  cout << ans << endl;
}
int main()
{
  amit_is_best();
  int a = 1;
  cin >> a;
  while (a--)
  {
    sol();
  }
}