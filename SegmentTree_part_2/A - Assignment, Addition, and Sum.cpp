#include<bits/stdc++.h>
#define endl '\n'
#define print(x) cout << (#x) << " is " << x << endl;
using namespace std;

const int mxN = 2e5 + 10;
#define int long long

int N, Q;

pair<int, int> ok[4 * mxN];

int mark[4 * mxN];

void segment(int k)
{
    if(mark[k]){
        mark[k] = 0;
        ok[2 * k].first = ok[2 * k + 1].first = ok[k].first / 2;
        ok[2 * k].second = ok[2 * k + 1].second = 0;
        mark[2 * k] = mark[2 * k + 1] = 1;
    }
}

void update(int node, int s, int e, int l, int r, int v)
{
    if(s > r || e < l)return;
    if(s >= l && e <= r){
        ok[node].second += v;
        return;
    }
    int mid = s + e >> 1;
    int h = min(e, r) - max(s, l) + 1;
    segment(node);
    ok[node].first += h * v;
    update(2 * node, s, mid, l, r, v);
    update(2 * node + 1, mid + 1, e, l, r, v);

}

int assign(int node, int s, int e, int l, int r, int v)
{
    if(s > r || e < l)return ok[node].first + (e - s + 1) * ok[node].second;
    if(s >= l && e <= r){
        ok[node].first = (e - s + 1) * v;
        ok[node].second = 0;
        mark[node] = 1;
        return ok[node].first;
    }
    int mid = s + e >> 1;
    segment(node);
    ok[2 * node].second += ok[node].second;
    ok[2 * node + 1].second += ok[node].second;
    ok[node].second = 0;
    ok[node].first = assign(2 * node, s, mid, l, r, v) + assign(2 * node + 1, mid + 1, e, l, r, v);
    return ok[node].first;
}
int query(int node, int s, int e, int l, int r)
{
    if(s > r || e < l)return 0;
    if(s >= l && e <= r){
        return ok[node].first + (e - s + 1) * ok[node].second;
    }
    segment(node);
    ok[node].first += (e - s  + 1) * ok[node].second;
    ok[2 * node].second += ok[node].second;
    ok[2 * node + 1].second += ok[node].second;
    ok[node].second = 0;
    int mid =  s + e >> 1;
    return query(2 * node, s, mid, l, r) + query(2 * node + 1, mid + 1, e, l, r);
}
int32_t main()
{
    cin >> N >> Q;
    N = ceil(1.0 * log2(1.0 * N));
    N = 1 << N;
    for (int i = 1; i <= Q; ++i){
        int t;
        cin >> t;
        if(t == 2)
        {
            int l, r, x;
            cin >> l >> r >> x;
            update(1, 1, N, l + 1, r, x);
        }
        else if(t == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            assign(1, 1, N, l + 1, r, x);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, N, l + 1, r) << endl;
        }
    }
}
