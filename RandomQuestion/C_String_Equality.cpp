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
  ll n,k;
  string a,b;
  cin>>n>>k>>a>>b;
  sort(all(a));
  sort(all(b));
  string str1="",str2="";
  ll i=0,j=0;
  while(i<a.size() || j<b.size()){
    if(i<a.size() && j<b.size()){
      if(a[i]==b[j]){
        i++;j++;
      }
      else if(a[i]<b[j]){
        str1+=a[i];
        i++;
      }
      else{
        str2+=b[j];
        j++;
      }
    }
    else if(i<a.size()){
      str1+=a[i];
      i++;
    }else{
      str2+=b[j];
      j++;
    }
  }
  // cout<<str1<<" "<<str2<<endl;
  if(str1.size()%k==0){
    rep(i,0,str1.size()/k){
      if(str1[i]>str2[i])
      {
        cout<<"No"<<endl;
        return;
      }
      rep(j,i*k,i*k+k){
        if(str1[i*k]!=str1[j]){
          cout<<"No"<<endl;
          return;
        }
      }
      rep(j,i*k,i*k+k){
        if(str2[i*k]!=str2[j]){
          // cout<<i<<" "<<j<<" "<<str2<<endl;
          cout<<"No"<<endl;
          return;
        }
      }
    }
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
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