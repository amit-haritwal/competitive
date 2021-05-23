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
void sol()
{
  vector<long long> in(3);
  for (int i = 0; i < 3; ++i)
  {
    scanf("%lld", &in[i]);
  }
  const long long M = 360 * 12 * 10LL * 1000 * 1000 * 1000;
  do
  {
    long long diff = in[1] - in[0];
    if (diff < 0)
    {
      diff += M;
    }
    // 11 * x == diff
    for (int rep = 0; rep < 12; ++rep)
    {
      // 11 * x == rep * M + diff
      long long tmp = rep * M + diff;
      if (tmp % 11 == 0)
      {
        long long x = tmp / 11;
        long long shift = in[0] - x;
        if (shift < 0)
        {
          shift += M;
        }
        bool ok = true;
        for (int i = 0; i < 3; ++i)
        {
          if ((vector<int>{1, 12, 720}[i] * x + shift) % M != in[i])
          {
            ok = false;
          }
        }
        if (ok)
        {
          vector<long long> answer;
          answer.push_back(x % 1'000'000'000);
          x /= 1'000'000'000;
          answer.push_back(x % 60);
          x /= 60;
          answer.push_back(x % 60);
          x /= 60;
          answer.push_back(x);
          reverse(answer.begin(), answer.end());
          if (answer[0] < 12)
          {
            for (long long x : answer)
            {
              printf(" %lld", x);
            }
            puts("");
            return;
          }
        }
      }
    }
  } while (next_permutation(in.begin(), in.end()));
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a = 1;
  cin >> a;
  int i = 1;
  while (a--)
  {
    cout << "Case #" << i << ':' << ' ';
    sol();
    i++;
  }
}