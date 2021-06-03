#include <bits/stdc++.h>
using namespace std;

#define Int long long
#define inf (1ll << 60)
const int mxN = 2e5 + 10;
int a[mxN], n;
void upd(int x, int v){
    for(int i = x; i <= n; i += i & -i)a[i] += v;
}
int sum(int x){
    if(x <= 0)return 0;
    int s = 0;
    for(int i = x; i ; i -= i & -i) s += a[i];
    return s;
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)upd(i, 1);
    int v[n + 10];
    for(int i = 1; i <= n; ++i){
        cin >> v[i];
    }
    int ans[n + 10];
    for(int i = n; i >= 1; --i){
        int lo = 1, hi = n;
        while(lo < hi){
            int mid = lo + hi >> 1;
            if(sum(n) - sum(mid) <= v[i])hi = mid;
            else lo = mid + 1;
        }
        ans[i] = lo;
        upd(lo, -1);
    }
    for(int i = 1; i <= n; ++i)cout << ans[i] << " \n" [i == n];

}
