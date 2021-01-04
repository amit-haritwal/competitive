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
  ll n;
  cin >> n;
  vector<ll> v1(n), even, odd;
  rep(i, 0, n)
  {
    cin >> v1[i];
    if (v1[i] % 2 == 0)
    {
      even.push_back(v1[i]);
    }
    else
    {
      odd.push_back(v1[i]);
    }
  }
  if (even.size())
    sort(even.begin(), even.end(), comp);
  if (odd.size())
    sort(odd.begin(), odd.end(), comp);
  ll i = 0, j = 0, turn = 0;
  ll sum1 = 0, sum2 = 0;
  // cout << "hi" << endl;
  rep(a, 0, n)
  {
    turn = !turn;
    if (turn)
    {
      if (i == even.size())
      {
        j++;
        continue;
      }
      // cout << "hi1" << endl;
      if (j >= odd.size() || even[i] >= odd[j])
      {
        sum1 += even[i];
        i++;
      }
      else
      {
        j++;
      }
    }
    else
    {
      if (j == odd.size())
      {
        i++;
        continue;
      }
      if (i >= even.size() || even[i] <= odd[j])
      {
        sum2 += odd[j];
        j++;
      }
      else
      {
        i++;
      }
    }
  }
  // cout << sum1 << " " << sum2 << endl;
  if (sum1 == sum2)
  {

    cout << "Tie" << endl;
    return;
  }
  if (sum1 > sum2)
  {
    cout << "Alice" << endl;
  }
  else
  {
    cout << "Bob" << endl;
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