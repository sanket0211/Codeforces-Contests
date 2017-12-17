
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
	char str1[1020], str2[102];
	cin >> str1 >> str2;
	int len1=strlen(str1);
	int len2=strlen(str2);
	if(len1==len2){
		int i=0;
		for(i=0;i<len1;i++){
			if(str1[i]!=str2[i]){
				break;
			}
		}
		if(i<=len1-1){
			cout<<"1"<<endl;

		}
		else{
			for(int i=0;i<len1;i++){
				cout << str1[i];
			}
			cout << endl;
		}
	}
	else{
		cout << "1" << endl;
	}
	return 0;
}
