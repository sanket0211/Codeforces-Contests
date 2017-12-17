
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
	lli n;vector<int> v;map<int,int>mp;
	cin >> n;
	loop(i,0,n){
		int k;
		cin >> k;
		v.push_back(k);
		if(mp.count(k)==0){
			mp.insert(pair<int,int>(k,1));
		}
		else{
			mp[k]++;
		}
	}
	sort(v.begin(),v.end());
	lli minsum=v[0]*v[1]*v[2];
	//cout << mp[v[0]]*mp[v[1]]*mp[v[2]] << endl;
	if(v[0]==v[1] && v[1]==v[2]){
		lli tot = mp[v[0]];
		cout << (tot*(tot-1)*(tot-2))/6 << endl;
	}
	else if(v[0]==v[1]){
		lli tot1=mp[v[0]];
		lli tot2=mp[v[2]];
		cout << ((tot1*(tot1-1))*tot2)/2 << endl;
	}
	else if(v[1]==v[2]){
		lli tot1=mp[v[1]];
		lli tot2=mp[v[0]];
		cout << ((tot1*(tot1-1))*tot2)/2 << endl;
	}
	else if(v[0]==v[2]){
		lli tot1=mp[v[0]];
		lli tot2=mp[v[1]];
		cout << ((tot1*(tot1-1))*tot2)/2 << endl;
	}
	else{
		cout << mp[v[0]]*mp[v[1]]*mp[v[2]] << endl;
	}
	return 0;
}