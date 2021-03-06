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
bool comp(ll v1, ll v2)
{
  return v1 > v2;
}
void sol()
{
  ll n, m;
  cin >> n >> m;
  vector<ll> v1(n), v2(m);
  rep(i, 0, n)
  {
    cin >> v1[i];
  }
  rep(i, 0, m)
  {
    cin >> v2[i];
  }
  sort(v1.begin(), v1.end(), comp);
  ll ans = 0, index = 0;

  rep(i, 0, n)
  {
    if (index + 1 <= v1[i] && index < m)
    {
      ans += v2[index];
      index++;
    }
    else
    {
      ans += v2[v1[i] - 1];
    }
    // cout << ans << " ";
  }
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