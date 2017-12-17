
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

int main(){
	vector< pair< lli, pair<lli, lli> > >vec;
	lli n,k;vector<lli> a,b;int l;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> l;
		a.PB(l);
	}
	for(int i=0;i<n;i++){
		cin >> l;
		b.PB(l);
	}
	lli diff;
	for(int i=0;i<n;i++){
		//cin >> l;
		//a.PB(l);
		diff = a[i]-b[i];
		vec.PB(make_pair(diff, make_pair(a[i],b[i])));
	} 
	lli sum=0;
	sort(vec.begin(),vec.end());
	for(int i=0;i<n;i++){
		//trace3(vec[i].first,vec[i].second.first,vec[i].second.second);
	}
	for(int i=1;i<=n;i++){
		if(i<=k || vec[i-1].first<0){
			sum+=vec[i-1].second.first;
		}
		else{
			sum+=vec[i-1].second.second;
		}
	}
	cout << sum << endl;
	return 0;

}