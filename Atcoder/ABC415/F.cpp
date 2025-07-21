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

const int N = 5e5 + 25;
int mx[N << 2], L[N << 2], R[N << 2];
int a[N];

#define ls rt << 1
#define rs rt << 1 | 1

void pull(int l, int r, int rt){
    int mid = l + r >> 1;
    L[rt] = L[ls] + L[rs] * (L[ls] == mid - l + 1 && a[l] == a[mid + 1]);
    R[rt] = R[ls] * (R[rs] == r - mid && a[r] == a[mid]) + R[rs];
    mx[rt] = max({mx[ls], mx[rs], (a[mid] == a[mid + 1]) * (R[ls] + L[rs])});
}

void build(int l, int r, int rt){
    if (l == r){
        mx[rt] = L[rt] = R[rt] = 1;
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, ls);
    build(mid + 1, r, rs);
    pull(l, r, rt);
}

void update(int l, int r, int rt, int k, int val){
    if (l == r){
        a[k] = val;
        mx[rt] = L[rt] = R[rt] = 1;
        return;
    }
    int mid = l + r >> 1;
    if (k <= mid)
        update(l, mid, ls, k, val);
    else
        update(mid + 1, r, rs, k, val);
    pull(l, r, rt);
}

pair<int, pii> query(int l, int r, int rt, int ql, int qr){
    if (l >= ql && r <= qr)
        return {mx[rt], {L[rt], R[rt]}};
    int mid = l + r >> 1;
    if (qr <= mid)
        return query(l, mid, ls, ql, qr);
    if (ql > mid)
        return query(mid + 1, r, rs, ql, qr);
    pair<int, pii> ll = query(l, mid, ls, ql, qr);
    pair<int, pii> rr = query(mid + 1, r, rs, ql, qr);
    int MX = max({ll.F, rr.F, (a[mid] == a[mid + 1]) * (ll.S.S + rr.S.F)});
    int LL = ll.S.F + rr.S.F * (ll.S.F == mid - l + 1 && a[l] == a[mid + 1]);
    int RR = ll.S.S * (rr.S.S == r - mid && a[r] == a[mid]) + rr.S.S;
    return {MX, {LL, RR}};
}

signed main(){
    smo1der
    int n, q;
    string s;
    cin >> n >> q >> s;
    for (int i = 1; i <= n; ++i)
        a[i] = s[i - 1] - 'a';
    build(1, n, 1);
    while (q--){
        int opt;
        cin >> opt;
        if (opt == 1){
            int i;
            char x;
            cin >> i >> x;
            update(1, n, 1, i, x - 'a');
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << query(1, n, 1, l, r).F << '\n';
        }
    }
}