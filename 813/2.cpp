
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
	lli x,y,l,tot=0,r;vector<long long int>v;
	cin >> x >> y >> l >>r;

	if(l==1&&r==1){
		cout << "1"<< endl;
		return 0;
	}
	
	else{
		/*int exp1=0;int exp2=0;
		while((pow(x,exp1)+pow(y,exp2))>=2 && (pow(x,exp1)+pow(y,exp2))<=r){
			exp2=0;
			//trace5(pow(x,exp1)+pow(y,exp2),x,y,exp1,exp2);
			while((pow(x,exp1)+pow(y,exp2))>=2 && (pow(x,exp1)+pow(y,exp2))<=r){
				if((pow(x,exp1)+pow(y,exp2))>=l && (pow(x,exp1)+pow(y,exp2))<=r)
				v.PB(pow(x,exp1)+pow(y,exp2));
			//	trace5(pow(x,exp1)+pow(y,exp2),x,y,exp1,exp2);
				exp2++;
			}			
			exp1++;
			exp2=0;
			//trace5(pow(x,exp1)+pow(y,exp2),x,y,exp1,exp2);
		}*/
		for(int i=0;i<=64;i++){
			for(int j=0;j<=64;j++){
				//lli num = pow(x,i)+pow(y,j);
				long long num =(long long)pow((double) x,i) + (long long)pow((double) y,j);
				if(num>r){
					break;
				}
				if(num>=l && num<=r){
					v.PB(num);
					trace3(num,i,j);
					tot++;
				}

			}
		}
	}
	long long int maxi=0;
	if(v.size()==0){
		//trace1(r-l+1);
		cout << r-l+1 << endl;
		return 0;
	}

	sort(v.begin(),v.end());
	/*for(int i=0;i<v.size();i++){
		trace2(v[i],i);
	}*/
	for(int i=1;i<v.size();i++){
		if(v[i]!=v[i-1]){
			long long int dist=v[i]-v[i-1]-1;
			if(dist>=maxi){
				maxi=dist;
			}
		}
	//	trace1(dist);
	}

	maxi = max(maxi,(v[0]-l));
	//trace3(maxi,r,l);
	maxi = max(maxi,r-v[v.size()-1]);
	trace3(maxi,r,v[v.size()-1]);

	cout << maxi << endl;
	//cout << tot << endl;
	return 0;
}


