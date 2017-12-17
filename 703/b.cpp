
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
	lli n, arr[5][100008],cap,sum,k,subk=0,beautysum=0,tempsum;
	cin >>n >> cap;
	sum=0;
	for(int i=0;i<n;i++){
		cin >> arr[0][i] ;
			beautysum+=arr[0][i];
		arr[1][i]=0;
		if(i>0){
			sum = sum + arr[0][i]*arr[0][i-1];
		//	trace1(sum);
		}
	}
	sum=sum+arr[0][n-1]*arr[0][0];
	//trace1(beautysum);
			//trace1(sum);
	for(int j=0;j<cap;j++){
		cin >> k;
		k=k-1;
		tempsum=beautysum;
		if(k==0){
			beautysum=beautysum-arr[0][k]-arr[0][k+1]-arr[0][n-1];
		}
		else if(k==n-1){
			beautysum=beautysum-arr[0][k]-arr[0][k-1]-arr[0][0];

		}
		else {
			beautysum=beautysum-arr[0][k]-arr[0][k+1]-arr[0][k-1];
		}
		sum=sum+arr[0][k]*beautysum;
		//trace2(sum,beautysum);
		beautysum=tempsum;
		beautysum=beautysum-arr[0][k];
		arr[0][k]=0;

		/*if(j!=0 && abs(subk-k)!=1 && abs(subk-k)!=n-1){
			sum=sum-arr[0][k]*arr[0][subk];
		}*/
		//trace1(k);
		

	}
	cout << sum << endl;
	return 0;
}