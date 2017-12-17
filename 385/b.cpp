
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
vector<int> sp;int vis[1002],sz[1005];
vector<int> vec[10003];
void dfs(int u,int v){
	sz[v]++;vis[u]=1;
	for(int i=0;i<vec[u].size();i++){
		//trace2(vec[u].size(),u);
		if(!vis[vec[u][i]]){
			dfs(vec[u][i],v);
		}
	}
}
int main(){
	lli n,k,m,l,h;
	cin >> n >> m >> k;
	for(int i=0;i<k;i++){
		cin >> l;
		sp.PB(l);
	}
	//vec.resize(n+1);

	for(int i=0;i<m;i++){
		cin >> l>>h;
		vec[l].PB(h);
		vec[h].PB(l);
	}
	int max=0,tot=0,mi=0,ans=0;
	for(int i=0;i<sp.size();i++){
		dfs(sp[i],i);
		if(sz[i]>max){
			max=sz[i];
			mi=i;
		}
		tot=tot+sz[i];
	}
	sz[mi]=sz[mi]+n-tot;
	//trace2(sz[mi],mi);
	for(int i = 0;i<k;i++){
		ans=ans+(sz[i]*(sz[i]-1))/2;
	}
	cout << ans -m << endl;
	//return 0;
	return 0;
}