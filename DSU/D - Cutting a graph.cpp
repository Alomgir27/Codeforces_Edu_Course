#include <bits/stdc++.h>
using namespace std;

#define Int long long

struct DSU{
    vector<int> rank, par, ans;
    void init(int n)
    {
        rank.assign(n + 5, 0);
        par.resize(n + 5);
        iota(par.begin(), par.end(), 0);
    }
    int find_set(int x)
    {
        if(x == par[x])return x;
        else return par[x] = find_set(par[x]);
    }
    bool merge(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if(a == b)return true;
        if(rank[a] < rank[b])swap(a, b);
        par[b] = a;
        rank[a] += rank[a] == rank[b];
        return false;
    }
    struct node{
        string type;
        int u, v;
    void read()
    {
        cin >> type >> u >> v;
    }
    };

    vector <node> query;
    void init_query(int k)
    {
        query.resize(k + 5);
        ans.resize(k + 5);
    }

};
int n, m, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    while(m--){
        int kinda, useless;
        cin >> kinda >> useless;
    }
    DSU ds;
    ds.init(n);
    ds.init_query(k);
    for(int i = 1; i <= k; ++i) ds.query[i].read();
    for(int i = k; i >= 1; --i){
        if(ds.query[i].type == "cut"){
            ds.merge(ds.query[i].u, ds.query[i].v);
        }
        else ds.ans[i] = ds.find_set(ds.query[i].u) == ds.find_set(ds.query[i].v);
    }
    for(int i = 1; i <= k; ++i)if(ds.query[i].type == "ask") cout << (ds.ans[i] ? "YES" : "NO") << '\n';
}
