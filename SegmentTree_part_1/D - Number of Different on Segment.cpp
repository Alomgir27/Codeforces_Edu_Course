#include <bits/stdc++.h>
using namespace std;

#define Int long long
#define inf (1ll << 60)
const int mxN = 2e5 + 10;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    int a[n + 10];
    set<int> st[50];
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        st[a[i]].insert(i);
    }
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int l, r;
            cin >> l >> r;
            int ans = 0;
            for(int i = 1; i <= 40; ++i){
                int x = *st[i].lower_bound(l);
                if(x >= l && x <= r)ans++;
            }
            cout << ans << endl;
        }
        else {
            int p, x;
            cin >> p >> x;
            st[a[p]].erase(p);
            st[x].insert(p);
            a[p] = x;
        }
    }


}
