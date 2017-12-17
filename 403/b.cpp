
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
	lli n;vector< pair <int , int> >vec;vector<int>cord; vector<int>vel;
	int k;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> k;
		cord.PB(k);
	}
	for(int i=0;i<n;i++){
		cin >> k;
		vel.PB(k);
	}
	for(int i=0;i<n;i++){
		vec.PB(MP(cord[i],vel[i]));
	}
	sort(vec.begin(),vec.end());
	for(int i=1;i<n;i++){
		double meet = (double)((vec[i-1].second*vec[i].first)+(vec[i].second*vec[i-1].first))/(vec[i].second+vec[i-1].second);
		double time = (meet - vec[i-1].first)/vec[i-1].second;
		double time1 = (meet-vec[0].first)/vec[0].second;
		double time2 = (vec[n-1].first - meet)/vec[n-1].second;
		trace4(vec[i-1].first, vec[i].first,vec[i-1].second,vec[i].second);
		trace4(meet,time,time1,time2);
		if(time1<= time && time2 <=time){
			cout << time << endl;
			break;
		}
	}
	return 0;
}
