#include <bits/stdc++.h>
using namespace std;

#define Int long long
#define inf (1ll << 60)

const Int mxN = 1e5 + 5;

const Int mxmN = 1e6 + 5;
const Int mod = 1e9 + 7;

const long long MOD = 1000000007;

struct segtree {
    int size;
    vector<long long> operations;
    vector<long long> values;

    long long NEUTRAL_ELEMENT = -1;
    long long modify_op(long long a, long long b){
        return (a | b);
    }

    long long calc_op(long long a, long long b){
        return (a & b);
    }

    long long apply_mod_op(long long &a, long long b){
        a = modify_op(a,  b);
    }
    void build(int node, int s, int e){
        if(s == e) {
            values[node] = 1;
            return;
        }
        int m = (s + e) / 2;
        build(2 * node, s, m);
        build(2 * node + 1, m + 1, e);
        values[node] = calc_op(values[2 * node], values[2 * node + 1]);
    }
    void init(int n) {
        size = 1;
        while(size < n)size *= 2;
        operations.assign(4 * size  , 0);
        values.assign(4 * size, 0);
        //build(1, 1, size);
    }
    void modify(int node, int s, int e, int l, int r, int v){
        if(s > r || e < l)return;
        if(s >= l && e <= r){
            apply_mod_op(operations[node],  v);
            apply_mod_op(values[node],  v);
            return;
        }
        int m = (s + e) / 2;
        modify(2 * node, s, m, l, r, v);
        modify(2 * node + 1, m + 1, e, l, r, v);
        values[node] = calc_op(values[2 * node], values[2 * node + 1]);
        apply_mod_op(values[node], operations[node]);
    }
    void modify(int l, int r, int v){
        modify(1, 1, size, l, r, v);
    }
    long long calc(int node, int s, int e, int l, int r){
        if(s > r || e < l) return NEUTRAL_ELEMENT;
        if(s >= l && e <= r){
            return values[node];
        }
        int m = (s + e) / 2;
        auto m1 = calc(2 * node, s, m, l, r);
        auto m2 = calc(2 * node + 1, m + 1, e, l, r);
        auto res = calc_op(m1, m2);
        apply_mod_op(res, operations[node]);
        return res;
    }
    long long calc(int l, int r){
        return calc(1, 1, size, l, r);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    segtree st;
    st.init(n);
    while(m--){
        int t;
        cin >> t;
        if(t == 1){
            int l, r, v;
            cin >> l >> r >> v;
            st.modify(l + 1, r, v);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << st.calc(l + 1, r) << '\n';
        }
    }
}
