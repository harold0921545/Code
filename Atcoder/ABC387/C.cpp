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

ll power[10][20];

ll f(string s){
    ll res = 0;
    for (int i = 1; i < s.size(); ++i)
        for (int j = 0; j < 10; ++j)
            res += (power[j][s.size() - i - 1]);
    int top = s[0] - '0';
    for (int i = 1; i < top; ++i)
        res += power[i][s.size() - 1];
    for (int i = 1; i <= s.size(); ++i){
        if (i == s.size())
            res++;
        else
            res += (power[top][s.size() - i - 1] * min(top, s[i] - '0'));
        if (s[i] - '0' >= top)
            break;
    }
    return res;
}

signed main(){
    noTLE
    ll L, R;
    string l, r;
    for (ll i = 1; i < 10; ++i){
        power[i][0] = 1;
        for (ll j = 1; j < 20; ++j)
            power[i][j] = power[i][j - 1] * i;
    }
    cin >> L >> R;
    l = to_string(L - 1), r = to_string(R);
    cout << f(r) - f(l) << '\n';
}