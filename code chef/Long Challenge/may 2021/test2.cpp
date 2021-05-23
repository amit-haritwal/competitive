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

#define SCD(t) scanf("%d", &t)
#define SCLD(t) scanf("%ld", &t)
#define SCLLD(t) scanf("%lld", &t)
#define SCC(t) scanf("%c", &t)
#define SCS(t) scanf("%s", t)
#define SCF(t) scanf("%f", &t)
#define SCLF(t) scanf("%lf", &t)
#define INP(t) cin >> t
#define INP2(t, u) cin >> t >> u
#define INP3(t, u, v) cin >> t >> u >> v
#define OUT(t) cout << t << endl
#define OUT2(t, u) cout << t << " " << u << endl
#define OUT3(t, u, v) cout << t << " " << u << " " << v << endl
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define INPV(a, n) \
  REP(i, n)        \
  INP(a[i])
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert(B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
// #define MOD 1000000007
#define read(type) readInt<type>()
const double pi = acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<unsigned long long int> VI64;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

bool comp(pair<int, int> a, pair<int, int> b)
{
  if (a.first == b.first)
    return a.second < b.second;

  return a.first < b.first;
}
struct treenode
{
  int data, lvl;
  vector<treenode *> child;
  treenode(int x)
  {
    data = x;
    lvl = 0;
  }
};
void buildTree(treenode *root, vector<vector<int>> &adj, vector<bool> &visited)
{
  visited[root->data] = 1;
  for (int i = 0; i < adj[root->data].size(); i++)
  {
    if (visited[adj[root->data][i]])
    {
      treenode *temp = new treenode(adj[root->data][i]);
    }
  }
  for (int i = 0; i < root->child.size(); i++)
  {
    buildTree(root->child[i], adj, visited);
  }
}
void DFS(treenode *root, int level)
{
  root->lvl = level;
  for (auto node : root->child)
  {
    treenode *current = node;
    DFS(current, level + 1);
  }
}
vector<pair<int, int>> leaves;
void DFS2(treenode *root)
{
  for (auto node : root->child)
  {
    treenode *current = node;
    DFS2(current);
  }

  if (root->child.size() == 0)
  {
    leaves.push_back({root->lvl, root->data + 1});
  }
}

void solve()
{
  int n;
  INP(n);
  vector<vector<int>> adj(n + 5);
  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  treenode *root = new treenode(0);
  vector<bool> visited(n + 5, 0);
  buildTree(root, adj, visited);
  DFS(root, 0);
  vector<pair<int, int>> ans;
  for (auto node : root->child)
  {
    DFS2(node);
    vector<pair<int, int>> v;
    pair<int, int> p;
    bool f = 0;
    sort(leaves.begin(), leaves.end(), comp);
    p = leaves[0];
    v.push_back(p);
    int val = p.first;
    int j = 1;
    while (j < leaves.size())
    {
      while (j < leaves.size() && leaves[j].first == val)
      {
        if (f)
        {
          v.emplace_back(p.first + 1, leaves[j].second);
        }
        else
        {
          v.emplace_back(leaves[j]);
        }
        j++;
      }
      if (j < leaves.size())
      {
        v.clear();
        f = 1;
        p.second = leaves[j].second;
        v.emplace_back(p.first + 1, leaves[j].second);
        val = leaves[j].first;
        j++;
      }
    }
    leaves.clear();
    for (auto x : v)
    {
      ans.push_back(x);
    }
  }
  sort(ans.begin(), ans.end(), comp);
  int day = ans[0].first;
  vector<int> xyz;
  for (int i = 0; i < ans.size(); i++)
  {
    if (ans[i].first == day)
    {
      xyz.push_back(ans[i].second);
    }
    else
    {
      break;
    }
  }
  OUT2(xyz.size(), day);

  REP(i, xyz.size())
  {
    cout << xyz[i] << " ";
  }
  cout << "\n";
  return;
}

int main()
{

  std::ios::sync_with_stdio(false);
  cin.tie(0);

  int tc;
  INP(tc);

  while (tc--)
  {
    solve();
  }
  return 0;
}