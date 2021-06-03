#include <bits/stdc++.h>
using namespace std;

#define Int long long

const Int mxN = 1e5 + 10;

const int mod = 1e9 + 7;

int par[mxN];

void make_set(int n)
{
    par[n] = n;
}

int find_set(int n)
{
    if(par[n] == n)return n;
    return par[n] = find_set(par[n]);
}

bool find_union(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a == b)return true;
    else return false;
}

void merge(int a, int b)
{
    a = find_set(par[a]);
    b = find_set(par[b]);
    if(a != b){
        par[b] = a;
    }
}
int n, q;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        make_set(i);
    }

    while(q--){
        string s;
        int u, v;
        cin >> s >> u >> v;
        if(s == "union"){
            merge(u, v);
        }
        else cout << (find_union(u, v) ? "YES" : "NO") << endl;
    }
}
