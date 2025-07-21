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

const int K = 2e5 + 5;
int f[K];
int Find(int x){
    if (f[x] != x) f[x] = Find(f[x]);
    return f[x];
}
map<pii, int> mp;
int d[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

signed main(){
    smo1der
    int h, w, k;
    cin >> h >> w >> k;
    vector<pii> p(k);
    for (int i = 0; i < k; ++i) {
        cin >> p[i].F >> p[i].S;
        f[i] = i;
        mp[p[i]] = i;
    }
    for (int i = 0; i < k; ++i){
        for (int j = 0; j < 8; ++j){
            int nx = p[i].F + d[j][0];
            int ny = p[i].S + d[j][1];
            if (nx < 1 || nx > h || ny < 1 || ny > w) continue;
            if (mp.count({nx, ny})){
                int u = Find(i);
                int v = Find(mp[{nx, ny}]);
                if (u != v) f[u] = v;
            }
        }
    }
    set<int> a, b, c;
    for (int i = 0; i < k; ++i){
        if (p[i].F == 1)
            a.insert(Find(i));
        if (p[i].S == 1)
            b.insert(Find(i));
        if (p[i].F == h)
            c.insert(Find(i));
    }
    bool ans = true;
    for (int i = 0; i < k; ++i){
        if (p[i].F == 1){
            if (b.find(Find(i)) != b.end()) {
                ans = false;
                break;
            }
        }
        if (p[i].F == h){
            if (a.find(Find(i)) != a.end()) {
                ans = false;
                break;
            }
        }    
        if (p[i].S == w){
            if (b.find(Find(i)) != b.end() || c.find(Find(i)) != c.end()) {
                ans = false;
                break;
            }
        }
    }
    cout << (ans ? "Yes" : "No") << '\n';
}