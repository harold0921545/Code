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
    for (int i = 0; i < n; ++i){
        string s;
        cin >> s;
        for (int j = 0; j < s.size() - 2; ++j)
            cout << s[j];
        cout << "i\n";
    }
}