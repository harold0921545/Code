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

int a[1 << 20], mn[1 << 20], mx[1 << 20];

void solve(int l, int r){
    if (l == r) {
        return;
    }
    int mid = l + r >> 1;
    solve(l, mid);
    solve(mid + 1, r);
    if (a[l] > a[mid + 1]) {
        for (int i = l; i <= mid; ++i)
            swap(a[i], a[mid + 1 + i - l]);
    }
}

signed main(){
    smo1der
    int t;
    cin >> t;
    while (t--){
        int n, N;
        cin >> n;
        N = (1 << n);
        for (int i = 0; i < N; ++i)
            cin >> a[i];
        solve(0, N - 1);
        for (int i = 0; i < N; ++i)
            cout << a[i] << ' ';
        cout << '\n';
    }
}