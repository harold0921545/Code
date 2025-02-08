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

const int N = 5e5 + 25;
struct Treap{
    int sz[N], ch[N][2], pri[N], val[N];
    int root, cnt, z, x, y;

    void pull(int rt) { 
        sz[rt] = 1 + sz[ch[rt][0]] + sz[ch[rt][1]]; 
    }
    
    int new_node(int x){
        sz[++cnt] = 1;
        val[cnt] = x;
        pri[cnt] = rand();
        ch[cnt][0] = ch[cnt][1] = 0;
        return cnt;
    }

    void split(int now, int k, int &x, int &y){
        if (!now) x = y = 0;
        else{
            if (sz[ch[now][0]] + 1 <= k)
                x = now, split(ch[now][1], k - sz[ch[now][0]] - 1, ch[now][1], y);
            else
                y = now, split(ch[now][0], k, x, ch[now][0]);
            pull(now);
        }
    }

    int Merge(int A,int B){
        if (!A || !B)
            return A + B;
        if (pri[A] > pri[B]){
            ch[A][1] = Merge(ch[A][1], B);
            pull(A);
            return A;
        }
        else {
            ch[B][0] = Merge(A, ch[B][0]);
            pull(B);
            return B;
        }
    }
} treap;

void dfs(int now){
    if (treap.ch[now][0] != 0)
        dfs(treap.ch[now][0]);
    cout << treap.val[now] << ' ';
    if (treap.ch[now][1] != 0)
        dfs(treap.ch[now][1]);
}

signed main(){
    SongBird;
    srand(time(0));
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int nod = treap.new_node(i);
        int x; 
        cin >> x;
        int p, q;
        treap.split(treap.root, x - 1, p, q);
        treap.root = treap.Merge(p, treap.Merge(nod, q));
    }
    dfs(treap.root);
    cout << '\n';
}