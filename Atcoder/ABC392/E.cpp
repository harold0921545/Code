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

const int N = 2e5 + 25;
int fa[N];
int Find(int x){return x == fa[x] ? x : fa[x] = Find(fa[x]); };
vector<pair<int, pii>> add_edges;

signed main(){
    SongBird;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    for (int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        if (Find(a) != Find(b))
            fa[Find(a)] = Find(b);
        else
            add_edges.pb(MP(i + 1, MP(a, b)));
    }
    set<int> st;
    for (int i = 1; i <= n; ++i)
        st.insert(Find(i));
    vector<pair<int, pii>> ans;
    for (int i = 0; i < add_edges.size(); ++i){
        if (st.size() == 1)
            break;
        int t = 0;
        for (auto &j : st){
            if (Find(j) != Find(add_edges[i].S.F)){
                t = Find(j);
                break;
            }
        }
        ans.pb(MP(add_edges[i].F, MP(add_edges[i].S.F, t)));
        st.erase(Find(add_edges[i].S.F));
        fa[Find(add_edges[i].S.F)] = Find(t);
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i].F << ' ' << ans[i].S.F << ' ' << ans[i].S.S << '\n';
}