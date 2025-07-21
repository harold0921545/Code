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

signed main(){
    smo1der
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n + 1, vector<ll>(m + 1));
    vector<ll> p(n + m - 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int i = 0; i < n + m - 1; ++i)
        cin >> p[i];
    ll l = 0, r = 1e15;
    while (l < r){
        ll mid = l + r >> 1;
        vector<vector<ll>> dp(n + 1, vector<ll> (m + 1, -1e18));
        dp[1][1] = a[1][1] - p[0];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j){
                if (i > 1 || j > 1)
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j] - p[i + j - 2];
                if (dp[i][j] < -mid)
                    dp[i][j] = -1e18;
            }
        if (dp[n][m] < -mid)
            l = mid + 1;
        else
            r = mid;
    }
    cout << l << '\n';
}