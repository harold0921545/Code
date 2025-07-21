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
    ll n, m;
    cin >> n >> m;
    vector<pll> a(m);
    priority_queue<pll> pq;
    for (int i = 0; i < m; ++i){
        cin >> a[i].F >> a[i].S;
        pq.push(make_pair(a[i].S - a[i].F, a[i].F));
    }
    ll ans = 0;
    while (!pq.empty()){
        auto [x, y] = pq.top();
        pq.pop();
        if (n < y) continue;
        ll k = n - y;
        x = abs(x);
        ans += (k) / x + 1;
        n -= ((k) / x + 1) * x;
    }
    cout << ans << '\n';
}