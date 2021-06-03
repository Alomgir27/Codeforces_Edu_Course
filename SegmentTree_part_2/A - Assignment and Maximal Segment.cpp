#include <bits/stdc++.h>
using namespace std;

#define Int long long
#define inf (1ll << 60)

const Int mxN = 1e5 + 10;
struct data {
    Int sum, pref, suff, ans;
}Tree[4 * mxN];

int mark[4 * mxN];
Int val[4 * mxN];

data make_data(Int v){
    data res;
    res.sum = v;
    res.pref = res.suff = res.ans = max(0ll, v);
    return res;
}
data data_combine(data l, data r){
    data res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max({l.ans, r.ans, l.suff + r.pref});
    return res;
}
void push(int node)
{
    if(mark[node] == 1){
        Tree[2 * node] = Tree[2 * node + 1] = make_data(val[node] / 2);
        mark[2 * node] = mark[2 * node + 1] = mark[node];
        val[2 * node] = val[2 * node + 1] = val[node] / 2;
        val[node] = 0;
        mark[node] = 0;
    }
}
void update(int node, int s, int e, int l, int r, Int v){
    if(s > r || e < l)return;
    if(s >= l && e <= r){
        Tree[node] = make_data((e - s + 1)*v);
        val[node] = (e - s + 1) * v;
        mark[node] = 1;
        return;
    }
    push(node);
    int mid = s + e >> 1;
    update(2 *  node, s, mid, l, r, v);
    update(2 *  node +1, mid + 1, e,  l, r, v);
    Tree[node] = data_combine(Tree[2 * node], Tree[2 * node + 1]);
}
data query(int node, int s, int e, int l, int r)
{
    if(s > r || e < l)return make_data(0ll);
    if(s >=l && e<= r){
        return Tree[node];
    }
    push(node);
    int mid  = s + e >> 1;
    return data_combine(query(2 * node, s, mid, l, r) , query(2 * node + 1, mid + 1, e, l, r));
}
int main()
{
    Int N, Q;
    cin >> N >> Q;
    N = ceil(1.0 * log2(1.0 * N));
    N = 1 << N;
    while(Q--)
    {
        int l, r;
        Int v;
        cin >> l >> r >> v;
        update(1, 1, N, l + 1, r, v);
        cout << query(1, 1, N, 1, N).ans << endl;
    }
}
