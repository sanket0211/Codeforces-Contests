
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
const int N = int(1e4)+10;
set<string> S;
bool dp[2][N];
vector<vector<int> > vec;
int vis[1000004],cat,counter;
int cats[2000005];
void dfs(int v,int cc,int max){
	vis[v]=1;
	if(cats[v]==1){
		cc++;
	}
	if(cc>=max){
		max=cc;
	}
	if(cats[v]==0){
		cc=0;
	}
	//cout << v << endl;
	for(int i=0;i<vec[v].size();i++){
		//cout << vec[v].size()<< " " << v << endl;
		if(vis[vec[v][i]]!=1)
			dfs(vec[v][i],cc,max);
	}
	cout << v << " " << max << " " << cat << endl;
	if(max<=cat){
		counter++;
	}
}

int main(){ 
	int n,e,v1,v2,cc=0,max=0;
	cin >>  n >> cat;
	counter=0;
	vec.resize(n+4);
	e=n-1;
	for(int i=0;i<=n;i++){
		vis[i]=0;
	}
	for(int i=1;i<=n;i++){
		cin >> cats[i];
	}
	for(int i=0;i<e;i++){
		cin >>v1 >> v2;
		vec[v1].PB(v2);
		
		
		
	}	
	dfs(1,cc,max);
	cout << counter << endl;
	return 0;
}



