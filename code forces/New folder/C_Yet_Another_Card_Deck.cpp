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
bool comp(pair<ll, ll> v1, pair<ll, ll> v2)
{
  return v2.first > v1.first;
}
class node
{
public:
  node *next;
  ll data;
  node(ll info)
  {
    data = info;
    next = NULL;
  }
};
ll search(node *head, ll x)
{
  node *current = head; // Initialize current
  ll ans = 0;
  while (current != NULL)
  {
    ans++;
    if (current->data == x)
      return ans;
    current = current->next;
  }
  return ans;
}
void deleteNode(node **head_ref, ll key)
{

  node *temp = *head_ref;
  node *prev = NULL;

  if (temp != NULL && temp->data == key)
  {
    *head_ref = temp->next;
    delete temp;
    return;
  }
  else
  {
    while (temp != NULL && temp->data != key)
    {
      prev = temp;
      temp = temp->next;
    }

    if (temp == NULL)
      return;

    prev->next = temp->next;

    delete temp;
  }
}
void printList(node *node)
{
  while (node != NULL)
  {
    cout << " " << node->data;
    node = node->next;
  }
}
void sol()
{
  ll n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> v1(n);
  node *head = NULL;

  head = new node(0);
  node *itrator = head;
  rep(i, 0, n)
  {
    ll t;
    cin >> t;
    node *head1 = NULL;
    head1 = new node(t);
    itrator->next = head1;
    itrator = itrator->next;
  }
  rep(i, 0, m)
  {
    ll t;
    cin >> t;
    cout << search(head, t) - 1 << " ";
    deleteNode(&head, t);

    node *head1 = NULL;
    head1 = new node(t);
    node *temp = head->next;
    head->next = head1;
    head1->next = temp;
  }
  // printList(head);
  cout << endl;
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