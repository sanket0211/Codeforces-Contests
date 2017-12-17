
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

int fits(int a,int b,int c,int d,int e,int f){
	if( (a+c)<= e && max(b,d)<=f){
		return 1;
	}
	else if( (a+d)<=e && max(b,c)<=f  ){
		return 1;
	}
	if( (a+c)<= f && max(b,d)<=e){
		return 1;
	}
	else if( (a+d)<=f && max(b,c)<=e  ){
		return 1;
	}
	else if( (b+c)<= e && max(a,d)<=f){
		return 1;
	}
	else if( (b+d)<=e && max(a,c)<=f  ){
		return 1;
	}
	else if( (b+c)<= f && max(a,d)<=e){
		return 1;
	}
	else if( (b+d)<=f && max(a,c)<=e  ){
		return 1;
	}
	

	return 0;
}



int main(){
	lli n,a,b;
	cin >> n >> a >> b;
	vector<pair<int,pair<int,int> > >v;
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		v.push_back(make_pair(x*y,make_pair(x,y)));
	}
	sort(v.begin(),v.end());
	int maxi=0;
	for(int i=n-1;i>=0;i--){
		for(int j=i-1;j>=0;j--){
			trace4(v[i].S.F,v[i].S.S,v[j].S.F,v[j].S.S);
			if(fits(v[i].S.F,v[i].S.S,v[j].S.F,v[j].S.S,a,b)){


				if( (v[i].F+v[j].F) >maxi ){
					maxi= (v[i].F+v[j].F);
				}
			}
		}
	}
	cout << maxi << endl;
	return 0;
}