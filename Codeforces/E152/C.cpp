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

const int N = 2e5 + 25;
int a[N], l[N], r[N];

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        char c;
        cin >> c;
        a[i] = (c == '1');
        l[i] = r[i] = 0;
    }
    l[n + 1] = r[0] = 0;
    for (int i = n; i > 0; --i)
        if (a[i] == 0)
            l[i] = l[i + 1] + 1;
    for (int i = 1; i <= n; ++i)
        if (a[i] == 1)
            r[i] = r[i - 1] + 1;
    set<pii> st;
    bool ok = 0;
    while (m--){
        int x, y;
        cin >> x >> y;
        int L = x + l[x], R = y - r[y];
        if (L >= R)
            ok = 1;
        else
            st.insert(MP(L, R));
    }
    
    cout << st.size() + ok << '\n';
}
 
signed main(){
    noTLE;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}