
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
	LL n,k;
	vector<int>sticks;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> k;
		sticks.PB(k);
	}
	LL sum=0;
	sort(sticks.begin(), sticks.end());
	for(int i=0;i<n-1;i++){
		sum=sum+sticks[i];
	}
	cout << sticks[n-1]-sum +1 << endl;
	return 0;

}