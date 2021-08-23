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
bool isAp(ll a,ll b,ll c){
  // cout<<a << " " <<b<<" " <<c<<endl;
  if(a-b==b-c)return true;
  return false;
}
void sol()
{ 
  vector<ll> v1(8);
  rep(i,0,8){
    cin>>v1[i];
  }
  map<double,ll> mp;
  mp[(v1[0]+v1[7]+0.0)/2]++;
  mp[(v1[1]+v1[6]+0.0)/2]++;
  mp[(v1[2]+v1[5]+0.0)/2]++;
  mp[(v1[3]+v1[4]+0.0)/2]++;
  ll ans=-INF;
  ll val=0;
  for(auto i: mp){
    if(i.second>val){ans=i.first;val=i.second;}
    // cout<<i.first<<" "<<i.second<<endl;
  }
  ll finalans=0;
    finalans+=isAp(v1[0],v1[1],v1[2]);
    finalans+=isAp(v1[3],ans,v1[4]);
    finalans+=isAp(v1[5],v1[6],v1[7]);
    finalans+=isAp(v1[0],v1[3],v1[5]);
    finalans+=isAp(v1[1],ans,v1[6]);
    finalans+=isAp(v1[2],v1[4],v1[7]);
    finalans+=isAp(v1[0],ans,v1[7]);
    finalans+=isAp(v1[2],ans,v1[5]);
  cout<<finalans<< endl;
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