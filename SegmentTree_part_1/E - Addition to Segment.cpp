#include <bits/stdc++.h>
using namespace std;

#define Int long long
#define inf (1ll << 60)
const int mxN = 2e5 + 10;
Int a[mxN];
Int n;
void upd(int x, Int v){
    for(int i = x; i <= n; i += i & -i)a[i] += v;
}
Int sum(int x){
    Int S = 0;
    for(Int i = x; i ; i -= i & -i) S += a[i];
    return S;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> n >> q;
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int l, r, v;
            cin >> l >> r >> v;
            upd(l + 1, v);
            upd(r + 1, -v);
        } else {
            int x;
            cin >> x;
            cout << sum(x + 1) << endl;
        }
    }


}
