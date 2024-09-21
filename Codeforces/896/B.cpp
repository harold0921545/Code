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
#define noTLE ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = " << x << "\n"

void solve(){
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    vector<pll> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i].F >> p[i].S;
    a--, b--;
    ll mna = 1e10, mnb = 1e10;
    for (int i = 0; i < k; ++i){
        mna = min(mna, abs(p[a].F - p[i].F) + abs(p[a].S - p[i].S));
        mnb = min(mnb, abs(p[b].F - p[i].F) + abs(p[b].S - p[i].S));
    }

    if (a < k && b < k){
        cout << "0\n";
    }
    else if (a < k && b >= k){
        cout << min(abs(p[b].F - p[a].F) + abs(p[b].S - p[a].S), mnb) << '\n';
    }
    else if (a >= k && b < k){
        cout << min(abs(p[b].F - p[a].F) + abs(p[b].S - p[a].S), mna) << '\n';
    }
    else
        cout << min(abs(p[b].F - p[a].F) + abs(p[b].S - p[a].S), mna + mnb) << '\n';
}

signed main(){
    noTLE;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}