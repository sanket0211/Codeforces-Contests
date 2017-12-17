
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

int vec[5001][5001];
int dp[5001][5001];

int main(){
	string str;
	cin >> str;
	
	/*for(int i=0;i<=str.size();i++){
		for(int j=0;j<=str.size();j++){
			vec[i][j]=0;
			dp[i][j]=0;
		}
	}*/
	memset(vec, 0, sizeof(vec[0][0]) * str.size()+1 * str.size()+1);
	memset(dp, 0, sizeof(dp[0][0]) * str.size()+1 * str.size()+1);

	for(int i=0;i<str.size();i++){
		vec[i][i]=1;
		dp[i][i]=1;
	}
	for(int j=1;j<=str.size();j++){
		for(int i=0;(i+j-1)<str.size();i++){
			
			if((i+j)>str.size()){
				break;
			}
			if(j<3){
				vec[i][i+j-1] = (str[i]==str[i+j-1]);
				continue;
			}
			vec[i][i+j-1] = vec[i+1][i+j-2] &  (str[i]==str[i+j-1]);
			//trace3(vec[i][i+j-1], i,i+j-1);
		}

	}
	/*for(int i=0;i<str.size();i++){
		for(int j=0;j<str.size();j++){
			trace3(vec[i][j],i,j);
		}
	}*/
	for(int j=1;j<=str.size();j++){
		for(int i=0;(i+j-1)<str.size();i++){
			if((i+j)>str.size()){
				//trace2(i,j);
				break;
			}
			if(j>2){
				dp[i][i+j-1] = dp[i+1][i+j-1] + dp[i][i+j-2] - dp[i+1][i+j-2] + vec[i][i+j-1];
			}
			else if(j>1){
				dp[i][i+j-1] = dp[i+1][i+j-1] + dp[i][i+j-2] + vec[i][i+j-1];
			}
			else{
				dp[i][i+j-1] = vec[i][i+j-1];
			}
			//trace3(dp[i][i+j-1],i,i+j-1);
		}
	}
	/*for(int i=0;i<str.size();i++){
		for(int j=0;j<str.size();j++){
			trace3(dp[i][j],i,j);
		}
	}*/
	int q;
	cin >> q;
	//vec.clear();
	int a,b;vector <pair <int , int> >vp;
	for(int i=0;i<q;i++){
		cin >> a >> b;
		vp.PB(make_pair(a,b));
	}
	for(int i=0;i<q;i++){
		cout << dp[vp[i].first-1][vp[i].second-1] <<endl;
	}

	return 0;

}