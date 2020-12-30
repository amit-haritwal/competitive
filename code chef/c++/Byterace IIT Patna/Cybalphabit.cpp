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
  ll n, k;
  cin >> n >> k;
  if (n > k)
  {
    cout << -1 << endl;
    return;
  }
  vector<ll> v1(26, 0);
  ll count = 0;
  rep(i, 0, 26)
  {
    ll s = pow(2, i + 1);
    if (k % s != 0)
    {
      v1[i] = 1;
      k = k - pow(2, i);
      count++;
    }
  }
  string str = "abcdefghijklmnopqrstuvwxz";
  while (true)
  {
    if (count > n)
    {
      cout << -1 << endl;
      return;
    }
    if (count == n)
    {
      rep(i, 0, 26)
      {
        rep(j, 0, v1[i])
        {
          cout << str[i];
        }
      }
      cout << endl;
      return;
    }

    rep(i, 0, 26)
    {
      if(i==25){
        cout << -1 << endl;
        return;
      }
      if (v1[25 - i] > 0)
      {
        v1[25 - i]--;
        v1[25 - i - 1] += 2;
        count++;
        break;
      }
    }
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