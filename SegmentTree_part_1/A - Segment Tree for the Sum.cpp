#include <bits/stdc++.h>
using namespace  std;
const int mxN = 2e5 + 10;
#define Int long long

Int Tree[4 * mxN];

void update(int node, int s, int e, int p, Int v){
    if(s > p || e < p)return;
    if(s == e){
        Tree[node] = v;
        return;
    }
    int mid = s + e >> 1;
    update(2 * node, s, mid, p, v);
    update(2 * node + 1, mid + 1, e, p, v);
    Tree[node] = Tree[2 * node] + Tree[2 * node + 1];
}
Int query(int node, int s, int e, int l, int r){
    if(s > r || e < l)return 0;
    if(s >= l && e <= r){
        return Tree[node];
    }
    int mid = s + e >> 1;
    return query(2 * node, s, mid, l, r) + query(2 * node + 1, mid+1, e, l, r);
}
int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n;++i){
        int x;
        cin >> x;
        update(1, 1, n, i, x);
    }
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int p, x;
            cin >> p >> x;
            update(1, 1, n, p + 1, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l + 1, r) << endl;
        }
    }
}
