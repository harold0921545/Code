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

int di[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

signed main(){
    smo1der
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<int>> a(h, vector<int>(w));
    vector<vector<int>> deg(h, vector<int>(w, 2));
    queue<pii> q;
    for (int i = 0; i < k; ++i){
        int x, y;
        cin >> x >> y;
        --x; --y;
        a[x][y] = 0;
        deg[x][y] = 0;
        q.push({x, y});
    }
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.F + di[i][0];
            int ny = cur.S + di[i][1];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            --deg[nx][ny];
            if (deg[nx][ny] == 0) {
                a[nx][ny] = a[cur.F][cur.S] + 1;
                q.push({nx, ny});
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            ans += a[i][j];
        }
    }
    cout << ans << '\n';
    return 0;
}