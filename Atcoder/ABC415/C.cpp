#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front

#define F first
#define S second
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using pdd = pair<double, double>;
#define smo1der ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = " << x << "\n"

map<ll, bool> mp, vis;
bool ok = false;

void dfs(int now, int n){
    if (mp[now] || vis[now]) return;
    // debug(now);
    vis[now] = true;
    if (now == ((1LL << n) - 1))
        ok = true;
    if (ok) return;
    for (int i = 0; i < n; ++i){
        if ((now & (1 << i)) == 0)
            dfs(now | (1 << i), n);
    }
}

signed main(){
    smo1der
    int t;
    cin >> t;
    while (t--){
        int n;
        string s;
        cin >> n >> s;
        mp.clear();
        vis.clear();
        ok = false;
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '1')
                mp[i + 1] = true;
        }
        dfs(0, n);
        cout << (ok ? "Yes\n" : "No\n");
    }
}