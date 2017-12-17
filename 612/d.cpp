
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
	lli n,k,a,b; vii vec,vec2;vvi ans;
	cin >> n >> k;
	ans.resize(2);
	loop(i,0,n){
		cin >> a >> b;
		vec.PB(MP(a,b));
		vec2.PB(MP(b,a));
	}
	sort(vec.begin(),vec.end());
	sort(vec2.begin(), vec2.end());
	lli ptr, ptr2;
	ptr=vec[0].F;ptr2=vec[0].S;
	int cnt=1;
	trace3(ptr,ptr2,cnt);
	loop(i,1,n){
		if(cnt==k){
			if(ans[1].size()!=0 && ptr<=ans[1][ans[1].size()-1]){
				if(ptr2>ans[1][ans[1].size()-1])
				ans[1][ans[1].size()-1]=ptr2;
			}
			else{
				ans[0].PB(ptr);
				ans[1].PB(ptr2);	
			}
			//trace4(ptr,ptr2,ans[0][ans[0].size()-1], ans[1][ans[1].size()-1]);
			cnt=1;ptr=vec[i-1].F;ptr2=vec[i-1].S;i--;
		}
		else{
			if(vec[i].F>ptr){
				ptr=vec[i].F;
			}
			if(vec[i].S<ptr2){
				ptr2=vec[i].S;
			}
			if(ptr>ptr2){
				cnt=1;ptr=vec[i].F;ptr2=vec[i].S;
			}
			else{
				cnt++;
			}
		}
		trace3(ptr,ptr2,cnt);
	}
	if(cnt==k){
		if(ans[1].size()!=0 && ptr<=ans[1][ans[1].size()-1]){
			if(ptr2>ans[1][ans[1].size()-1])
			ans[1][ans[1].size()-1]=ptr2;
		}
		else{
			ans[0].PB(ptr);
			ans[1].PB(ptr2);	
		}
		//cnt=1;ptr=vec[i-1].F;ptr2=vec[i-1].S;i--;
	}
	cnt==0;
	for(int i=n-1;i>=0;i--){

	}
	//trace2(ans.size(),ans[0].size());
	cout << ans[0].size() << endl;
	loop(i,0,ans[0].size()){
		cout<<ans[0][i] << " " << ans[1][i] << endl;
	}
	return 0;
}