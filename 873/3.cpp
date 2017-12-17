
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
	lli n, m,k;
	cin >> n >> m >> k;
	vector<vector<int > > vec;
	vector<vector<int> >vec1;
	vec.resize(n+3);
	vec1.resize(n+3);
	int tot,cost,mini;mini=INT_MIN;int mini_cost=INT_MIN;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int a;
			cin >> a;
			vec1[i].push_back(a);
		}	
	}

	for(int i=0;i<=n;i++){
		for(int j=0;j<m;j++){
			vec[i].push_back(0);

		}
		
	}
	lli ans,ans2;ans=0;ans2=0;
	for(int j=0;j<m;j++){
		for(int i=0;i<=n;i++){
			if(i==0){
				vec[i][j]=0;
			}
			else{
				vec[i][j]=vec[i-1][j]+vec1[i-1][j];
			}

		}
		tot=0;cost=0;map<int,int>mp;mini=INT_MIN;//ans=0;ans2=0;
		for(int i=1;i<=n;i++){
			if(vec1[i-1][j]==1){
				tot = (vec[i+min(n-i+1, k)-1][j]-vec[i-1][j]);
				//if(mp.find(cost)==mp.end()){
				//mp.insert(make_pair(cost,tot));
				//cost++;
				if(tot>mini){
					mini=tot;
					mini_cost=cost;
				}
				//trace4(j,i,tot, cost);
				cost++;
			}
			
			
		}
		if(mini==INT_MIN){
			continue;
		}
		ans+=mini;ans2+=mini_cost;
		//trace2(ans,ans2);
		
	}
	cout << ans << " " << ans2 << endl;
	return 0;
}