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

vector<pair<int, vector<pii>>> dice;

signed main(){
    SongBird;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        map<int, int> cnt;
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j){
            int x;
            cin >> x;
            cnt[x]++;
        }
        vector<pii> tmp;
        for (auto &[p, q] : cnt)
            tmp.pb(MP(p, q));
        dice.pb(MP(k, tmp));
    }
    double ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j){
            double tmp = 0;
            for (int p = 0, q = 0; p < dice[i].S.size(); ++p){
                while (q < dice[j].S.size() && dice[j].S[q].F < dice[i].S[p].F)
                    q++;
                if (dice[i].S[p].F == dice[j].S[q].F){
                    double x = dice[i].S[p].S, y = dice[j].S[q].S;
                    tmp += ((x / dice[i].F) * (y / dice[j].F));
                }
            }
            ans = max(ans, tmp);
        }
    cout << fixed << setprecision(20) << ans << '\n';
}