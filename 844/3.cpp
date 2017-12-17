
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
	lli n;
	cin >> n;
	vector<pair<int,int> >v;
	for(int i=0;i<n;i++){
		int k;
		cin >> k;
		v.push_back(make_pair(k,i));
	}

	sort(v.begin(),v.end());
	int cnt=0;map<int,int>mp;
	int ptr=0;
	int m=0;int mcont=0;vector<vector<int> >ans;
	
	for(int i=0;i<n;i++){
		if(v[i].first==-1){
			continue;
		}
		ptr=i;mcont++;
		vector<int>temp;
		
		//temp.push_back(v[i].second+1);
		while(v[ptr].first!=-1){
			cnt++;

			v[ptr].first=-1;
			
			ptr = v[ptr].second;
			temp.push_back(v[ptr].second+1);
			//trace1(v[ptr].second+1);
		}
		//cout << cnt << " ";

		sort(temp.begin(),temp.end());
		/*for(int m=0;m<temp.size();m++){
			trace1(temp[m]);
		}*/
		//temp[0]=cnt;
		ans.push_back(temp);
		temp.clear();

		cnt=0;
	}
	cout << ans.size() << endl;
	for(int i=0;i<ans.size();i++){
		cout << ans[i].size() << " ";
		for(int j=0;j<ans[i].size();j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}