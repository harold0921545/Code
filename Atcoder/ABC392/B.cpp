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
    int n, m;
    cin >> n >> m;
    set<int> exist;
    for (int i = 0; i < m; ++i){
        int x;
        cin >> x;
        exist.insert(x);
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i){
        if (exist.find(i) == exist.end())
            ans.pb(i);
    }
    cout << ans.size() << '\n';
    for (auto &i : ans)
        cout << i << ' ';
    cout << '\n';
}