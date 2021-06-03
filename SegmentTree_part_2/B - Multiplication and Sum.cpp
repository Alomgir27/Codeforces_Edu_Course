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

    long long NEUTRAL_ELEMENT = 0;
    long long modify_op(long long a, long long b){
        return (a * b) % MOD;
    }

    long long calc_op(long long a, long long b){
        return (a + b) % MOD;
    }

    long long apply_mod_op(long long &a, long long b){
        a = modify_op(a,  b);
    }
    void build(int x, int lx, int rx){
        if(rx == lx + 1) {
            values[x] = 1;
            return;
        }
        int m = (lx + rx) / 2;
        build(2 * x + 1, lx, m);
        build(2 * x + 2, m, rx);
        values[x] = calc_op(values[2 * x + 1], values[2 * x + 2]);
    }
    void init(int n) {
        size = 1;
        while(size < n)size *= 2;
        operations.assign(2 * size, 1ll);
        values.assign(2 * size, 1ll);
        build(0, 0, size);
    }
    void modify(int l, int r, int v, int x, int lx, int rx){
        if(lx >= r || l >= rx)return;
        if(lx >= l && rx <= r){
            apply_mod_op(operations[x],  v);
            apply_mod_op(values[x],  v);
            return;
        }
        int m = (lx + rx) / 2;
        modify(l, r, v, 2 * x + 1, lx, m);
        modify(l, r, v, 2 * x + 2, m, rx);
        values[x] = calc_op(values[2 * x + 1], values[2 * x + 2]);
        apply_mod_op(values[x], operations[x]);
    }
    void modify(int l, int r, int v){
        modify(l, r, v, 0, 0, size);
    }
    long long calc(int l, int r, int x, int lx, int rx){
        if(lx >= r || l >= rx) return NEUTRAL_ELEMENT;
        if(lx >= l && rx <= r){
            return values[x];
        }
        int m = (lx + rx) / 2;
        auto m1 = calc(l, r, 2 * x + 1, lx, m);
        auto m2 = calc(l, r, 2 * x + 2, m, rx);
        auto res = calc_op(m1, m2);
        apply_mod_op(res, operations[x]);
        return res;
    }
    long long calc(int l, int r){
        return calc(l, r, 0, 0, size);
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
            st.modify(l, r, v);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << st.calc(l, r) << '\n';
        }
    }
}
