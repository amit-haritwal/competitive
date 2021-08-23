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
  ll n;
  cin>>n;
  vector<ll> v1(n),v2(n);
  rep(i,0,n)cin>>v1[i];
  rep(i,0,n)cin>>v2[i];
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  ll sum1=0,sum2=0;
  for(auto i:v1){
    sum1+=i;
  }
  for(auto i:v2){
    sum2+=i;
  }
  ll toremove=n/4;
  ll i=0;
  while(toremove>i){
    sum1=sum1-v1[i];
    sum2=sum2-v2[i];
    i++;
  }
  ll prevtor=toremove;
  ll ans=0,k=n,tt=toremove;
  while(sum1<sum2){
      sum1+=100;
      k++;
      ans++;
      if(toremove!=0){
        toremove--;
          sum2+=v2[toremove];
          
        }
      ll tor=k/4;
      if(tor!=prevtor){
        if(tt==n){
          sum1-=100;
        }
        else{
          sum1-=v1[tt];
          tt++;
        }
      }
          prevtor=tor;
    }
    // cout<<sum1<< " "<<sum2<<endl;
  cout<<ans<<endl;
  
  
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