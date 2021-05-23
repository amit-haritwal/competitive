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
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define res(i, a, b) for (ll i = a; i >= b; i--)
#define all(n) n.begin(), n.end()
#define mod 1000000007
typedef long long ll;
const long long INF = 1e18 + 42;
// vector<ll> primes(10005, 1);
template <typename T>
void pop_front(std::vector<T> &vec)
{
  assert(!vec.empty());
  vec.erase(vec.begin());
}
bool compPairF(pair<ll, ll> v1, pair<ll, ll> v2)
{
  return v1.first < v2.first;
}
bool compPairS(pair<ll, ll> v1, pair<ll, ll> v2)
{
  return v1.second < v2.second;
}
//void sieveWithCount(ll n)
//{
//  vector<bool> v1(n, 1);
//  for (ll i = 2; i * i < n; i++)
//  {
//    if (primes[i] != 0)
//    {
//      for (ll j = i * i; j < n; j = j + i)
//      {
//        primes[j] = 0;
//      }
//    }
//  }
//}
ll gcd(ll a, ll b)
{
  if (b == 0)
  {
    return a;
  }
  else
  {
    return gcd(b, a % b);
  }
}
ll power(ll x, ll y)
{
  ll temp;
  if (y == 0)
    return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
ll ans = 0;
void unique_combination(ll l, ll sum, ll K,
                        vector<ll> &local,
                        vector<ll> &A)
{
  if (sum == K)
  {
    ans++;
    cout << "{";
    for (int i = 0; i < local.size(); i++)
    {
      if (i != 0)
        cout << " ";
      cout << local[i];
      if (i != local.size() - 1)
        cout << ", ";
    }
    cout << "}" << endl;
    return;
  }

  for (ll i = l; i < A.size(); i++)
  {
    if (sum + A[i] > K)
      continue;
    if (i > l && A[i] == A[i - 1])
      continue;

    local.push_back(A[i]);
    unique_combination(i + 1, sum + A[i], K, local, A);
    local.pop_back();
  }
}

void Combination(vector<ll> A, ll K)
{
  sort(A.begin(), A.end());

  vector<ll> local;

  unique_combination(0, 0, K, local, A);
}
void sol()
{
  ll n, m, b;
  ans = 0;
  cin >> n >> m >> b;
  vector<ll> v1(n * m);
  rep(i, 0, n * m)
  {
    cin >> v1[i];
  }
  Combination(v1, b);
  cout << ans << endl;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a = 1;
  cin >> a;
  while (a--)
  {
    sol();
  }
}