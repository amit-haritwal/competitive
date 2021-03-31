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
bool compPairF(ll v1, ll v2)
{
  return v1 > v2;
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
  ll n, w;
  cin >> n >> w;
  vector<ll> v1(n);
  rep(i, 0, n)
  {
    cin >> v1[i];
  }
  sort(v1.begin(), v1.end(), compPairF);
  vector<ll> v2, v3;
  ll j = 0;
  while (j < n)
  {
    ll flag = 0;
    rep(i, 0, v2.size())
    {
      if (v2[i] >= v1[j])
      {
        v2[i] -= v1[j];
        flag = 1;
        break;
      }
    }
    if (!flag)
    {
      v2.push_back(w - v1[j]);
    }
    j++;
  }
  cout << v2.size() << endl;
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, box_width, w;
        cin >> n >> box_width;

        vector<int> counts(20);
        for (int i = 0; i < n; i++) {
            cin >> w;
            counts[log2(w)]++;
        }

        int height = 1, space_left = box_width;

        for (int iter = 0; iter < n; iter++) {
            int largest = -1;

            for (int size = 19; size >= 0; size--) {
                if (counts[size] and (1 << size) <= space_left) {
                    largest = size;
                    break;
                }
            }

            if (largest == -1) {
                space_left = box_width;
                height++;
                for (int size = 19; size >= 0; size--) {
                    if (counts[size] and (1 << size) <= space_left) {
                        largest = size;
                        break;
                    }
                }
            }

            counts[largest] -= 1;
            space_left -= 1 << largest;
        }

        cout << height << endl;
    }

}