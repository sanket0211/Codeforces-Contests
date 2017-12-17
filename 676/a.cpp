
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
	LL n,t,count=0;
	cin >> n >> t;
	double arr[12][12];

	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			arr[i][j]=0;
		}
	}
	arr[1][1]=t;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(arr[i][j]>1){
				arr[i+1][j]+=(arr[i][j]-1)/2;
				arr[i+1][j+1]+=(arr[i][j]-1)/2;
				arr[i][j]=1;
			}
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(arr[i][j]==1){
				
				count++;
			}
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(arr[i][j]==1){
				
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}
