#include <bits/stdc++.h>
using namespace std;

#define Int long long
const int mxN = 1e6 + 10;
#define inf (1ll << 62)

Int Tree[4 * mxN];
Int lazy[4 * mxN];
int mark[4 * mxN];
Int N, Q;

void push(int node){
    if(mark[node] == 1){
        Tree[2 * node] += lazy[node];
        Tree[2 * node + 1] += lazy[node];
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
        mark[2 * node] = mark[2 * node + 1] = mark[node];
        lazy[node] = 0;
        mark[node] = 0;
    }
}

void update(int node, int s, int e, int l, int r, Int new_val){
    push(node);
    if(s > r || e < l)return;
    if(s >= l && e <= r){
        lazy[node] += new_val;
        mark[node] = 1;
        Tree[node] += new_val;
        return;
    }
    push(node);
    int mid = s + e >> 1;
    update(2 * node, s, mid, l, r, new_val);
    update(2 * node + 1, mid + 1, e, l, r, new_val);
    Tree[node] = max(Tree[2 * node] , Tree[2 * node + 1]);
}

Int query(int node, int s, int e, int l, Int x){
    if(l > e)return inf;
    if(Tree[node] < x)return inf;
    if(s == e)return s;
    push(node);
    int mid = s + e >> 1;
    Int x_ = query(2 * node, s, mid, l, x);
    if(x_ == inf)x_ = query(2 * node + 1, mid + 1, e, l, x);
    return x_;
}
int main()
{
    cin >> N >> Q;
    while(Q--){
        int t;
        cin >> t;
        if(t == 1){
            int l, r;
            Int v;
            cin >> l >> r >> v;
            update(1, 1, N, l + 1, r, v);
        } else {
            Int x, l;
            cin >> x >> l;
            x = query(1, 1, N, l + 1, x);
            cout << (x == inf ? -1 : x - 1) << endl;
        }
    }
}
