
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

int n,m;
int a,b,c;
int st[400005];
int s[100005];
vector<pair<int,int> >V;
void build(int l,int r,int d){
	if(l==r)st[d]=s[l];
	else{
		int mid=l+r>>1;
		build(l,mid,d+d);
		build(mid+1,r,d+d+1);
		st[d]=__gcd(st[d+d],st[d+d+1]);
	}
}
int find(int l,int r,int d,int a,int b){
	if(r<a||b<l)return 0;
	if(a<=l&&r<=b)return st[d];
	int mid=l+r>>1;
	return __gcd(find(l,mid,d+d,a,b),find(mid+1,r,d+d+1,a,b));
}
int main(){
	scanf("%d",&n);
	V.clear();
	for(int i=1;i<=n;i++)scanf("%d",&s[i]),V.push_back(make_pair(s[i],i));
	build(1,n,1);
	for(int i=0;i<2*n;i++){
		trace2(st[i], i);
	}
	scanf("%d",&m);
	sort(V.begin(),V.end());
	while(m--){
		scanf("%d%d",&a,&b);
		c=find(1,n,1,a,b);
		printf("%d\n",b-a+1-(upper_bound(V.begin(),V.end(),make_pair(c,b))-lower_bound(V.begin(),V.end(),make_pair(c,a))));
	}
	return 0;
}