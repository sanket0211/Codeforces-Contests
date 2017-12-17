
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
	cin >> n >>k;
	vector<int>fr;
	vector<int>sc;
	fr.PB(0);
	int max=0;
	int tot1=1;int tot2=1;
	sc.PB(0);
	char str[100005];
	cin >> str;
	int len = strlen(str);
	//cout << len << endl;
	for(int i=0;i<len;i++){
		if(str[i]=='a'){
			tot1++;
			fr.PB(i+1);
		}
		else{
			tot2++;
			sc.PB(i+1);
		}
	}tot1++;tot2++;fr.PB(n+1);sc.PB(n+1);int ch = k;
	//cout << tot1 << tot2 << endl;
	for(int i=0;i<tot1;i++){
		if(i+k+1 < tot1){
			int diff = fr[i+k+1]-fr[i];
			if(diff>=max){
				max=diff;
			}
		}
		else{
			if(k>0){
				k--;
				i--;
			}
		}
	}
	k=ch;
	for(int i=0;i<tot2;i++){
		if(i+k+1 < tot2){
			int diff = sc[i+k+1]-sc[i];
			if(diff>=max){
				max=diff;
			}
		}
		else{
			if(k>0){
				k--;i--;
			}
		}
	}	
	cout << max-1 << endl;
	return 0;

}