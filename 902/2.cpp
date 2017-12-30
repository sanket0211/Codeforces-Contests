
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
	vector<vector<int> >v;
	lli n;cin >> n;
	v.resize(n+1);vector<int>c;
	for(int i=2;i<=n;i++){
		lli k;cin >> k;
		v[i].push_back(k);
		v[k].push_back(i);
	}
	for(int i=0;i<n;i++){
		lli k;
		cin >> k;
		c.push_back(k);
	}
	queue<pair<int,int> >q;
	lli cnt=0;
	int vis[1000005]={0};
	q.push(make_pair(1,0));
	while(!q.empty()){
		pair<int,int>node=q.front();
		q.pop();
		int col=node.S;int ver=node.F;
		vis[ver]=1;
		//trace2(col,ver)
		if(col!=c[ver-1]){
			cnt++;
			
		}
		for(int i=0;i<v[ver].size();i++){
			if(vis[v[ver][i]]==0)
			q.push(make_pair(v[ver][i],c[ver-1]));
		}
		/*else{
			for(int i=0;i<v[ver].size();i++){
				if(vis[v[ver][i]]==0)
				q.push(make_pair(v[ver][i],0));
			}
		}*/

	}
	cout << cnt << endl;
	return 0;
}