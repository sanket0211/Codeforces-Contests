
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
	lli n,k,a,b;map<lli,int>mp,c;vi v;
	cin >> n>>a>>b;
	loop(i,0,n){
		cin >> k;
		v.PB(k);
		mp.insert(pair<lli,int>(k,2));
		if(c.count(k)==0){
			c.insert(pair<lli,int>(k,1));
		}
		else{
			c[k]++;
		}
	}
	loop(i,0,n){
		//trace1(mp[a-v[i]]);
		trace4(mp[v[i]], mp[a-v[i]], c[v[i]], c[a-v[i]]);
		if(mp[a-v[i]]==2 && c[a-v[i]]>0 && c[v[i]]>0){
			mp[v[i]]=0;mp[a-v[i]]=0;c[v[i]]--;c[a-v[i]]--;
		}
		else if(mp[b-v[i]]==2 && c[b-v[i]]>0 && c[v[i]]>0){
			mp[v[i]]=1;mp[b-v[i]]=1;c[v[i]]--;c[b-v[i]]--;
		}
		else if((c.count(a-v[i])==0 && c.count(b-v[i])==0) || (c[a-v[i]]==0&&c.count(a-v[i])!=0) || (c[b-v[i]]==0&&c.count(b-v[i])!=0)){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	loop(i,0,n){
		cout << mp[v[i]] << " ";
	}
	cout << endl;
	return 0;


}