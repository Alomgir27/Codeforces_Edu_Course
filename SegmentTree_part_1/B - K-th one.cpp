#include <bits/stdc++.h>
using namespace std;

#define Int long long
#define inf (1ll << 60)
const int mxN = 2e5 + 10;
int Tree[4 * mxN];
int a[mxN];

void build(int node, int s, int e){
    if(s == e){
        Tree[node] = a[s];
        return;
    }
    int mid = s + e >> 1;
    build(2 * node, s, mid);
    build(2 * node + 1, mid + 1, e);
    Tree[node] = Tree[2 * node] + Tree[2 * node + 1];
}
void update(int node, int s, int e, int p){
    if(s > p || e < p)return;
    if(s == e){
        Tree[node] ^= 1;
        return;
    }
    int mid = s + e >> 1;
    update(2 *  node, s, mid, p);
    update(2 *  node + 1, mid + 1, e,  p);
    Tree[node] = Tree[2 * node] + Tree[2 * node + 1];
}
Int query(int node, int s, int e, int k)
{
    if(e == s)return s;
    int mid = s + e >> 1;
    if(Tree[2 * node] >= k)return query(2 * node, s, mid, k);
    else return query(2 * node + 1, mid + 1, e, k - Tree[2 * node]);
}
int main()
{
    Int N, Q;
    cin >> N >> Q;
    for(int i = 1; i <= N; ++i){
            cin >> a[i];
    }
    build(1, 1, N);
    while(Q--)
    {
        int l, r;
        cin >> l >> r;
        if(l == 1){
            update(1, 1, N, r + 1);
        } else {
            cout << query(1, 1, N, r + 1) - 1 << endl;
        }
    }
}
