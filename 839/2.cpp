
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
	lli n,k;
	cin >> n >> k;
	vector<int>vec;
	for(int i=0;i<k;i++){
		int a;
		cin >> a;
		vec.push_back(a);
	}
	int g4=0;int g2=0;int g1=0;
	for(int i=0;i<k;i++){
		g4=g4+vec[i]/4;
		vec[i]=vec[i]%4;
		g2=g2+vec[i]/2;
		vec[i]=vec[i]%2;
		g1=g1+vec[i]/1;
		vec[i]=0;
	}
	int actg4=n;int actg2=n*2;
	trace4(g2,g4,actg2,actg4);
	if(g4>actg4){
		
		g4=g4-actg4;
		actg4=0;
		g2=g2 + g4*2;
		g2=g2+g1;
		if(actg2>=g2){
			cout << "YES"<< endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	else if(g4<=actg4){
		actg4=actg4-g4;
		if(g1>=actg4){
			g1=g1-actg4;
		}
		else{
			g1=0;
		}
		//g1=g1-actg4;
		actg2=actg2+actg4;
		g2=g2+g1;
		if(g2<=actg2){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	/*else if(g2>actg2){
		cout << "NO" << endl;
	}
	else if(g2<=actg2){
		actg2=actg2-g2;
		actg2=actg2/2;
		g4=g4-actg2;
		if(g4<=actg4){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}*/
	return 0;

}