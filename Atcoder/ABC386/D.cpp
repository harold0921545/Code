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

vector<pair<pii, char>> nod;

signed main(){
    noTLE
    int n, m;
    cin >> n >> m;
    bool ok = true;
    for (int i = 0; i < m; ++i){
        int x, y;
        char c;
        cin >> x >> y >> c;
        nod.pb(MP(MP(x, y), c));
    }
    sort(nod.begin(), nod.end());
    set<int> wn;
    for (int i = 0; i < m; ++i){
        int x = nod[i].F.F, y = nod[i].F.S;
        char c = nod[i].S;
        if (c == 'B'){
            if (wn.empty())
                continue;
            if (wn.upper_bound(y) != wn.begin())
                ok = false;
        }
        else 
            wn.insert(y);
    }
    if (ok)
        cout << "Yes\n";
    else
        cout << "No\n";
}