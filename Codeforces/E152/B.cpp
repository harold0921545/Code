#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front

#define ff first
#define ss second
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using pdd = pair<double, double>;
#define noTLE ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = " << x << "\n"



void solve(){
    int n;
    ll k;
    cin >> n >> k;
    vector<pll> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i].ff;
        a[i].ff = (a[i].ff - 1) % k + 1;
        a[i].ss = -(i + 1);
    }
    sort(a.begin(), a.end());
    for (int i = n - 1; i >= 0; --i)
        cout << -a[i].ss << ' ';
    cout << '\n';
}

signed main(){
    noTLE;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}