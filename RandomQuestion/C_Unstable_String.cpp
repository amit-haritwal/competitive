#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<vector<int>> lst(2, vector<int>(2, -1));
    long long ans = 0;
    for (int i = 0; i < int(s.size()); ++i) {
      int j = i - 1;
      int p = i & 1;
      if (s[i] != '1') j = min(j, max(lst[0][p ^ 1], lst[1][p]));
      if (s[i] != '0') j = min(j, max(lst[0][p], lst[1][p ^ 1]));
      ans += i - j;
      if (s[i] != '?') lst[s[i] - '0'][p] = i;
    }
    cout << ans << '\n';
  }
}