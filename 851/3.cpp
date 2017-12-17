
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
	lli n;
	cin >> n;
	int a[n][n][5];
	vector<vector<int> >v;
	v.resize(n+1);
	for(int i=0;i<n;i++){
		int a1,b1,c1,d1,e1;
		cin >> a1 >> b1 >> c1 >> d1 >> e1;
		v[i].push_back(a1);
		v[i].push_back(b1);
		v[i].push_back(c1);
		v[i].push_back(d1);
		v[i].push_back(e1);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			a[j][i][0]=v[j][0]-v[i][0];
			a[j][i][1]=v[j][1]-v[i][1];
			a[j][i][2]=v[j][2]-v[i][2];
			a[j][i][3]=v[j][3]-v[i][3];
			a[j][i][4]=v[j][4]-v[i][4];
		}
	}

	
	lli cnt=0;vector<int>ans;int flag=0;
	for(int i=0;i<n-2;i++){
		flag=0;
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(i==j || i==k || j==k){
					continue;
				}
				double dot_pro=0,mod1=0,mod2=0;
				double tot = 0;
				for(int t=0;t<5;t++){
					dot_pro += a[j][i][t]*a[k][i][t];
				}
				for(int t=0;t<5;t++){
					mod1 += a[j][i][t]*a[j][i][t];
					mod2 += a[k][i][t]*a[k][i][t];
				}
				mod1 = sqrt(mod1);
				mod2 = sqrt(mod2);
				//trace3(dot_pro,mod1,mod2);
				//trace2(j,k);
				tot = (double)dot_pro / ((double)mod1*(double)mod2);
				//trace6(i,j,k, dot_pro, mod1, mod2);
				if(tot >0){
					//cnt++;
					
					//ans.push_back(i+1);
					flag=1;
					break;
				}
			}
			if(flag==1){
				break;
			}
		}
		//trace2(i,flag);
		if(flag==0){
			cnt++;
			
			ans.push_back(i+1);
			
		}

	}
	cout << cnt << endl;
	for(int i=0;i<ans.size();i++){
		cout << ans[i] << endl;
	}
	return 0;
}