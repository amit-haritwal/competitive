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
  string str;
  cin >> str;
  ll type = 0, j = 0;
  rep(i, 0, str.size())
  {
    if (int(str[i]) < 58)
    {
      j++;
    }
    else if (j > 0)
    {
      type = 1;
      break;
    }
  }
  // cout << type << endl;
  if (type != 0)
  {
    int pos, a = 0, b = 0;
    for (int i = 0; i < str.size(); ++i)
    {
      if (str[i] == 'C')
      {
        pos = i;
        break;
      }
    }
    for (int i = 1; i < pos; ++i)
    {
      a = a * 10 + (str[i] - '0');
    }
    for (int i = pos + 1; i < str.size(); ++i)
    {
      b = b * 10 + (str[i] - '0');
    }
    stack<char> s;
    while (b > 0)
    {
      if (b % 26 == 0)
      {
        s.push('Z');
        b -= 26;
      }
      else
        s.push('A' - 1 + b % 26);
      b /= 26;
    }
    while (!s.empty())
    {
      printf("%c", s.top());
      s.pop();
    }
    printf("%d\n", a);
  }
  else
  {
    int pos;
    for (int i = 0; i < str.size(); ++i)
    {
      if (isdigit(str[i]))
      {
        pos = i;
        break;
      }
    }
    int num = 0;
    for (int i = 0; i < pos - 1; ++i)
    {
      num = num * 26 + (str[i] - 'A' + 1) * 26;
    }
    num += str[pos - 1] - 'A';
    printf("R");
    for (int i = pos; i < str.size(); ++i)
      printf("%c", str[i]);
    printf("C%d\n", num + 1);
  }
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