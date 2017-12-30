
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

	double n,r;cin >> n >> r;
	vector<double>v2;
	r=r*2;
	vector<double>v;
	for(int i=0;i<n;i++){
		lli k;cin >> k;v.push_back(k);
	}
	for(int i=0;i<n;i++){
		if(i==0){
			//cout << r/2 << " ";
			printf("%.6lf ", r/2);
			v2.push_back(r/2);
			continue;
		}
		else{
			lli mn=-1;lli mny=INT_MIN;
			v2.push_back(-1.0000000);
			for(int j=i-1;j>=0;j--){
				if(  abs(v[i]-v[j])<=(r)  ){
					
					mn=j;
					mny=v2[j];
					

					double y1,y2;
					double  c = (v[i]-v[mn])*(v[i]-v[mn]);
					//trace1(c);
					if(c<=(r*r)){
						//trace3(sqrt( (r*r-c) ),r*r,v2[mn]);
						
						//cout << sqrt( (r*r-c) ) + v2[mn] << " ";
						//printf("%.6lf ",sqrt( (r*r-c) ) + v2[mn] );
						//trace1(sqrt( (r*r-c) ) + v2[mn]);
						if( (sqrt( (r*r-c) ) + v2[mn])>v2[i]  )
						v2[i]=sqrt( (r*r-c) ) + v2[mn];
					}
					else{
						//cout<< r+v[mn]<< " ";
						//printf("%.6lf ",r+v[mn] );
						if( v2[i]<r+v2[mn] )
						v2[i]=(r+v2[mn]);
					}
				}
				//trace3(v2[i],mn,i);
			}
			//

			if(mn==-1){
				printf("%.6lf ",r/2 );
				v2[i]=r/2;
				continue;
			}
			else{
				printf("%.6lf ",v2[i] );
			}
			//trace1(mn);
			
		}
	
	}
	cout << endl;
	return 0;
}