
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


vector<string>v;
lli n,m;
lli x,y;
int check(){
	//trace4(x,y,n,m);
	if(x>=n || y>=m || x<0 || y<0)return 0;
	else if(v[x][y]=='#')return 0;
	else if(v[x][y]=='E')return 2;
	else return 1;
}
int get_direction(int g){
	if(g==0){
		x=x-1;
	}
	else if(g==1)y=y+1;
	else if(g==2)x=x+1;
	else y=y-1;
}

int main(){

	cin >> n >> m;
	int o_x;int o_y;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		v.push_back(s);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(v[i][j]=='S'){
				x=i;y=j;
				o_x=x;o_y=y;break;
			}
		}
	}
	//trace2(x,y);
	string t;cin >> t;int cnt=0;
	//trace1(t);
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(j==i)continue;
			for(int k=0;k<4;k++){
				if(k==i || k==j)continue;
				for(int l=0;l<4;l++){
					if(l==i||l==j||l==k)continue;
					else{
						x=o_x;y=o_y;int ans=-1;
						//trace4(i,j,k,l);
						//if(i==2&&j==3&&k==0&&l==1)
						for(int b=0;b<t.size();b++){
							if(t[b]=='0'){
								get_direction(i);
								ans=check();
								if(ans==0 || ans==2)break;
								//if(ans==1)trace1(ans);
							}
							else if(t[b]=='1'){
								get_direction(j);
								ans=check();
								if(ans==0|| ans==2)break;
								//if(ans==1)trace1(ans);
							}
							else if(t[b]=='2'){
								get_direction(k);
								ans=check();
								if(ans==0|| ans==2)break;
								//if(ans==1)trace1(ans);
							}
							else if(t[b]=='3'){
								get_direction(l);
								ans=check();

								if(ans==0|| ans==2)break;
								//if(ans==1)trace1(ans);
							}
							/*if(i==2&&j==3&&k==0&&l==1){
								trace3(ans,x,y);
								trace1(v[x][y]);
							}*/

						}
						//trace1(ans);
						if(ans==2)cnt++;


					}
				}
			}
		}
	}
	cout<< cnt << endl;
	return 0;
}