
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
	lli n,L,k;vector<lli> vec1;vector<lli>vec2;vector<lli>v1,v2;
	cin >> n >> L;
	for(int i=0;i<n;i++){
		cin >> k;
		v1.PB(k);
	}
	for(int i=0;i<n;i++){
		cin >> k;
		v2.PB(k);
	}
	for(int i=0;i<n;i++){
		//cin >> k;
		if(i==0){
			vec1.PB(v1[i]);
		}
		else{
			vec1.PB(v1[i]-v1[i-1]);
		}
	}
	vec1[0]=L-v1[n-1]+v1[0];
	for(int i=0;i<n;i++){
		//cin >> k;
		if(i==0){
			vec2.PB(v2[i]);
		}
		else{
			vec2.PB(v2[i]-v2[i-1]);
		}
	}
	vec2[0]=L-v2[n-1]+v2[0];
	/*for(int i=0;i<n;i++){
		trace2(vec1[i],vec2[i]);
	}*/
	sort(vec1.begin(),vec1.end());
	sort(vec2.begin(),vec2.end());
	for(int i=0;i<n;i++){
		if(vec1[i]!=vec2[i]){
			cout << "NO"<< endl;
			return 0;
		}
	}
	cout << "YES"<< endl;
	return 0;


}