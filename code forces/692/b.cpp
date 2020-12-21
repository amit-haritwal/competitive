#include <bits/stdc++.h>
using namespace std;
void amit_is_best() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
#define rep(i,a,b) for (ll i = a; i <b; i++)
#define res(i,a,b) for (ll i = a; i >=b; i--)
#define all(n) n.begin(),n.end()
#define mod 1000000007
template<typename T>
void pop_front(std::vector<T>& vec)
{
    assert(!vec.empty());
    vec.erase(vec.begin());
}
typedef long long ll;
const long long INF = 1e18 + 42;
bool comp(vector<ll> v1, vector<ll> v2) {
    return v1[1] < v2[1];
}
void sol() {
    ll n, ans;
    cin >> n;
    ans = n;
    while (true) {
        ll pred = ans;
        vector<ll> v1;
        while (true) {
            if (ans == 0) {
                break;
            }
            if (ans % 10 != 0) {
                v1.push_back(ans % 10);

            }
            ans = ans / 10;
        }
        ll flag = 1;
        rep(i, 0, v1.size()) {
            if (pred % v1[i] != 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << pred << endl;
            return;
        }
        ans = pred + 1;
    }
}
int main()
{
    amit_is_best();
    int a = 1;
    cin >> a;
    while (a--) {
        sol();
    }
}