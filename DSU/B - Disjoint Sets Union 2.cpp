#include <bits/stdc++.h>
using namespace std;

#define Int long long

const Int mxN = 3e5 + 10;

const int mod = 1e9 + 7;

struct DSU {
    vector <int> par, minv, maxv, rank, element;
    DSU(int n)
    {
        par.resize(n + 10);
        rank.resize(n + 10, 0);
        maxv.resize(n + 10);
        minv.resize(n + 10);
        element.assign(n + 10, 1);
        for(int i = 1; i <= n; ++i){
            par[i] = maxv[i] = minv[i] = i;
        }
    }

    int find_set(int n)
    {
        if(par[n] == n)return n;
        else return par[n] = find_set(par[n]);
    }

    void merge(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if(a == b)return;
        if(rank[a] == rank[b])rank[a]++;
        if(rank[a] > rank[b]){
            par[b] = a;
            maxv[a] = max(maxv[a], maxv[b]);
            minv[a] = min(minv[a], minv[b]);
            element[a] += element[b];
        } else {
            par[a] = b;
            maxv[b] = max(maxv[a], maxv[b]);
            minv[b] = min(minv[a], minv[b]);
            element[b] += element[a];
        }
    }
    int Max(int x){
        return maxv[find_set(x)];
    }
    int Min(int x){
        return minv[find_set(x)];
    }
    int Element(int x){
        return element[find_set(x)];
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
        if(s == "union"){
            cin >> x >> y;
            ds.merge(x, y);
        } else {
            cin >> x;
            cout << ds.Min(x) << ' ' << ds.Max(x) << ' ' << ds.Element(x) << endl;
        }
    }
}
