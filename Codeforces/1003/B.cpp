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
    int n;
    cin >> n;
    while (n--){
        string s;
        cin >> s;
        int ans = s.size();
        for (int i = 0; i < s.size() - 1; ++i)
            if (s[i] == s[i + 1]){
                ans = 1;
                break;
            }
        cout << ans << '\n';
    }
}