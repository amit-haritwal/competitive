#include <bits/stdc++.h>
using namespace std;
void amit_is_best()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define res(i, a, b) for (ll i = a; i >= b; i--)
#define all(n) n.begin(), n.end()
#define mod 1000000007
template <typename T>
void pop_front(std::vector<T> &vec)
{
  assert(!vec.empty());
  vec.erase(vec.begin());
}
typedef long long ll;
const long long INF = 1e18 + 42;
bool comp(vector<ll> v1, vector<ll> v2)
{
  return v1[1] < v2[1];
}
void sol()
{
  string str;
  cin >> str;
  int count1 = 0, count0 = 0;
  if (str.size() % 2 != 0)
  {
    cout << -1 << endl;
    return;
  }
  rep(i, 0, str.size())
  {
    if (str[i] == '0')
    {
      count0++;
    }
    else
    {
      count1++;
    }
  }
  if (str.size() == count0 or str.size() == count1)
  {
    cout << -1 << endl;
    return;
  }
  int ans = 0;
  ans = str.size() / 2 - min(count0, count1);
  cout << ans << endl;
}

int main()
{
  amit_is_best();
  int a = 1;
  cin >> a;
  while (a--)
  {
    sol();
  }
}