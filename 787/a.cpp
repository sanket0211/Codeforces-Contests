
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
	lli a,b,c,d,sum;
	cin >> a >> b;
	cin >> c >> d;
	vector<int>vec;
	vector<int>vec2;
	for(int i=0;i<100005;i++){
		vec.PB(0);
	}
	sum=0;int i=0;
	while(1){
		if((b-d+(i*a))>=0 && (b-d+(i*a))%c==0){
			cout << b-d+(i*a)+d << endl;
			return 0;
		}
		else if((b-d+(i*a))>=0 && vec[b-d+(i*a)]!=0){
			break;
		}
		if((b-c+(i*a))>=0){
			vec[b-c+(i*a)]=1;
		}
		if(b-d+i*a>19999){
			break;
		}
		i++;
	}
	for(int i=0;i<100005;i++){
		vec2.PB(0);
	}
	sum=0; i=0;
	while(1){
		if((d-b+(i*c))>=0 && (d-b+(i*c))%a==0){
			cout << c-b+(i*d)+b << endl;
			return 0;
		}
		else if((d-b+(i*d))>=0 && vec2[d-b+(i*c)]!=0){
			break;
		}
		if((d-b+(i*c))>=0){
			vec[d-b+(i*c)]=1;
		}
		if(d-b+i*c>19999){
			break;
		}
		i++;
	}
	cout << -1 << endl;
	return 0;
}