
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
	lli n,k;cin >>  n >> k;
	lli req=1;stack<int>s;
	vector<int>v;
	for(int i=0;i<k;i++){
		lli a;cin >> a;v.push_back(a);
	}	
	
	vector<int>ans;
	for(int i=0;i<k;i++){
		s.push(v[i]);	
		while(!s.empty()&&s.top()==req){
			req++;s.pop();
		}
	}

	stack<int>temp;temp=s;
	while(!s.empty()){
		ans.push_back(s.top());
		s.pop();
	}
	vector<int>ans_temp;
	ans_temp=ans;
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++){
		if(ans[i]!=ans_temp[i]){
			cout << "-1" << endl;
			return 0;
		}
	}
	s=temp;

	for(int i=0;i<k;i++){
		cout << v[i] << " ";
	}
	int st=req;

		//int e=s.top();
		//trace2(st,e);
		//return 0;
	while(!s.empty()){
		int e=s.top();
		for(int i=e-1;i>=st;i--){
			cout << i << " ";
			k++;
		}
		st=e+1;
		s.pop();
		if(s.empty())break;
		e=s.top();

	}
	//trace2(n,k);
	//return 0;
	for(int i=n;i>k;i--){
		cout << i << " ";
	}
	cout << endl;
	return 0;

}