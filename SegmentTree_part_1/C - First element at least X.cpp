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
    Tree[node] = max(Tree[2 * node] , Tree[2 * node + 1]);
}
void update(int node, int s, int e, int p, int v){
    if(s > p || e < p)return;
    if(s == e){
        Tree[node] = v;
        return;
    }
    int mid = s + e >> 1;
    update(2 *  node, s, mid, p, v);
    update(2 *  node + 1, mid + 1, e,  p, v);
    Tree[node] = max(Tree[2 * node] , Tree[2 * node + 1]);
}
Int query(int node, int s, int e, int x)
{
    if(Tree[node] < x)return 0;
    if(e == s)return s;
    int mid = s + e >> 1;
    if(Tree[2 * node] >= x)return query(2 * node, s, mid, x);
    else return query(2 * node + 1, mid + 1, e, x);
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
        int t;
        cin >> t;
        if(t == 1){
                int l, v;
        cin >> l >> v;
            update(1, 1, N, l + 1, v);
        } else {
            int x;
            cin >> x;
            cout << query(1, 1, N, x) - 1 << endl;
        }
    }
}
