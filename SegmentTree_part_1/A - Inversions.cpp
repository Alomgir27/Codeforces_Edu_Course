#include <bits/stdc++.h>
using namespace std;

#define Int long long
#define inf (1ll << 60)
const int mxN = 2e5 + 10;
int a[mxN], n;
void upd(int x){
    for(int i = x; i <= n; i += i & -i)a[i]++;
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
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        cout << sum(n) - sum(x - 1) << endl;
        upd(x);
    }

}
