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
#define SongBird ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);

signed main(){
    SongBird;
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> adj[n + 1];
        vector<int> a(n + 1);
        vector<bool> ans(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        for (int i = 0; i < n - 1; ++i){
            int x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        for (int i = 1; i <= n; ++i){
            set<int> st;
            st.insert(a[i]);
            for (auto j : adj[i]){
                if (st.find(a[j]) != st.end())
                    ans[a[j]] = 1;
                st.insert(a[j]);
            }
        }
        for (int i = 1; i <= n; ++i)
            cout << ans[i];
        cout << '\n';
    }
}