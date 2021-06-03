#include <bits/stdc++.h>
using namespace std;
#define Int long long
const Int mxN = 3e5 + 10;
const int mod = 1e9 + 7;
struct DSU {
    vector <int> par, rank, add;
    DSU(int n)
    {
        par.resize(n + 10);
        rank.resize(n + 10, 0);
        add.resize(n + 10, 0);
        for(int i = 1; i <= n; ++i){
            par[i] = i;
        }
    }
    int find_set(int n)
    {
        if(par[n] == n)return n;
        else return  find_set(par[n]);
    }

    void merge(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if(a == b)return;
        if(rank[a] == rank[b])rank[a]++;
        if(rank[a] > rank[b]){
            par[b] = a;
            add[b] -= add[a];
        } else {
            par[a] = b;
            add[a] -= add[b];
        }
    }
    int get(int x)
    {
        if(par[x] == x)return add[x];
        else return add[x] + get(par[x]);
    }
    void Add(int x, int y)
    {
        add[find_set(x)] += y;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    DSU ds(n);
    while(q--){
        string s;
        int x, y;
        cin >> s;
        if(s == "join"){
            cin >> x >> y;
            ds.merge(x, y);
        } else if(s == "add"){
            cin >> x >> y;
            ds.Add(x, y);
        }
        else {
            cin >> x;
            cout << ds.get(x) << endl;
        }
    }
}
