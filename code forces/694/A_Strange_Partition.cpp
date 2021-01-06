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
  cin >> n >> m;
  vector<ll> v1(n);
  ll minval = 0, maxval = 0, sum = 0;
  rep(i, 0, n)
  {
    cin >> v1[i];
    sum += v1[i];
    if (v1[i] % m == 0)
    {
      maxval += v1[i] / m;
    }
    else
    {
      maxval += (v1[i] / m) + 1;
    }
    }

  if (sum % m == 0)
  {
    minval += sum / m;
  }
  else
  {
    minval += (sum / m) + 1;
  }
  cout << minval << " " << maxval << endl;
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