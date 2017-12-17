
#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
#define bitcount(n) __builtin_popcount(n)
#define DRT()  int t; cin>>t; while(t--)
#define TRACE
#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#else
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#endif
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
lli modpow(lli a,lli n,lli temp){lli res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}

#define N 5005
int a[N],l[N],r[N], c[N],d[N],f[N],g[N];
int main(){
	lli n,k;
	loop(i,0,N)l[i]=0,r[i]=0,f[i]=0,g[i]=-1,d[i]=0;
	cin >> n;
	loop(i,1,n+1){
		cin >> k;
		a[i]=k;
		if(!l[k])l[k]=i;
		r[k]=i;
	}
	loop(i,1,n+1){
		loop(j,0,N)g[i]=-1;
		d[i]=r[a[i]];
		loop(j,i,d[i]+1){
			if(l[a[i]]<i)break;
			if(j==i)c[i]=a[j],g[a[j]]=1;
			d[i]=max(d[i],r[a[j]]);
			if(g[a[j]]==-1)g[a[j]]=1,c[i]^=a[j];
		}
	}
	loop(i,1,n+1)trace1(c[i]);
	for(int i=n;i>0;--i)f[i]=max(f[i+1],f[d[i]+1]+c[i]),trace4(f[i], f[i+1],d[i],f[d[i]+1]);
	cout << f[1] << endl;
	return 0;

}