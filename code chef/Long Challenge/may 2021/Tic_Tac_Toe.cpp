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
#define mOd 1000000007
typedef long long ll;
const long long INF = 1e18 + 42;
// vector<ll> primes(10005, 1);
template <typename T>
void pOp_frOnt(std::vector<T> &vec)
{
  assert(!vec.empty());
  vec.erase(vec.begin());
}
bool cOmpPairF(pair<ll, ll> v1, pair<ll, ll> v2)
{
  return v1.first < v2.first;
}
bool cOmpPairS(pair<ll, ll> v1, pair<ll, ll> v2)
{
  return v1.second < v2.second;
}
//vOid sieveWithCOunt(ll n)
//{
//  vector<bOOl> v1(n, 1);
//  fOr (ll i = 2; i * i < n; i++)
//  {
//    if (primes[i] != 0)
//    {
//      fOr (ll j = i * i; j < n; j = j + i)
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
ll pOwer(ll X, ll y)
{
  ll temp;
  if (y == 0)
    return 1;
  temp = pOwer(X, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return X * temp * temp;
}
ll Xwin(vector<string> game)
{
  ll ans = 0;
  if (game[0][0] == 'X' && game[0][1] == 'X' && game[0][2] == 'X')
  {
    ans++;
  }
  if (game[1][0] == 'X' && game[1][1] == 'X' && game[1][2] == 'X')
  {
    ans++;
  }
  if (game[2][0] == 'X' && game[2][1] == 'X' && game[2][2] == 'X')
  {
    ans++;
  }
  if (game[0][0] == 'X' && game[1][0] == 'X' && game[2][0] == 'X')
  {
    ans++;
  }
  if (game[0][1] == 'X' && game[1][1] == 'X' && game[2][1] == 'X')
  {
    ans++;
  }
  if (game[0][2] == 'X' && game[1][2] == 'X' && game[2][2] == 'X')
  {
    ans++;
  }
  if (game[0][0] == 'X' && game[1][1] == 'X' && game[2][2] == 'X')
  {
    ans++;
  }
  if (game[2][0] == 'X' && game[1][1] == 'X' && game[0][2] == 'X')
  {
    ans++;
  }
  return ans;
}
ll Owin(vector<string> game)
{
  ll ans = 0;
  if (game[0][0] == 'O' && game[0][1] == 'O' && game[0][2] == 'O')
  {
    ans++;
  }
  if (game[1][0] == 'O' && game[1][1] == 'O' && game[1][2] == 'O')
  {
    ans++;
  }
  if (game[2][0] == 'O' && game[2][1] == 'O' && game[2][2] == 'O')
  {
    ans++;
  }
  if (game[0][0] == 'O' && game[1][0] == 'O' && game[2][0] == 'O')
  {
    ans++;
  }
  if (game[0][1] == 'O' && game[1][1] == 'O' && game[2][1] == 'O')
  {
    ans++;
  }
  if (game[0][2] == 'O' && game[1][2] == 'O' && game[2][2] == 'O')
  {
    ans++;
  }
  if (game[0][0] == 'O' && game[1][1] == 'O' && game[2][2] == 'O')
  {
    ans++;
  }
  if (game[2][0] == 'O' && game[1][1] == 'O' && game[0][2] == 'O')
  {
    ans++;
  }
  return ans;
}
bool zerO1(vector<string> game)
{
  ll O = 0, X = 0, c_ = 0;
  rep(i, 0, 3)
  {
    rep(j, 0, 3)
    {
      if (game[i][j] == 'X')
      {
        X++;
      }
      else if (game[i][j] == 'O')
      {
        O++;
      }
      else
      {
        c_++;
      }
    }
  }
  if (X == 5 && O == 4)
    return true;
  return false;
}
bool zerO2(vector<string> game)
{
  ll O = 0, X = 0, c_ = 0;
  rep(i, 0, 3)
  {
    rep(j, 0, 3)
    {
      if (game[i][j] == 'X')
      {
        X++;
      }
      else if (game[i][j] == 'O')
      {
        O++;
      }
      else
      {
        c_++;
      }
    }
  }
  if (c_ > 0)
    return true;
  return false;
}
void sOl()
{
  ll flag = 0;
  vector<string> game(3);
  cin >> game[0] >> game[1] >> game[2];
  ll x = 0, o = 0, c_ = 0;
  rep(i, 0, 3)
  {
    rep(j, 0, 3)
    {

      if (game[i][j] == 'X')
      {
        x++;
      }
      else if (game[i][j] == 'O')
      {
        o++;
      }
      else
      {
        c_++;
      }
    }
  }
  if (o > x || abs(x - o) > 1)
  {
    cout << 3 << endl;
    return;
  }
  if ((x > o && Xwin(game) == 1 && Owin(game) == 0) || (x == o && Xwin(game) == 0 && Owin(game) == 1) || (c_ == 0 && Xwin(game) == 0 && Owin(game) == 0) || (c_ == 0 && Xwin(game) == 2))
  {
    cout << 1 << endl;
    return;
  }
  else if (!Xwin(game) && !Owin(game) && zerO2(game))
  {
    cout << 2 << endl;
    return;
  }
  else
  {
    cout << 3 << endl;
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
    sOl();
  }
}
