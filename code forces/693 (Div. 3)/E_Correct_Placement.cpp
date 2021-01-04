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
  vector<pair<ll, ll>> v1(n), v2(n);
  rep(i, 0, n)
  {
    ll t, q;
    cin >> t >> q;
    v1[i] = {t, q};
    v2[i] = {q, t};
  }
  // sort(v1.begin(), v1.end(), comp);
  // sort(v2.begin(), v2.end(), comp);

  rep(i, 0, n)
  {
    ll x = v1[i].first, y = v1[i].second, flag = 0;
    rep(j, 0, n)
    {
      if ((v1[j].first < x && v1[j].second < y) || (v1[j].second < x && v1[j].first < y))
      {
        flag = 1;
        cout << j + 1 << " ";
        break;
      }
    }
    if (!flag)
    {
      cout << -1 << " ";
    }
  }
  cout << endl;
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