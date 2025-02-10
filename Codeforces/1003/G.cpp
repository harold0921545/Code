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
bool prime[N];
vector<int> p;

signed main(){
    SongBird;
    for (int i = 0; i < N; i++)
        prime[i] = 1;
    prime[0] = prime[1] = 0;
    for (int i = 2; i < N; i++){
        if (prime[i])
            p.pb(i);
        for (auto x : p){
            if (x * i >= N)
                break;
            prime[x * i] = 0;
            if (i % x == 0)
                break;
        }
    }
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<ll> cnt(n + 1, 0);
        for (int i = 0; i < n; ++i){
            cin >> a[i];
            cnt[a[i]]++;
        }
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        ll ans = 0, p_cnt = 0;
        for (int i = 0; i < a.size(); ++i){
            if (prime[a[i]]){
                ans += (cnt[a[i]] * p_cnt);
                p_cnt += cnt[a[i]];
            }
            else{
                for (int j = 2; j <= sqrt(a[i]); ++j){
                    if (a[i] % j == 0 && prime[j] && prime[a[i] / j]){
                        if (j != a[i] / j)
                            ans += (cnt[j] + cnt[a[i] / j]) * cnt[a[i]];
                        else
                            ans += cnt[j] * cnt[a[i]];
                        ans += ((cnt[a[i]] + 1LL) * cnt[a[i]]) / 2LL;
                        break;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}