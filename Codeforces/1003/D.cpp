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
        int n, m;
        cin >> n >> m;
        vector<pair<int, vector<ll>>> a;
        for (int i = 0; i < n; ++i){
            ll sum = 0;
            vector<ll> c(m);
            for (int j = 0; j < m; ++j){
                cin >> c[j];
                sum += c[j];
            }
            a.pb(MP(sum, c));
        }
        sort(a.rbegin(), a.rend());
        ll ans = 0, cur = 0;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                cur += a[i].S[j];
                ans += cur;
            }
        }
        cout << ans << '\n';
    }
}