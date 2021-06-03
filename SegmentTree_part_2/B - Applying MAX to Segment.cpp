#include <bits/stdc++.h>
using namespace std;

#define Int long long
#define inf (1ll << 60)

const Int mxN = 1e5 + 5;

const Int mxmN = 1e6 + 5;

int mark[4 * mxN];
Int Tree[4 * mxN];


void update(Int node, Int s, Int e, Int l, Int r, Int new_val)
{
    if(s > r || e < l)return;
    if(s ==  l && e == r){
        Tree[node] = max(new_val, Tree[node]);
        return;
    }
    Int mid = (s + e) >> 1;
    update(2 * node, s, mid, l, min(mid, r), new_val);
    update(2 * node + 1, mid + 1, e, max(mid + 1, l), r, new_val);
}

Int query(Int node, Int s, Int e, Int p)
{
    if(s == e) return Tree[node];
    Int mid = (s + e) >>  1;
    if(p <= mid)return max(Tree[node],  query(2 * node, s, mid, p));
    else return  max(Tree[node], query(2 * node + 1, mid + 1, e, p));
}

int main()
{
    Int N, Q;
    cin >> N >> Q;
    while(Q--)
    {
        Int t;
        cin >> t;
        if(t == 1){
            Int l, r, v;
            cin >> l >> r >> v;
            update(1, 1, N, l + 1, r, v);
        }
        else {
            Int p;
            cin >> p;
            cout << query(1, 1, N, p + 1) << endl;
        }
    }
}
