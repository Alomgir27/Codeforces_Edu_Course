#include <bits/stdc++.h>
using namespace std;

#define Int long long
#define inf (1ll << 60)

const Int mxN = 1e5 + 10;

const int N = 2'0000'5;

class DSU {
private:
    vector <int> rank, par;
public:
    DSU(int n)
    {
        rank.resize(n + 5, 0);
        par.resize(n + 5);
        iota(par.begin(), par.end(), 0);
    }
    int find(int n)
    {
        return par[n] == n ? n : par[n] = find(par[n]);
    }
    void unite(int a, int b)
    {
        a = find(a), b = find(b);
        if(a == b)return;
        rank[a] += rank[a] == rank[b];
        if(rank[a] < rank[b])swap(a, b);
        par[b] = a;
        return;
    }

};

class node {
public:
    int u, v;
    long long w;
    node(int _u, int _v, long long _w) : u(_u), v(_v), w(_w) {}
    bool operator < (const node &p)const {
        return w < p.w;
    }
};

int n, m;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    vector <node> edges;
    DSU dsu(n);
    for (int i = 0; i < m; ++i){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges.push_back(node(u, v, w));
    }
    sort(edges.begin(), edges.end());
    long long ans = 0;
    for (auto e : edges){
        if(dsu.find(e.u) != dsu.find(e.v)){
            ans += e.w;
            dsu.unite(e.u, e.v);
        }
    }
    cout << ans << '\n';
}
