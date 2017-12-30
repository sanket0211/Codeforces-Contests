
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
	lli n;cin >> n;int arr[26];int flag=0;int cnt=0;int ans=0;
	for(int i=0;i<26;i++){
		arr[i]=1;
	}
	for(int i=0;i<n;i++){
		string s,t;
		cin >> s >> t;
		if (i==n-1)continue;
		//trace2(ans,flag);
		//trace3(flag,s,t);
		for(int j=0;j<26;j++){
			if(arr[j]==1)cnt++;
		}
		//trace1(cnt);
		if(cnt==1){
			flag=1;
			
		}
		cnt=0;
		if(s[0]=='.' || s[0]=='?'){
			if(flag==1&&s[0]=='?'){
				ans++;continue;
			}
			for(int j=0;j<t.size();j++){
				arr[t[j]-'a']=-1;
			}
		}
		else if(s[0]=='!' ){
			if(flag==1&&s[0]=='!'){
				ans++;continue;
			}
			for(int j=0;j<t.size();j++){
				//trace1(arr[j]);
				if(arr[t[j]-'a']==1)
				arr[t[j]-'a']=2;
			}
			for(int j=0;j<26;j++){
				if(arr[j]==1)arr[j]=-1;
			}
			for(int j=0;j<26;j++){
				if(arr[j]==2){
					arr[j]=1;
					//trace1(j);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}