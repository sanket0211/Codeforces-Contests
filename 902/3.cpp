
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
	lli n;cin >> n;
	vector<int>v;int flag1=0;
	for(int i=0;i<=n;i++){
		lli k;cin >> k;v.push_back(k);
	}
	int flag=0;
	for(int i=0;i<=n;i++){
		if(flag==1&&v[i]>=2){
			flag1=1;
			cout << "ambiguous" << endl;
			break;
		}
		else if(flag==1&&v[i]<2)flag=0;
		if(v[i]>=2){
			flag=1;
		}

	}
	if(flag1==0){
		cout << "perfect" << endl;
		return 0;
	}
	queue<int>q;
	q.push(0);int sum=1;int cnt=1;
	for(int i=0;i<=n;i++){
		cnt=0;
		int par=q.front();q.pop();
		while(!q.empty()){
			q.pop();
		}
		while(cnt<v[i]){
			cout << par << " ";
			cnt++;
			q.push(sum);
			sum++;
		}
	}
	cout << endl;

	queue<int>q2;
	q2.push(0);sum=0;int prev_sum=0;int par2=-1;
	for(int i=0;i<=n;i++){
		//trace1(q2.size());
		cnt=0;sum=v[i]+prev_sum;prev_sum=sum;
		int par=q2.front();q2.pop();
		if(!q2.empty()){
			par2=q2.front();
		}
		while(!q2.empty()){
			q2.pop();
		}
		//trace1(par2);
		while(cnt<v[i]){
			cout << par << " ";
			cnt++;
			q2.push(sum);
			sum--;
			if(par2!=-1)par=par2;
			//trace1(sum);

		}
	}
	cout << endl;

	return 0;
}