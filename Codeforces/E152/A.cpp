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
    int a, b, c;
    cin >> a >> b >> c;
    if (b + c < a - 1)
        cout << 2 * (b + c) + 1 << '\n';
    else
        cout << 2 * a - 1 << '\n';
}

signed main(){
    noTLE;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}