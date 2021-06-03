#include <bits/stdc++.h>
using namespace  std;
const int mxN = 2e5 + 10;
#define Int long long
#define inf (1ll << 62)
pair<Int, Int> Tree[4 * mxN];
void update(int node, int s, int e, int p, Int v){
    if(s > p || e < p)return;
    if(s == e){
        Tree[node] = {v, 1};
        return;
    }
    int mid = s + e >> 1;
    update(2 * node, s, mid, p, v);
    update(2 * node + 1, mid + 1, e, p, v);
    if(Tree[2 * node].first < Tree[2 * node + 1].first)
        Tree[node] = Tree[2 * node];
    else if(Tree[2 * node].first > Tree[2 * node + 1].first)
        Tree[node] = Tree[2 * node + 1];
    else {
        Tree[node] = {Tree[2 * node].first, Tree[2 * node].second + Tree[2 * node + 1].second};
    }
}
pair<Int, Int> query(int node, int s, int e, int l, int r){
    if(s > r || e < l)return {inf, inf};
    if(s >= l && e <= r){
        return Tree[node];
    }
    int mid = s + e >> 1;
    pair<Int, Int> x = query(2 * node, s, mid, l, r);
    pair<Int, Int> y = query(2 * node + 1, mid + 1, e, l, r);
    if(x.first < y.first)
        return x;
    else if(x.first > y.first)
        return y;
    else {
        return {x.first, x.second + y.second};
    }
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
            pair<Int, Int> x = query(1, 1, n, l + 1, r);
            cout << x.first << ' ' << x.second << endl;
        }
    }
}
