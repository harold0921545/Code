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
    int x, sum = 0;
    cin >> x;
    for (int i = 1; i <= 9; ++i)
        for (int j =  1; j <= 9; ++j)
            sum += (i * j) * ((i * j) != x);
    cout << sum << '\n';
}