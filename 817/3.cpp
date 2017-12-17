
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

lli ms;

lli caldiff(lli a){
	lli b=a;int i=1;
	while(1){
		lli temp=b;
		a=b-b%((lli)pow(10,i));
		b=a;
		//trace2(a,b);
		lli sum=0;
		while(a>0){
			sum+=a%10;
			a=a/10;
		}
		lli diff=b-sum;
		i++;
		//cout << diff << endl;
		//trace3(diff,temp,a);
		//trace1(ms);
		if(diff==ms){
			return b;
		}
		else if(diff<ms){
			return temp;
		}
		//return temp;
		//break;
	}
}


int main(){
	lli n, s;
	cin >> n >> s;
	ms=s;
	lli sum=0;
	while(ms>0){
		sum+=ms%10;
		ms=ms/10;
	}
	ms=s;
	lli minsum=s-sum;
	lli tempsum=minsum;
	minsum=s-minsum;
	lli temp;
	//trace1(minsum);
	if(minsum%9==0){
		temp=minsum/9;
	}
	else{
		temp=(minsum/9)+1;
	}
	s=s+10*temp;
	//trace1(s);
	//while(1){

	s=caldiff(s);	
	
	//trace1(s);
	//trace1(s);
	//s=s-s%10;

	if((n-s+1)<0){
		cout << "0" << endl;
		return 0;
	}
	cout << n - s + 1 << endl;
	return 0;
}