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
#define SongBird ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);

signed main(){
    SongBird;
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < m; ++i)
            cin >> b[i];
        sort(b.begin(), b.end());
        a[0] = min(a[0], b[0] - a[0]);
        bool ok = true;
        for (int i = 1; i < n; ++i){
            int l = 0, r = m;
            while (l < r){
                int mid = l + r >> 1;
                if (b[mid] < a[i] + a[i - 1])
                    l = mid + 1;
                else
                    r = mid;
            }
            int j = l;
            if (j < m){
                if (a[i] >= a[i - 1] && b[j] - a[i] >= a[i - 1])
                    a[i] = min(a[i], b[j] - a[i]);
                else if (a[i] < a[i - 1])
                    a[i] = b[j] - a[i];
            }
            if (a[i] < a[i - 1]){
                ok = false;
                break;
            }
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
}