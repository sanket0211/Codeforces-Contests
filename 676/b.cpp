
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
const int N = int(1e4)+10;
set<string> S;
bool dp[2][N];
int main(){
	LL n,k,pos1=-1,pos2=-1;
	vector <int> vec;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> k;
		//vec.PB(k);
		if((k==1 || k==n) && pos2==-1){
			pos1=i;
		}
		if( (k==n || k==1) && pos1!=-1){
			pos2=i;
		}
	}
	//cout << pos1 << pos2 << endl;
	if(pos1==0 && pos2==n-1){
		cout << n-1<< endl;
	}
	else if(pos2>(n-1-pos1)){
		cout << pos2 << endl;
	}
	else{
		cout << n-1-pos1 << endl;
	}
	return 0;
}