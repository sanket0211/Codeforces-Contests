
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
	lli n, k;vector< pair<lli, lli> > vec;vector< lli > v1,v2;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		int m,n;
		cin >> m >> n;
		
		v1.PB(m);
		v2.PB(n);
		if((2*m)>n){
			vec.PB(make_pair(n-m,i));

		}
		else{
			vec.PB(make_pair(2*m-m,i));
		}
	}
	sort(vec.begin(), vec.end());

	/*for(int i=0;i<n;i++){
		trace2(vec[i].first,vec[i].second);
	}*/
	for(int i=0;i<k;i++){
		v1[vec[vec.size()-1-i].second]*=2;
	}
	/*for(int i=0;i<n;i++){
		trace2(v1[i], v2[i]);
	}*/
	lli sum=0;
	for(int i=0;i<n;i++){
		if(v1[i]<=v2[i]){
			sum+=v1[i];
		}
		else{
			sum+=v2[i];
		}
	}
	cout << sum << endl;
	return 0;
}