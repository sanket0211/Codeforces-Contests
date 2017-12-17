
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
	string s;
	cin >> s;
	int hr=0;int revhr=0;
	for(int i=0;i<2;i++){
		hr=hr+ s[i] -48;
		hr=hr*10;
	//	trace1(hr);
	}
	hr=hr/10;
	for(int i=1;i>=0;i--){
		revhr=revhr+ s[i] -48;
		revhr=revhr*10;
	}
	revhr=revhr/10;
	int minu=0;
	
	for(int i=3;i<5;i++){
		minu+=s[i] -48;
		minu=minu*10;
	}
	minu=minu/10;
	if(minu==revhr){
		cout << '0' << endl;
		return 0;
	}
	//trace3(minu, hr, revhr);
	int ans=0;
	if(hr>=16 && hr<=19){
		cout << ((20-hr)*60) + ((62-minu)%60) << endl;
	}
	else if(hr>=7&& hr<=9){
		cout << (10-hr)*60 + ((61-minu)%60) << endl;
	}
	else if(minu<revhr) {
		cout << revhr-minu << endl;
	}
	else if(revhr<minu){
		if(hr==23){
			cout << (60-minu) << endl;
			return 0;
		}
		cout << (60-minu + revhr+10) << endl;
	}
	return 0;
}