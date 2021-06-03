#include <bits/stdc++.h>
using namespace std;

#define Int long long

const int mxN = 1e6 + 10;
int a[4 * mxN];
int n, q;
void upd(int node, int s, int e, int p, int v)
{
    if(s > p || e < p)return;
    if(s == e){
        a[node] = v;
        return;
    }
    int m = (s + e) >> 1;
    upd(2 * node, s, m, p, v);
    upd(2 * node + 1, m + 1, e, p, v);
    a[node] = min(a[2 * node], a[2 * node + 1]);
}
int query(int node, int s, int e, int l,int r){
    if(s > r || e < l)return 1e9;
    if(s >= l && e <= r)return a[node];
    int m = (s + e) >> 1;
    return min(query(2 * node, s, m, l, r), query(2 * node + 1, m + 1, e, l, r));
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        upd(1, 1, n, i, i);
    }
    while(q--){
        char ch;
        int x;
        cin >> ch >> x;
        if(ch == '?'){
            x = query(1, 1, n, x, n);
            cout << (x == 1e9 ? -1 : x) << '\n';
        }
        else {
            upd(1, 1, n, x, (int)1e9);
        }
    }

}

