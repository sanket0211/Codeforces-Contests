
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
	lli sum = 1;
	vector<lli>ans;
	cin >> n;lli sum2=0;
		for(int a=0;a<=9;a++){
			for(int b=0;b<=9;b++){
				for(int c=0;c<=9;c++){
					for(int d=0;d<=9;d++){
						for(int e=0;e<=9;e++){
							for(int f=0;f<=9;f++){
								for(int g=0;g<=9;g++){
									for(int h=0;h<=9;h++){
										for(int i=0;i<=9;i++){
											sum = (100000001*a + 10000001*b + 1000001*c + 100001*d + 10001*e + 1001*f + 101*g + 11*h + 2*i);
											sum2 = (100000000*a + 10000000*b + 1000000*c + 100000*d + 10000*e + 1000*f + 100*g + 10*h + 1*i);
											if( sum == n){
												//cnt++;
												sum = (100000000*a + 10000000*b + 1000000*c + 100000*d + 10000*e + 1000*f + 100*g + 10*h + 1*i);
												ans.push_back(sum);
											}
											if(sum2>n)break;
										}
										if(sum2>n)break;
									}
									if(sum2>n)break;
								}
								if(sum2>n)break;
							}
							if(sum2>n)break;
						}
						if(sum2>n)break;
					}
					if(sum2>n)break;
				}
				if(sum2>n)break;
			}
		}
		cout << ans.size() << endl;
		for(int i=0;i<ans.size();i++){
			cout << ans[i] << " ";
		}
		cout << endl;
		return 0;
	
}