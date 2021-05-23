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
  if (v1.first != v2.first)
    return v1.first > v2.first;
  else
    return v1.second < v2.second;
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
void swap(ll *a, ll *b)
{
  ll t = *a;
  *a = *b;
  *b = t;
}
ll partition(vector<ll> arr, int low, int high)
{
  int pivot = arr[high]; // pivot
  int i = (low - 1);     // Index of smaller element and indicates the right position of pivot found so far

  for (int j = low; j <= high - 1; j++)
  {
    // If current element is smaller than the pivot
    if (arr[j] < pivot)
    {
      i++; // increment index of smaller element
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}
void quickSort(vector<ll> arr, int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

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
const int MAXN = 200000;

vector<int> v[1 + MAXN];
int u[1 + MAXN], s[1 + MAXN];
long long answer[1 + MAXN], sum[1 + MAXN];
void sol()
{
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; test++)
  {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
      cin >> u[i];
    }
    for (int i = 1; i <= n; i++)
    {
      cin >> s[i];
    }
    for (int i = 1; i <= n; i++)
    {
      v[u[i]].push_back(s[i]);
      answer[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
      sort(v[i].begin(), v[i].end());
      int m = v[i].size();
      for (int j = 1; j <= m; j++)
      {
        sum[j] = sum[j - 1] + v[i][j - 1];
      }
      for (int k = 1; k <= m; k++)
      {
        answer[k] += sum[m] - sum[m % k];
      }
    }
    for (int i = 1; i <= n; i++)
    {
      v[i].clear();
      cout << answer[i] << " ";
    }
    cout << "\n";
  }
  return;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a = 1;
  // cin >> a;
  while (a--)
  {
    sol();
  }
}