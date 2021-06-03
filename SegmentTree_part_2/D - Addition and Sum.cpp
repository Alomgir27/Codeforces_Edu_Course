#include <bits/stdc++.h>
using namespace std;

#define Int long long
#define inf (1ll << 60)

const Int mxN = 1e5 + 10;

Int Tree[4 * mxN];
Int lazy[4 * mxN];
int n, m;
void update(int x, Int v)
{
    for(int i = x;i <= n; i += i & -i)Tree[i] += v;
}
void update1(int x, Int v)
{
    for(int i = x; i <= n; i += i & -i)lazy[i] += v;
}
void update2(int l, int r, Int v){
    update(l, v);
    update(r + 1, -v);
    update1(l, (l-1) * v);
    update1(r + 1, -r * v);
}
Int sum(int x){
    Int S = 0;
    for(int i = x; i ; i -= i & -i){
        S += Tree[i];
    }
    return S;
}
Int sum1(int x){
    Int S = 0;
    for(int i = x; i ; i -= i & -i){
        S += lazy[i];
    }
    return S;
}
Int query(int x){
    return sum(x) * x - sum1(x);
}
Int range_sum(int l, int r){
    return query(r) - query(l - 1);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);

    cin >> n >> m;
    while(m--){
        int t;
        cin >> t;
        if(t == 1){
            int l, r, v;
            cin >> l >> r >> v;
            update2(l + 1, r, v);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << range_sum(l + 1, r) << '\n';
        }
    }
}
