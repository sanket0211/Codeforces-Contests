
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
	lli n,m;
	cin >> n >> m;
	vector<vector<int> >g;
	g.resize(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int k;
			cin >> k;
			g[i].push_back(k);
		}
	}
	vector<vector<int> >f;
	f=g;
	vector<int>row;int cnt=0;
	vector<int>col;
	int mini=INT_MAX;
	for(int i=0;i<n;i++){
		mini=INT_MAX;
		for(int j=0;j<m;j++){
			if(g[i][j]<mini){
				mini=g[i][j];
			}
		}
		for(int j=0;j<m;j++){
			
			g[i][j]-=mini;
		}
		row.push_back(mini);
		if(mini>0){
			cnt+=mini;
		}
		/*if(mini>0){
			cout << "row " << mini << endl;
		}*/
	}
	//trace1(cnt);
	for(int j=0;j<m;j++){
		mini=INT_MAX;
		for(int i=0;i<n;i++){
			if(g[i][j]<mini){
				mini=g[i][j];
			}
		}
		for(int i=0;i<n;i++){
			
			g[i][j]-=mini;
		}
		col.push_back(mini);
		if(mini>0){
			cnt+=mini;
		}
		/*if(mini>0){
			cout << "col " << mini << endl;
		}*/
	}

	vector<int>row1;int cnt1=0;
	vector<int>col1;
	mini=INT_MAX;
	
	//trace1(cnt);
	for(int j=0;j<m;j++){
		mini=INT_MAX;
		for(int i=0;i<n;i++){
			if(f[i][j]<mini){
				mini=f[i][j];
			}
		}
		for(int i=0;i<n;i++){
			
			f[i][j]-=mini;
		}
		col1.push_back(mini);
		if(mini>0){
			cnt1+=mini;
		}
		/*if(mini>0){
			cout << "col " << mini << endl;
		}*/
	}
	for(int i=0;i<n;i++){
		mini=INT_MAX;
		for(int j=0;j<m;j++){
			if(f[i][j]<mini){
				mini=f[i][j];
			}
		}
		for(int j=0;j<m;j++){
			
			f[i][j]-=mini;
		}
		row1.push_back(mini);
		if(mini>0){
			cnt1+=mini;
		}
		/*if(mini>0){
			cout << "row " << mini << endl;
		}*/
	}

	//trace2(cnt,cnt1);
	if(cnt<=cnt1){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(g[i][j]!=0){
				cout << "-1" << endl;
				return 0;
			}
		}
	}
	cout << cnt << endl;
	for(int i=0;i<row.size();i++){
		for(int j=0;j<row[i];j++){
			cout << "row " << i+1 << endl;
		}

	}
	for(int i=0;i<col.size();i++){
		for(int j=0;j<col[i];j++){
			cout << "col " << i+1 << endl;
		}
	}
	//cout << cnt << endl;
	return 0;
	}
	else{
		for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(f[i][j]!=0){
				cout << "-1" << endl;
				return 0;
			}
		}
	}
	cout << cnt1 << endl;
	for(int i=0;i<row1.size();i++){
		for(int j=0;j<row1[i];j++){
			cout << "row " << i+1 << endl;
		}

	}
	for(int i=0;i<col1.size();i++){
		for(int j=0;j<col1[i];j++){
			cout << "col " << i+1 << endl;
		}
	}
	//cout << cnt1 << endl;
	return 0;
	}
}