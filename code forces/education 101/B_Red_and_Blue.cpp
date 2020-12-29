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
  ll n, m;
  cin >> n;
  vector<ll> v1(n);
  rep(i, 0, n)
  {
    cin >> v1[i];
  }
  vector<ll> v3;
  ll ans1 = 0;
  rep(i, 0, n)
  {
    ans1 += v1[i];
    if (ans1 > 0)
    {
      v3.push_back(ans1);
      ans1 = 0;
    }
  }
  if (ans1 != 0)
  {
    // cout << "hi" << endl;
    // cout << ans1 << endl;
    v3.push_back(ans1);
    ans1 = 0;
  }
  cin >> m;
  vector<ll> v2(m);
  rep(i, 0, m)
  {
    cin >> v2[i];
  }
  vector<ll> v4;
  rep(i, 0, m)
  {
    ans1 += v2[i];
    if (ans1 > 0)
    {
      v4.push_back(ans1);
      ans1 = 0;
    }
  }
  if (ans1 != 0)
  {
    v4.push_back(ans1);
    ans1 = 0;
  }
  ll j = 0, k = 0, ans = 0, finalans = 0;
  rep(i, 0, v3.size() + v4.size())
  {
    if (j == v3.size())
    {
      ans += v4[k];
      k++;
    }
    else if (k == v4.size())
    {
      ans += v3[j];
      j++;
    }
    else if (v3[j] > v4[k])
    {
      ans += v3[j];
      j++;
    }
    else
    {
      ans += v4[k];
      k++;
    }
    finalans = max(ans, finalans);
  }
  cout << finalans << endl;
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