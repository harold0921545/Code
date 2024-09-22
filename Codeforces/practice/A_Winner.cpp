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

signed main(){
    noTLE
    int n;
    cin >> n;
    vector<pair<string, int>> v(n);
    map<string, int> mp;
    for (int i = 0; i < n; ++i){
        cin >> v[i].ff >> v[i].ss;
        mp[v[i].ff] += v[i].ss;
    }
    vector<string> candidate;
    int mx = 0;
    for (auto x : mp){
        mx = max(mx, x.ss);
    }
    for (auto x : mp){
        if (x.ss == mx)
            candidate.pb(x.ff);
    }
    mp.clear();
    for (int i = 0; i < n; ++i){
        mp[v[i].ff] += v[i].ss;
        if (mp[v[i].ff] >= mx && find(candidate.begin(), candidate.end(), v[i].ff) != candidate.end()){
            cout << v[i].ff << '\n';
            return 0;
        }
    }
}