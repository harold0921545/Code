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

int dis[2][1005][1005];
char g[1005][1005];

signed main(){
    noTLE
    int h, w, sx, sy, ex, ey;
    cin >> h >> w;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j){
            cin >> g[i][j];
            if (g[i][j] == 'S')
                sx = i, sy = j;
            if (g[i][j] == 'G')
                ex = i, ey = j;
        }
    for (int k = 0; k < 2; ++k)
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                dis[k][i][j] = 1e8;
    queue<pair<int, pair<int, int>>> q;
    dis[0][sx][sy] = dis[1][sx][sy] = 0;
    int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    q.push(MP(0, MP(sx, sy)));
    q.push(MP(1, MP(sx, sy)));
    while (!q.empty()){
        int nx = q.front().S.F, ny = q.front().S.S;
        int p = q.front().F;
        q.pop();
        for (int k = p * 2; k < (p + 1) * 2; ++k){
            int x = nx + d[k][0], y = ny + d[k][1];
            if (x < 0 || y < 0 || x >= h || y >= w || g[x][y] == '#')
                continue;
            if (dis[p ^ 1][x][y] == 1e8)
                dis[p ^ 1][x][y] = dis[p][nx][ny] + 1, q.push(MP(p ^ 1, MP(x, y)));
        }
    }
    if (dis[0][ex][ey] == dis[1][ex][ey] && dis[0][ex][ey] == 1e8)
        cout << "-1\n";
    else
        cout << min(dis[0][ex][ey], dis[1][ex][ey]) << '\n';
}