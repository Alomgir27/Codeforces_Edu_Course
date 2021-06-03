#include <bits/stdc++.h>
using namespace std;

#define Int long long
#define inf (1ll << 60)
const int mxN = 2e5 + 10;
Int a[mxN];
Int b[mxN];
Int c[mxN];
Int n;
void upd(int x, Int v){
    for(int i = x; i <= n; i += i & -i)a[i] += v;
}
void upd1(int x, Int v){
    for(int i = x; i <= n; i += i & -i)b[i] += v;
}
Int sum(int x){
    Int S = 0;
    for(Int i = x; i ; i -= i & -i) S += a[i];
    return S;
}
Int sum1(int x){
    Int S = 0;
    for(Int i = x; i ; i -= i & -i) S += b[i];
    return S;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> n;
    for(int i = 1; i <= n; ++i){
            cin >> c[i];
        if(i % 2)upd(i, c[i]);
       else upd1(i, c[i]);
    }
    cin >> q;
    while(q--){
        int t;
        cin >> t;
        if(t == 0){
            int p,  v;
            cin >> p >> v;
            if(p % 2)upd(p, -c[p] + v),c[p] = v;
            else upd1(p, -c[p] + v), c[p] = v;
        } else {
            int l, r;
            cin >> l >> r;
            if(l % 2) cout << (sum(r) - sum(l - 1)) - (sum1(r) - sum1(l - 1)) << endl;
            else cout << (sum1(r) - sum1(l - 1)) - (sum(r) - sum(l - 1)) << endl;
        }
    }


}
