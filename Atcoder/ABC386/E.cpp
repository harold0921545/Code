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

ll a[200005];
ll mx = 0, cur = 0, b = 0;
int n, k;

void dfs(int x, int y){
    if (x == k){
        mx = max(mx, cur);
        return;
    }
    if (n - y < k - x)
        return;
    for (int i = y; i < n; ++i){
        cur ^= a[i];
        dfs(x + 1, i + 1);
        cur ^= a[i];
    }
}

signed main(){
    noTLE
    cin >> n >> k;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        cur ^= a[i];
    }
    if (k <= n - k)
        cur = 0;
    else    
        k = n - k;
    dfs(0, 0);
    cout << mx << '\n';
}