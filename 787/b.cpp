
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
	lli n , m,flag;
	cin >> n >> m;
	vector<vector <int> >vec;
	vec.resize(m+1);
	for(int i=0;i<m;i++){
		int k;
		cin >> k;int flag=1;
		for(int j=0;j<k;j++){
			
			int m;
			cin >> m;
			//vec2[m]=1;
			
			vec[i].PB(m);
			//trace2(i,vec[i][j]);
		}
	}
	flag=1;
	for(int i=0;i<m;i++){
		sort(vec[i].begin(),vec[i].end());
		vector<int>vec2;
		for(int k=0;k<10006;k++){
			vec2.PB(0);
		}
		for(int j=0;j<vec[i].size();j++){
			if(vec[i][j]<0){
				vec[i][j]=vec[i][j]*-1;
				vec2[vec[i][j]]=1;
			}
			else{
				flag=1;
				if(vec2[vec[i][j]]==1){
					flag=0;
					break;
				}
			}
		}
		if(flag==1){
			cout << "YES"<< endl;
			return 0;
		}
		
	}

	if(flag==0){
		cout <<"NO"<< endl;
		return 0;
	}
	
	//cout << vec[0][1] << endl;
	return 0;
}