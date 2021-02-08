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
  string str1, str2, least = "", least2 = "";
  cin >> str1 >> str2;

  rep(i, 0, str1.size())
  {
    if (least.size() == 0)
    {
      least += str1[0];
      continue;
    }
    if (least[0] == str1[i])
    {
      ll flag = 1;
      ll k = 0;
      rep(j, 0, str1.size())
      {
        if (least[k] == str1[j])
        {
          k++;
          if (k == least.size())
          {
            k = 0;
          }
        }
        else
        {
          flag = 0;
          break;
        }
      }
      if (flag && str1.size() % least.size() == 0)
      {
        break;
      }
    }
    least += str1[i];
  }
  ll flag = 1;
  ll k = 0;
  rep(j, 0, str2.size())
  {
    if (least[k] == str2[j])
    {
      k++;
      if (k == least.size())
      {
        k = 0;
      }
    }
    else
    {
      flag = 0;
      break;
    }
  }
  // cout << least << endl;
  if (flag == 0 || str2.size() % least.size() != 0)
  {
    // cout << flag << " " << str2.size() % least.size() << endl;
    cout << -1 << endl;
    return;
  }
  ll num1 = (str2.size() / least.size());
  ll num2 = (str1.size() / least.size());
  ll max = min(num1, num2);
  while (true)
  {
    if (max % num1 == 0 && max % num2 == 0)
    {
      break;
    }
    max++;
  }
  string ans = least;
  rep(i, 0, max - 1)
  {
    ans += least;
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