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
  ll n,m1,m2;
  cin>>n>>m1>>m2;
  map<ll,vector<ll>> mp;

  rep(i,0,m1){
    ll l,r;
    cin>>l>>r;
    if(mp[l].size()){
      mp[l].push_back(r);
      vector<ll> temp = mp[l];

      for(auto j:mp[l]){
        mp[j]=temp;
      }
      
    }
    else{
      mp[l].push_back(r);
      mp[l].push_back(l);
    }
    if (mp[r].size())
    {
      mp[r].push_back(l);
      vector<ll> temp = mp[r];

      for (auto j : mp[r])
      {

        mp[j] = temp;
      }
    }
    else{
      mp[r].push_back(r);
      mp[r].push_back(l);
    }
    
  }
  map<ll, vector<ll>> mp1;

  rep(i, 0, m2)
  {
    ll l, r;
    cin >> l >> r;
    if (mp1[l].size())
    {
      mp1[l].push_back(r);
      vector<ll> temp = mp1[l];

      for (auto j : mp1[l])
      {
        mp1[j] = temp;
      }
    }
    else
    {
      mp1[l].push_back(r);
      mp1[l].push_back(l);
    }
    if (mp1[r].size())
    {
      mp1[r].push_back(l);
      vector<ll> temp = mp1[r];

      for (auto j : mp1[r])
      {

        mp1[j] = temp;
      }
    }
    else
    {
      mp1[r].push_back(r);
      mp1[r].push_back(l);
    }
  }
  vector<vector<ll>>v1;
  for(auto i : mp1){
    ll flag=0;
    for(auto j:v1){
      if(i.second==j){
        flag = 1;
        break;
      }
    }
    if(!flag){
      v1.push_back(i.second);
    }
  }

  rep(i,0,v1.size()){
    rep(j,i,v1.size()){
      
    }
  }
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