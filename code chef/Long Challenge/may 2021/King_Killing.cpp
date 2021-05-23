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
vector<vector<int>> graph;
pair<vector<pair<int, int>>, vector<pair<int, int>>> dfs(int current, int past)
{
  vector<pair<int, int>> ans, final, temp, carry;
  if (graph[current].size() == 1 && past != -1)
  {
    ans.emplace_back(current, 0);
    return {ans, final};
  }
  for (auto i : graph[current])
  {
    if (i != past)
    {
      pair<vector<pair<int, int>>, vector<pair<int, int>>> z = dfs(i, current);
      vector<pair<int, int>> v1 = z.first, t = z.second;
      for (auto j : t)
      {
        carry.push_back(j);
      }
      for (auto j : v1)
      {
        j.second += 1;
        ans.push_back(j);
      }
    }
  }
  if (current == 1)
  {
    ll min1 = 2e5, flag = 0;
    for (auto j : ans)
    {

      if (min1 > j.second)
      {
        min1 = j.second;
      }
    }
    for (auto j : ans)
    {
      if (min1 == j.second)
      {
        final.push_back(j);
      }
    }
    return {final, temp};
  }
  else
  {
    ll min1 = 2e5, flag = 0;
    for (auto j : ans)
    {
      if (min1 > j.second)
      {
        min1 = j.second;
      }
    }
    for (auto j : ans)
    {
      if (min1 < j.second)
      {
        flag++;
        final.push_back(j);
      }
    }
    for (auto j : carry)
    {
      if (min1 < j.second)
      {
        flag++;
        final.push_back(j);
      }
      else
      {
        temp.push_back(j);
      }
    }
    if (flag == 0)
    {
      for (auto j : ans)
      {
        if (min1 == j.second)
        {
          final.push_back(j);
        }
      }
    }
    else
    {
      for (auto j : ans)
      {
        if (min1 >= j.second)
        {
          temp.push_back(j);
        }
      }
      for (int j = 0; j < final.size(); j++)
      {
        auto &i = final[j];
        i.second = min1 + 1;
      }
    }
    return {final, temp};
  }
}
void sol()
{
  int n;
  cin >> n;
  graph.resize(n + 1);
  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  vector<pair<int, int>> v1 = dfs(1, -1).first;
  cout << v1.size() << " " << v1[0].second << "\n";
  vector<int> ans;
  for (int j = 0; j < v1.size(); j++)
  {
    auto i = v1[j];
    ans.push_back(i.first);
  }
  sort(ans.begin(), ans.end());
  for (int j = 0; j < ans.size(); j++)
    cout << ans[j] << " ";
  cout << "\n";
  graph.clear();
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