//Prashant Tyagi
using namespace std;
#include <bits/stdc++.h>
#define TRACE
#ifdef TRACE
#define TR(...) __f(#__VA_ARGS__, __VA_ARGS__)

#else
#define TR(...)
#endif
typedef  long long                     LL;
typedef  vector < int >                VI;
typedef  pair< int, int >              II;
typedef  vector < II >                 VII;
#define SI(x)                          scanf ("%d", &x)
#define SLL(x)                         scanf ("%lld", &x)
#define PI(x)                          printf ("%d\n", x)
#define PLL(x)                         printf ("%lld\n", x)
#define MOD                            98765431
#define PB                             push_back
#define MP                             make_pair
#define ALL(v)                         v.begin(), v.end()
#define VIF(x,V)                       for(int x:V)
#define FILL(a,b)                      memset(a,b,sizeof(a))
#define REP(i,j,n)                     for(int i=j;i<n;i++)
#define FLD(i,j,n)                     for(int i=n-1;i>=j;i--)
#define F                              first  
#define S                              second
#define fast_io                        ios_base::sync_with_stdio(false);cin.tie(NULL)
const int N=2e2+1;
char X[N][N];

int main ()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n,m;SI(n);SI(m);
	bool W[3];
	W[0]=W[1]=W[2]=false;
	REP(i,1,n+1)REP(j,1,m+1){
		cin>>X[i][j];
		if(X[i][j]=='R')W[0]=true;
		else if(X[i][j]=='G')W[1]=true;
		else W[2]=true;
	}
	REP(i,0,3){
		if(W[i]==false){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	bool flag1=true;
	bool flag2=true;
	if(m%3==0){
		for(int i=1;i<=m;i+=m/3){
			set<char> S;
			REP(j,1,n+1)REP(l,i,i+m/3){
				S.insert(X[j][l]);
			}
			if(S.size()>1)flag1=false;
		}
	}else flag1=false;
	if(n%3==0){
		for(int i=1;i<=n;i+=n/3){
			set<char> S;
			REP(j,i,i+n/3)REP(l,1,m+1)S.insert(X[j][l]);
			if(S.size()>1)flag2=false;
		}
	}else flag2=false;
	if(flag1||flag2)cout<<"YES";
	else cout<<"NO";
	cout<<endl;
	return 0;
}