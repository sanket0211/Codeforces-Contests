
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
	lli n,k,sum=0,a;
	vector<int>vec;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> a;
		vec.PB(a);
	}
	if(k<=(n/2)){
		//cout << "1" << endl;
		int j=k-1;
		for(int i=k-1;i>=0;i--){
			if(vec[i]==vec[j] && j==k-1){
				sum=sum+vec[j];
			}
			else if(vec[i]==vec[j]){
				sum=sum+vec[j]+vec[i];
			}
		//	trace2(i,j);

			j++;
		}
		//j++;
		while(j<=vec.size()-1){
			sum=sum+vec[j];
			j++;
		//	trace2(j,sum);
		}

	}
	else {
		int j=k-1;
		//cout << "2" << endl;

		for(int i=k-1;i<=vec.size()-1;i++){
			if(vec[i]==vec[j] && j==k-1){
				sum=sum+vec[j];
			}
			else if(vec[i]==vec[j]){
				sum=sum+vec[j]+vec[i];
			}
			j--;
			//trace3(i,j,sum);
		}
		//j--;
		while(j>=0){
			sum=sum+vec[j];
			j--;
		}
	}
	cout << sum << endl;
}