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

/*******  All Required define Pre-Processors and typedef Constants *******/
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
vector<vector<int>> adj;
vector<int> lvl;
vector<pair<int, int>> leaves;

bool comp(pair<int, int> a, pair<int, int> b)
{
  if (a.first == b.first)
    return a.second < b.second;

  return a.first < b.first;
}
class Graph
{
public:
  int V;
  void addEdge(int v, int w);
  void DFS(int u, int v, int level);
  void DFS2(int u, int v);
};

void Graph::addEdge(int v, int w)
{
  adj[v].push_back(w);
  adj[w].push_back(v);
}

void Graph::DFS(int u, int v, int level)
{
  lvl[u] = level;
  for (auto node : adj[u])
  {
    if (node != v)
    {
      DFS(node, u, level + 1);
    }
  }

  return;
}

void Graph::DFS2(int u, int v)
{
  for (auto node : adj[u])
  {
    if (node != v)
    {
      DFS2(node, u);
    }
  }

  if (1 == adj[u].size())
  {
    leaves.emplace_back(lvl[u], u + 1);
  }

  return;
}

void solve()
{
  int n;
  INP(n);

  Graph g;
  adj.resize(n + 5);
  lvl.resize(n + 5);

  REP(i, n - 1)
  {
    int u, v;
    INP2(u, v);
    g.addEdge(--u, --v);
  }
  g.DFS(0, 0, 0);
  vector<pair<int, int>> ans;
  for (int i = 0; i < adj[0].size(); i++)
  {
    g.DFS2(adj[0][i], 0);
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

  adj.clear();
  lvl.clear();
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