
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
	lli n,k;vector<int>vec,vec2;
	cin >> n;
	loop(i,0,n){
		cin >> k;
		vec.PB(k);
	}
	lli q;
	cin >> q;
	loop(i,0,q){
		cin >>k;
		vec2.PB(k);
	}
	lli sum =0;int ptr = 0;int maxi=0;
	lli index=0;
	loop(i,0,n){
		if(sum < vec2[ptr]){
			sum = sum + vec[i];
			if(maxi>vec[i]){
				maxi=vec[i];
				index=i;
			}
		}
		else if(sum == vec2[ptr]){
			sum = 0;
			int cnt = i;
			while(cnt){
				if(index!=0 && vec[index-1]<vec[index]){
					vec[index]+=vec[index-1];
					cout << "LEFT" << " " << index+1 << endl;
					for(int i=index;i<n;i++){
						vec[i-1]=vec[i];
					}
					
				}
				else if(index!=i-1 && vec[index+1]<vec[index]){
					vec[index]+=vec[index+1];
					cout << "RIGHT" << " " << index+1<< endl;
					for(int i=index+1;i<n;i++){
						vec[i-1]=vec[i];
					}
				}
				if(vec[index-1]==vec2[ptr]){
					break;
				}
			}
			ptr++;

		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
	
}