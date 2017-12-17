
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
#define bitcount1(n) __builtin_popcount1(n)
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

int vis[1000006];
vector<vector<int> >vec;
vector<int>val;vector<int>tree;
int a,b,cnt=0,sum=0,count1=0,root;
void dfs(int start){
	vis[start]=1;
	//trace1(start);
	//trace1(vec[start][0])
	tree[start]=val[start];
	if(vec[start].size()!=0)
	for(int i=0;i<vec[start].size();i++){
		//trace1(vec[start][i])
		if(vis[vec[start][i]]==0){
			vis[vec[start][i]]=1;
			dfs(vec[start][i]);
			tree[start]+=tree[vec[start][i]];
		}
		//trace2(start,tree[start]);
		if(cnt<2 && tree[start]==count1/3 && start!=root){
			
			if(cnt==1)a=vec[start][i];
			else b=vec[start][i];
			sum=0;cnt++;
			tree[start]=0;
			//trace2(a,b);
		}
	}
}

int main(){
	lli n;
	cin >> n;
	vec.resize(n+1);

	for(int i=0;i<=n;i++){
		vis[i]=0;
		val.PB(0);
		tree.PB(0);
	}
	for(int i=1;i<=n;i++){
		cin >> a >> b;
		if(a==0){
			root=i;
			val[i]=b;
			count1+=b;
			continue;
		}
		vec[a].PB(i);
		//vec[i].PB(a);
		val[i]=b;
		count1+=b;
		//trace1(count1);
	}
	if(count1%3!=0){
		cout << "-1" << endl;
		return 0;
	}
	else{
		dfs(root);
		cout << a << " " << b << endl;
	}
	return 0;


}