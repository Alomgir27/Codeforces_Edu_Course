///Accepted code

#include <bits/stdc++.h>
#define mod 1000000007
#define ull unsigned ll
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define pi acos(-1)
#define nui 100
#define INF 100000000000

#define F(i,a,n) for(ll i=a;i<n;i++)
#define B(i,a,n) for(ll i=n-1;i>=a;i--)
#define tc int t;cin>>t;while(t--)
#define tcf int t;cin>>t;for(int w=1;w<=t;w++)
#define all(x) x.begin(), x.end()



#define vll vector<ll>
#define pll pair<ll,ll>

using namespace std;


ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

ll fermat_inv(ll y) {return binpow(y, mod - 2);}

// 1-based indexing


struct node
{
    ll w,x,y,z;
};
ll r;
node st[800005];
node a[200005];
node merge(node c,node d)
{
    node res;
    res.w=((c.w*d.w)+(c.x*d.y))%r;
    res.x=((c.w*d.x)+(c.x*d.z))%r;
    res.y=((c.y*d.w)+(c.z*d.y))%r;
    res.z=((c.y*d.x)+(c.z*d.z))%r;
    return res;
}

void build(ll si,ll ss,ll se)
{
    if(ss==se)
    {
        st[si].w=a[ss].w;
        st[si].x=a[ss].x;
        st[si].y=a[ss].y;
        st[si].z=a[ss].z;
        return;
    }
    ll mid=(ss+se)/2;
    build(2*si,ss,mid);
    build(2*si+1,mid+1,se);
    st[si]=merge(st[2*si],st[2*si+1]);
}
node query(ll si,ll ss,ll se,ll qs,ll qe)
{

    if(qs>se || ss>qe)
    {
        return {1,0,0,1}; //identity element
    }
    else if(ss>=qs && qe>=se)
    {
        return st[si];
    }
    ll mid=(ss+se)/2;
    node l=query(2*si,ss,mid,qs,qe);
    node r=query(2*si+1,mid+1,se,qs,qe);
    return merge(l,r);
}




int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    t=1;
    // cin>>t;
    while(t--)
    {
        ll n,q;
        cin>>r>>n>>q;
        F(i,1,n+1)
        {
            cin>>a[i].w>>a[i].x>>a[i].y>>a[i].z;
        }
        ll xa,yb;
        build(1,1,n);
        while(q--)
        {
            cin>>xa>>yb;
            cout<<query(1,1,n,xa,yb).w<<" "<<query(1,1,n,xa,yb).x<<"\n";
            cout<<query(1,1,n,xa,yb).y<<" "<<query(1,1,n,xa,yb).z<<"\n";
            cout<<"\n";

        }
    }




    return 0;

}

/// TLE CODE ON TEST 13

#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#include <vector>
#include<iostream>
#define Int long long
using namespace std;

vector< vector<Int> > Ans;
Int MOD , n , m;


class SegTree {
private:
	vector< vector<Int> > Identity ;
	vector< vector< vector<Int> > > Seg;

	inline Int MulMod(Int a , Int b) {
		return (a * b) % MOD;
	}

	inline Int add(Int a, Int b)
	{
	    return (a + b) % MOD;
	}
	inline vector<vector<Int>> Compain(vector< vector< Int > > a, vector< vector< Int > > b) {
	     vector< vector< Int > > Res(2, vector<Int> (2, 0));
		for (int i = 0 ; i < 2 ; i++){
			for (int j = 0 ; j < 2 ; j++) {
				for (int k = 0 ; k < 2 ; k++) {
					Res[i][j] = add(Res[i][j] ,  MulMod(a[i][k] , b[k][j]));
				}
			}
		}

        return Res;
	}

	inline void DoIdentity () {
		Identity.assign(2 , vector< Int >(2 , 0));
		for (int i = 0 ; i < 2 ; i++)
			Identity[i][i] = 1;
	}

	inline void UPD(int i , vector< vector< Int > > &v , int p , int L , int R) {
		if ( i >  R || i <  L ) return;
		if ( L == R ) {
			Seg[p] = v;
			return;
		}

		int Mid = (L + R) >> 1;
        UPD(i , v , 2 * p , L , Mid);
        UPD(i , v , 2 * p + 1 , Mid + 1 , R);
		Seg[p] = Compain(Seg[2 * p] , Seg[2 * p + 1]);
	}

  inline vector<vector<Int>> QRY(int i , int j , int p , int L , int R) {
		if ( i >  R || L >  j ) return {{1, 0}, {0, 1}};
		if ( i <= L && R <= j ) {
			return Seg[p];
		}
		int Mid = (L + R) >> 1;
		return Compain(QRY(i , j , 2 * p , L , Mid), QRY(i , j , 2 * p + 1 , Mid + 1 , R));
	}

public:
	SegTree(int n) {
		DoIdentity();
		Seg.assign(4 * n , Identity );
	}
	inline void UPD(int i , vector< vector< Int > > &v) {
		UPD(i , v , 1 , 1 , n);
	}
	inline void QRY(int L , int R) {
		Ans = QRY(L , R , 1 , 1 , n);
	}
};

int main() {
	scanf("%lld %lld %lld", &MOD, &n, &m);
	SegTree ST(n);

	vector< vector< Int > > V(2 , vector< Int >(2));
	for (int idx = 1 ; idx <= n ; idx++) {
		for (int i = 0 ; i < 2 ; i++)
			for (int j = 0 ; j < 2 ; j++)
				scanf("%lld",&V[i][j]);
		ST.UPD(idx , V);
	}
	int L , R, i;

	while ( m-- ) {
		scanf("%d %d", &L, &R);
		ST.QRY(L , R);

		for (i = 0 ; i < 2 ; i++) {
			for (int j = 0 ; j < 2 ; j++)
				printf("%lld ", Ans[i][j]);
			puts("");
		}
		puts("");
	}
}
