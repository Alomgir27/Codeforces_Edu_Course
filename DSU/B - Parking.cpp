#include <bits/stdc++.h>
using namespace std;

#define Int long long

const int mxN = 1e6 + 10;
struct DSU {
    vector <int> par;
    DSU(int n)
    {
        par.resize(n + 5);
        iota(par.begin(), par.end(), 0);
    }
    int find(int n)
    {
        return par[n] == n ? n : par[n] = find(par[n]);
    }
    void join(int n)
    {
        n = find(n);
        par[n] = n + 1;
    }
};
int n, q;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    DSU dsu(n);
    q = n;
    while(q--){
        int x;
        cin >> x;
        x = dsu.find(x);
        cout << (x == n + 1 ? x = dsu.find(1) : x) << '\n';
        dsu.join(x);
    }

}

