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

bool solve(ll index, ll n, vector<ll> v1, ll heg, ll k, vector<vector<ll>> &dp)
{
  if (index == n)
  {
    return heg == 0;
  }
  if (dp[heg][index] != -1)
  {
    return dp[heg][index];
  }
  rep(i, 0, k - 1)
  {
    if (v1[i] <= heg + i && heg + i - k < v1[i] && dp[index + 1][heg + i] == -1)
    {
      dp[index + 1][heg + i] = solve(index + 1, n, v1, heg + i, k, dp);
      if (dp[index + 1][heg + i])
      {
        return true;
      }
    }
  }

  return false;
}
void sol()
{
  ll n, k;
  cin >> n >> k;
  vector<vector<ll>> dp(k * n, vector<ll>(n, -1));
  vector<ll> v1(n);
  rep(i, 0, n)
  {
    cin >> v1[i];
  }
  if ((k - 1) * (n - 1) < v1[n - 1])
  {
    cout << "NO" << endl;
  }
  ll ans = 1;
  rep(i, 0, n)
  {
  }
  if (solve(1, n, v1, 0, k, dp))
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
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