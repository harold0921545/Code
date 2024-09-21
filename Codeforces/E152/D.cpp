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
int a[N], f[N];
int Find(int x) { return f[x] == x ? x : f[x] = Find(f[x]);}

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        f[i] = i;
    }
    for (int i = 2; i <= n; ++i){
        if (a[i] > 0 && a[i - 1] > 0){
            int p = Find(i), q = Find(i - 1);
            if (p != q){
                if (a[p] < a[q])
                    swap(p, q);
                f[q] = p;
            }
        }
    }
    vector<int> v;
    v.pb(Find(1));
    for (int i = 2; i <= n; ++i){
        if (Find(i) != Find(i - 1))
            v.pb(Find(i));
    }
    int ans = 0;
    vector<bool> vis(v.size() + 5, 0);
    for (int i = 0; i < v.size(); ++i){
        if (a[v[i]] == 1){
            if (i - 1 >= 0 && !vis[i - 1])
                vis[i - 1] = 1;
            else if (i + 1 < v.size() && !vis[i + 1])
                vis[i + 1] = 1;
            ans++;
        }
        else if (a[v[i]] == 2){
            if (i - 1 >= 0 && !vis[i - 1])
                vis[i - 1] = 1;
            if (i + 1 < v.size() && !vis[i + 1])
                vis[i + 1] = 1;
            ans++;
        }
    }
    for (int i = 0; i < v.size(); ++i)
        if (a[v[i]] == 0 && !vis[i])
            ans++;
    cout << ans << '\n';
}

signed main(){
    noTLE;
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
}