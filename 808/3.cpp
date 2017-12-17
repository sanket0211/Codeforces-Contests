
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
	lli n, w;vector< pair<int,int> >vec,vec2;vector<int>v;
	cin >> n >> w; 
	loop(i,0,n){
		int a;
		cin >> a;
		vec.PB(MP(a,i));
		vec2.PB(MP(i,a));
		v.PB(a);
		
	}
	for(int i=0;i<n;i++){
		if(vec[i].F%2==0){
			w=w-vec[i].F/2;
			vec[i].F=vec[i].F/2;
			vec2[i].S=vec2[i].S/2;
		}
		else{
			w=w-vec[i].F/2-1;
			vec[i].F = vec[i].F/2+1;
			vec2[i].S = vec2[i].S/2+1;
		}
	//trace1(w);

	}
	if(w<0){
		cout << "-1" << endl;
	}
	else{
		sort(v.begin(), v.end());
		sort(vec.begin(), vec.end());
		for(int i=0;i<n;i++){
			trace4(vec[i].F, vec[i].S, vec2[i].F, vec2[i].S);
		}
		int i=0;
		while(w>0){
			w = w - (v[v.size()-i-1]-vec[vec.size()-i-1].F);
			vec2[vec[vec.size()-1].S].S += (v[v.size()-i-1]-vec[vec.size()-i-1].F);
			vec[vec.size()-i-1].F += (v[v.size()-i-1]-vec[vec.size()-i-1].F);
			trace1(w);
			if(w<0){
				vec2[vec[vec.size()-1].S].S += w;
				vec[vec.size()-i-1].F += w;
				w=0;
			}
			i++;

		}
		sort(vec2.begin(),vec2.end());
		for(int i=0;i<n;i++){
			cout << vec2[i].S << " ";
		}
		cout << endl;
	}
	return 0;

}