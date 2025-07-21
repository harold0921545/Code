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

signed main(){
    smo1der
    string s;
    cin >> s;
    vector<pii> ans;
    int lst = -1;
    for (int i = 0; i < s.size(); ++i){
        if (s[i] == '#'){
            if (lst == -1)
                lst = i;
            else
                ans.push_back(make_pair(lst, i)), lst = -1;
        }
    }
    for (auto i : ans)
        cout << i.F + 1 << ',' << i.S + 1 << '\n';
}