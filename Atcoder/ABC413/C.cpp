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
    int q;
    cin >> q;
    deque<pll> dq;
    while (q--){
        int opt;
        cin >> opt;
        if (opt == 1){
            int c, x;
            cin >> c >> x;
            if (dq.empty() || dq.back().second != x)
                dq.pb({c, x});
            else
                dq.back().first += c;
            
        }
        else{
            int k;
            cin >> k;
            ll ans = 0;
            while (k > 0 && !dq.empty()){
                if (dq.front().first <= k){
                    ans += dq.front().first * dq.front().second;
                    k -= dq.front().first;
                    dq.ppf();
                }
                else{
                    ans += k * dq.front().second;
                    dq.front().first -= k;
                    k = 0;
                }
            }
            cout << ans << "\n";
        }
    }
}