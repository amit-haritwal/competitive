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
  ll ans = 0, asa = 0;
  map<char, vector<ll>> mp;
  map<ll, vector<ll>> pld;
  rep(i, 0, str.size())
  {
    if (mp[str[i]].size())
    {
      rep(k, 0, mp[str[i]].size())
      {
        bool flag = true;
        rep(j, mp[str[i]][k], i)
        {
          if (str[j] != str[i - j])
          {
            flag = false;
            break;
          }
        }
        if (flag)
        {
          pld[mp[str[i]][k]].push_back(i);
          ans++;
        }
      }
    }
    mp[str[i]].push_back(i);
  }
  ans = 0;
  for (auto i : pld)
  {
    ans = max(ans, (ll)i.second.size() + 1);
  }
  if (ans % 2 == 0)
  {
    cout << ans / 2 << endl;
  }
  else
  {
    cout << ans / 2 + 1 << endl;
  }
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