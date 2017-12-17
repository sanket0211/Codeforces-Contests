
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
	int arr[1005]={0};
	lli n,k;vi a,b;
	cin >> n ;
	loop(i,0,n){
		cin >> k;
		a.PB(k);
		arr[k]=1;
	}
	int flag=0;
	loop(i,0,n){
		cin >> k;
		b.PB(k);
		arr[k]=1;
	}
	int used[1005]={0};
	int cnt=0;int ind1,ind2;
	loop(i,0,n){
		if(a[i]!=b[i]){
			cnt++;
			if(cnt==1){
				ind1=i;
			}
			else{
				ind2=i;
			}
		}
		else{
			used[a[i]]=1;
		}
	}
	int nc;
	loop(i,1,n+1){
		if(arr[i]==0){
			nc=i;
			break;
		}
	}
	vi ans;
	if(cnt==1){
		loop(i,0,n){
			if(a[i]==b[i]){
				cout << a[i] << " ";
				//ans.PB(a[i];)
			}
			else{
				cout << nc << " ";
			}
		}
		cout << endl;
		return 0;
	}
	int un1=-1,un2=-1;
	loop(i,1,n+1){
		if(un1==-1&& used[i]==0){
		un2=i;
		}
		if(used[i]==0){
			un1=i;
		}
	}
	loop(i,0,n){
		if(a[i]==b[i]){
			//cout << a[i] << " ";
			ans.PB(a[i]);
		}
		else if(flag==0){
			ans.PB(un1);flag=1;
		}
		else{
			ans.PB(un2);
		}
	}
	int cnt1=0;int cnt2=0;
	loop(i,0,n){
		if(ans[i]!=a[i]){
			cnt1++;
		}
		if(ans[i]!=b[i]){
			cnt2++;
		}
	}
	swap(un1,un2);
	trace2(un1,un2);
	if(cnt1==cnt2 && cnt1==1){
		loop(i,0,n){
			cout << ans[i] << " ";
		}
		cout << endl;
		return 0;
	}
	else{
		swap(ans[ind1],ans[ind2]);
		loop(i,0,n){
			cout << ans[i] << " ";
		}
		cout << endl;
		return 0;	
	}
	//cout <<endl;
	return 0;
}