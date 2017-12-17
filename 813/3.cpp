
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

#define N 200005

vector<vector<int> >v;
int vis[N];
int vis2[N];
map<int,int>mp1;
map<int,int>mp2;
std::map<int,int>::iterator it1;
std::map<int,int>::iterator it2;

void dfs(int start,int cnt){
	vis[start]=1;
	cnt++;
	for(int i=0;i<v[start].size();i++){
		if(vis[v[start][i]]!=1){	
			//trace3(v[start][i],start,i);
		//	mp1.insert(pair<int,int>(v[start][i],cnt));

			dfs(v[start][i],cnt);
		}
		if(v[v[start][i]].size()==1){
			mp1.insert(pair<int,int>(v[start][i],cnt));
		}
		
	}

}

void dfs2(int start,int cnt){
	vis2[start]=1;
	cnt++;
	for(int i=0;i<v[start].size();i++){
		if(vis2[v[start][i]]!=1){	
			//trace3(v[start][i],start,i);
		//	mp1.insert(pair<int,int>(v[start][i],cnt));

			dfs(v[start][i],cnt);
		}
		if(v[v[start][i]].size()==1){
			mp2.insert(pair<int,int>(v[start][i],cnt));
		}
		
	}

}

int main(){
	lli n,x;
	cin >> n >> x;
	v.resize(n+1);
	loop(i,0,n-1){
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		vis[i]=0;
		vis[i+1]=0;
		vis2[i]=0;
		vis2[i+1]=0;
	}
	
	dfs(1,0);
	dfs2(x,0);
	//dfs(x,0);
	int maxi=0;int dist=0;
	for(it2=mp2.begin();it2!=mp2.end();it2++){
		trace2(it2->first,it2->second);
		/*if(mp2.count(it1->first)!=0){
			int dist=mp2[it1->first]-mp1[it1->first];
			if(dist>maxi){
				maxi=dist;
			}
			trace1(dist);
		}*/
	}
	cout << maxi << endl;
	return 0;
}