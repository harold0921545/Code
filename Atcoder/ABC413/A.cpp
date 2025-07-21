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
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        m -= x;
    }
    cout << (m >= 0 ? "Yes" : "No") << "\n";
}