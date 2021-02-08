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
  ll n, m, sum = 0;
  cin >> n >> m;
  vector<ll> v1(n), vh, vl;
  rep(i, 0, n)
  {
    cin >> v1[i];
    sum += v1[i];
  }
  rep(i, 0, n)
  {
    ll t;
    cin >> t;
    if (t == 1)
    {
      vl.push_back(v1[i]);
    }
    else
    {
      vh.push_back(v1[i]);
    }
  }
  ll j = 0, k = 0, ans = 0;
  if (sum < m)
  {
    cout << -1 << endl;
    return;
  }
  rep(i, 0, n)
  {
    if (j < vl.size() && k < vh.size())
    {
      if (vl[j] >= vh[k])
      {
        ans++;
        m -= vl[j];
        j++;
      }
      else if (m - vl[j] <= 0)
      {
        ans++;
        break;
      }
      else if (j < vl.size() - 1 && vl[j] + vl[j + 1] <= vh[k])
      {
        ans += 2;
        k++;
        m -= vh[k];
      }
      else
      {
        ans++;
        m -= vl[j];
      }
    }
    if (m <= 0)
    {
      break;
    }
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