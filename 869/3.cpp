
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

#define MOD 998244353

lli ini[5003];
vector<lli>fact;
lli po(lli x,lli y) 
{
        if(x==0) return 1;
        lli z = po(x/2,y);
        z = (z*z)%MOD;
        if(x&1) z = (z*y)%MOD;
        return z;
}

unsigned long long int nChoosek( unsigned long long int n, unsigned long long int k )
{
    lli result=fact[n]%MOD;
    lli result1=1;
    for(int i=0;i<=k;i++){
    	result1 = result1*(ini[i]);
    	result1=result1%MOD;
    }
    lli r2=1;
    for(int i=0;i<=(n-k);i++){
    	r2 = r2*(ini[i]);
    	r2=r2%MOD;
    }
    result = (((result%MOD*(result1%MOD))%MOD)*(r2%MOD))%MOD;

    return result%MOD;
}


int main(){

	//cout << MOD << endl;
	
	fact.push_back(1);
	fact.push_back(1);
	ini[0]=1;
	for(int i=1;i<=5003;i++)
		ini[i] = po(MOD-2,i);
	for(lli i=2;i<=5005;i++){
		fact.push_back( ((fact[i-1]%MOD)*(i%MOD))%MOD );
	}


	lli a,b,c;
	cin >> a >> b >> c;
	lli tot = 0;

	for(lli i=0;i<=min(a,b);i++){
		tot = tot%MOD + ((((nChoosek(a,i)%MOD)*(nChoosek(b,i)%MOD))%MOD)*(fact[i]%MOD))%MOD;
		tot = tot%MOD;
	}
	//trace1(tot);
	lli tot2 = 0;
	for(lli i=0;i<=min(b,c);i++){
		tot2 = tot2%MOD + ((((nChoosek(b,i)%MOD)*(nChoosek(c,i)%MOD))%MOD)*(fact[i]%MOD))%MOD;
		tot2 = tot2%MOD;
	}
	//trace1(tot2);
	lli tot3 = 0;
	for(lli i=0;i<=min(a,c);i++){
		tot3 = tot3%MOD + ((((nChoosek(a,i)%MOD)*(nChoosek(c,i)%MOD))%MOD)*(fact[i]%MOD))%MOD;
		tot3 = tot3%MOD;
	}
	//trace1(tot3);
	tot = ((((tot%MOD)*(tot2%MOD))%MOD)*tot3%MOD)%MOD;
	tot = tot%MOD;
	cout << tot << endl;
	return 0;
}