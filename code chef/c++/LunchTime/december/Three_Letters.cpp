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
  string str;
  cin >> str;
  map<char, ll> mp;
  vector<char> v1;
  rep(i, 0, str.size())
  {
    if (!mp[str[i]])
    {
      v1.push_back(str[i]);
    }
    mp[str[i]]++;
  }
  ll ans = 0;
  while (true)
  {
    ll flag = 1;
    rep(i, 0, v1.size())
    {
      if (mp[v1[i]] > 1 && 3 * ans + 3 <= str.size())
      {
        ans++;
        mp[v1[i]] -= 2;
        flag = 0;
      }
    }
    if (flag)
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