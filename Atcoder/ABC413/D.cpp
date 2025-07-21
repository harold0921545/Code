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

const double eps = 1e-9;

signed main(){
    smo1der
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a.begin(), a.end(), [](int x, int y){
            return abs(x) < abs(y);
        });
        if (abs(a[0]) == abs(a[n - 1])){
            int x = 0;
            for (int i = 0; i < n; ++i){
                if (a[i] < 0)
                    x++;
            }
            if (x == n || x == 0 || x == n / 2 || x == (n + 1) / 2)
                cout << "Yes\n";
            else
                cout << "No\n";
            continue;
        }
        bool ok = true;
        for (int i = 0; i < n - 1; ++i){
            if (a[i + 1] * a[0] != a[i] * a[1]){
                ok = false;
                break;
            }
        }
        if (ok)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}