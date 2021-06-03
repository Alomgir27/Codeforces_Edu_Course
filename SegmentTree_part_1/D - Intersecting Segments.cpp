#include <bits/stdc++.h>
using namespace std;

#define Int long long
#define inf (1ll << 60)
const int mxN = 2e5 + 10;
vector<int> idx[mxN];
int mp[mxN];
int a[2 * mxN];
int block;
int cnt;
struct mint{
    int l, r, idx;
    mint(int _l, int _r, int _idx){
        l = _l, r = _r, idx = _idx;
    }
    bool operator < (const mint &p)const {
        if(l / block != p.l / block){
            return l < p.l;
        }
        else return r < p.r;
    }
};
void add(int x){
    mp[x]++;
    if(mp[x] == 1)cnt++;
    else cnt--;
}
void remove(int x){
    if(mp[x] == 2)cnt++;
    else cnt--;
    mp[x]--;
}
vector<mint> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= 2 * n; ++i){
        cin >> a[i];
        idx[a[i]].push_back(i);
    }
    for(int i = 1; i <= n; ++i){
        v.push_back({min(idx[i][0], idx[i][1]), max(idx[i][0], idx[i][1]), i});
    }
    block = sqrt(2 * n);
    sort(v.begin(), v.end());
    int ans[n + 10];
    int L = 1, R = 0;
    for(int i = 0; i < n; ++i){
        int l = v[i].l;
        int r = v[i].r;
        while(R < r)add(a[++R]);
        while(R > r)remove(a[R--]);
        while(L < l)remove(a[L++]);
        while(L > l)add(a[--L]);
        ans[v[i].idx] = cnt;
    }
    for(int i = 1; i <= n; ++i)cout << ans[i] << ' ';
    cout << endl;


}
