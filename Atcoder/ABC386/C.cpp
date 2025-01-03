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

signed main(){
    noTLE
    int k;
    string s, t;
    cin >> k >> s >> t;
    if (s == t){
        cout << "Yes\n";
        exit(0);
    }
    if (abs((int)(s.size() - t.size())) > 1){
        cout << "No\n";
        exit(0);
    }
    if (s.size() == t.size()){
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i)
            if (s[i] != t[i])
                cnt++;
        if (cnt > 1)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    else {
        if (s.size() < t.size())
            swap(s, t);
        // s.size() > t.size()
        int l = s.size() - 1, r = 0;
        for (int i = 0; i < s.size() - 1; ++i)
            if (s[i] != t[i]){
                l = i;
                break;
            }
        for (int i = s.size() - 1; i > 0; --i){
            if (s[i] != t[i - 1]){
                r = i;
                break;
            }
        }
        if (r > l)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
}