
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
	lli n,m ;
	cin >> n >> m;
	vector<vector<int> >v;
	v.resize(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int k;
			cin >> k;
			v[i].push_back(k);
		}
	}
	int cnt1=0;int cnt2=0;lli sum=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(v[i][j]==1){
				cnt1++;
			}
			else{
				cnt2++;
			}
		}
		sum += pow(2, cnt1);
		sum-=1;
		sum += pow(2, cnt2);
		sum-=1;
		cnt1=0;cnt2=0;
		//trace1(sum);
	}

	cnt1=0;cnt2=0;
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
			if(v[i][j]==1){
				cnt1++;
			}
			else{
				cnt2++;
			}
		}
		sum += pow(2, cnt1);
		sum-=1;
		sum += pow(2, cnt2);
		sum-=1;
		cnt1=0;cnt2=0;
		//trace1(sum);
	}
	sum = sum - (n*m);

	cout << sum << endl;
	return 0;
}