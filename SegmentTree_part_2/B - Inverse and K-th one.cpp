#include <bits/stdc++.h>
using namespace std;

#define Int long long
#define inf (1ll << 60)

const int mxN = 1e6 + 10;

int lazy[4 * mxN];
int Tree[4 * mxN];

void push(int node, int s, int e){
    if(s == e || lazy[node] % 2 == 0)
        return;
    int m = s + e >> 1;
    Tree[2 * node] = m - s + 1 - Tree[2 * node];
    Tree[2 * node + 1] = e - m - Tree[2 * node + 1];
    lazy[2 * node]++; lazy[2 * node + 1]++;
    lazy[node] = 0;
}

void update(int node, int s, int e, int l, int r){
    push(node, s, e);
    if(s > r || e < l)return;
    if(s >= l && e <= r){
        Tree[node] = (e - s + 1) - Tree[node];
        lazy[node] = 1;
        push(node, s, e);
        return;
    }
    int m = s + e >> 1;
    update(2 * node, s, m, l, r);
    update(2 * node + 1, m + 1, e, l, r);
    Tree[node] = Tree[2 * node] + Tree[2 * node + 1];
}
int query(int node, int s, int e, int p){
    int m = s + e >> 1;
    push(node, s, e);
    push(2 * node, s, m);
    push(2 * node + 1, m + 1, e);
    if(s == e)return s;
    if(Tree[2 * node] >= p)
        return query(2 * node, s, m, p);
    else
        return query(2 * node + 1, m + 1, e, p - Tree[2 * node]);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n, q;
    cin >> n >> q;
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int l, r;
            cin >> l >> r;
            update(1, 0, n - 1, l, r - 1);
        } else {
            int p;
            cin >> p;
            cout << query(1, 0, n - 1, p + 1) << endl;
        }
    }
}
