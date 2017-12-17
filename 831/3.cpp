
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
	lli k, n;vector<int>f,s;
	cin >> k >> n;map<int,int>nr,r;
	for(int i=0;i<k;i++){
		int m;
		cin >> m;
		if(m==0){
			continue;
		}
		f.push_back(m);

	}
	for(int i=0;i<n;i++){
		int m;
		cin >> m;
		s.push_back(m);
		
			r.insert(make_pair(m,1));
		
		
	}
	/*for(int i=0;i<k;i++){
		if(i==0)continue;
		else{
			f[i]=f[i]+f[i-1];
		}
	}*/
	//sort(f.begin(),f.end());int ans=0;
	//sort(s.begin(),s.end());
	nr=r;int cnt=1;int ans=0;

	/*for(int i=0;i<f.size();i++){
		trace1(f[i]);
	}*/

	for(int i=f.size()-1;i>=0;i--){
		for(int l=0;l<n;l++){
			r=nr;cnt=1;int diff=s[l]-f[i];
			
			
			r.erase(s[l]);
			
			if(cnt==n){
				ans++;continue;;
			}
			//trace3(s[l],f[i],diff);
			for(int j=i-1;j>=0;j--){
				
				if(r.find(diff)!=r.end()){
					cnt++;
					
					r.erase(diff);
					
				
				}
				diff=diff-f[j];
				if(cnt==n){
					ans++;
					break;
				}
				/*trace1(r[diff]);
				trace3(diff,cnt,r[diff]);*/
			}
			if(cnt==n){
				//ans++;
				break;
			}
		}

	}
	cout << ans << endl;
	return 0;
}