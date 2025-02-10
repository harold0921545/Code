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
        int n, m, k;
        cin >> n >> m >> k;
        if (max(n, m) < k || max(n, m) - min(n, m) > k){
            cout << "-1\n";
            continue;
        }
        bool turn;
        if (m > n)
            turn = 1;
        else
            turn = 0;
        while (m > 0 || n > 0){
            if (turn == 1){
                for (int i = 0; i < min(k, m); ++i)
                    cout << '1';
                m -= min(k, m);
            }
            else{
                for (int i = 0; i < min(k, n); ++i)
                    cout << '0';
                n -= min(k, n);
            }
            turn ^= 1;
        }
        cout << '\n';
    }
}