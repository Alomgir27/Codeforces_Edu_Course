#include <bits/stdc++.h>
using namespace std;

#define Int long long
#define inf (1ll << 60)

const Int mxN = 1e5 + 10;

Int Tree[4 * mxN];
Int mark[4 * mxN];

void push(Int node)
{
    if(mark[node] == 1){
    Tree[2 * node] = Tree[node];
    Tree[2 * node + 1] = Tree[node];
    mark[2 * node] = mark[node];
    mark[2 * node + 1] = mark[node];
    mark[node] = 0;
    }
}

void update(int node, int s, int e, int l, int r, int v){
    if(s > r || e < l)return;
    if(s == l && e == r){
        Tree[node] = v;
        mark[node] = 1;
        return;
    }
    push(node);
    int mid = s + e >> 1;
    update(2 * node, s, mid, l, min(r, mid), v);
    update(2 * node + 1, mid + 1, e, max(l, mid + 1), r, v);
    Tree[node] = min(Tree[2 * node] , Tree[2 * node + 1]);
}
Int query(int node, int s, int e, int l, int r){
    if(s > r || e < l) return inf;
    if(s == l && e == r){
        return Tree[node];
    }
    push(node);
    int mid = s + e >> 1;
    return  min(query(2 * node, s, mid, l, min(r, mid)) , query(2 * node + 1, mid + 1, e, max(l, mid + 1), r));
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    while(m--){
        int t;
        cin >> t;
        if(t == 1){
            int l, r, v;
            cin >> l >> r >> v;
            update(1, 1, n, l + 1, r, v);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l + 1, r) << '\n';
        }
    }
}
