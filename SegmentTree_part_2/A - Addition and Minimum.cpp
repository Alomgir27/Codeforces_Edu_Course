#include <bits/stdc++.h>
using namespace std;

#define Int long long
#define inf (1ll << 60)

const Int mxN = 1e5 + 5;

const Int mxmN = 1e6 + 5;
const Int mod = 1e9 + 7;

Int lazy[4 * mxN];
Int Tree[4 * mxN];
Int N, Q;

void push(Int node)
{
    Tree[2 * node] += lazy[node];
    lazy[2 * node] += lazy[node];
    Tree[2 * node + 1] += lazy[node];
    lazy[2 * node + 1] += lazy[node];
    lazy[node] = 0;
}
void update(Int node, Int s, Int e, Int l, Int r, Int new_val)
{
    if(s > r || e < l)return;
    if(s == l && e == r)
    {
        Tree[node] += new_val;
        lazy[node] += new_val;
        return;
    }
    push(node);
    Int mid = s + e >> 1;
    update(2 * node, s, mid, l, min(r, mid), new_val);
    update(2 * node + 1, mid + 1, e, max(l, mid + 1), r, new_val);
    Tree[node] = min(Tree[2 * node], Tree[2 * node + 1]);
}
Int query(Int node, Int s, Int e, Int l, Int r)
{
    if(s > r || e < l)return inf;
    if(s >= l && e <= r){
        return Tree[node];
    }
    push(node);
    Int mid  =  s + e >> 1;
    return min(query(2 * node, s, mid, l, r), query(2 * node + 1, mid + 1, e, l, r));
}
int main()
{
    cin >> N >> Q;
    while(Q--)
    {
        Int t;
        cin >> t;
        if(t == 1)
        {
            Int l, r, v;
            cin >> l >> r >> v;
            update(1, 1, N, l + 1, r, v);
        }
        else {
            Int l, r;
            cin >> l >> r;
            Int x = query(1, 1, N, l + 1, r);
            cout << (x == inf ? 0 : x) << endl;
        }
    }
}
/**
10 10
1 0 9 10
2 9 9
1 0 5 7
1 5 9 8
2 3 7
2 8 9
1 3 8 10
1 2 2 8
2 1 6
2 8 8
**/
