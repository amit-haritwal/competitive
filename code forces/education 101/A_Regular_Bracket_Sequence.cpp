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
  ll count = 0, count1 = 0;

  cin >> str;

  if (str[0] == ')' or str[str.size() - 1] == '(')
  {
    cout << "NO" << endl;
    return;
  }
  rep(i, 0, str.size())
  {
    if (str[i] == ')')
    {
      count--;
    }
    else if (str[i] == '(')
    {
      count++;
    }
    else
    {
      count++;
    }
  }
  if (count % 2 == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
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