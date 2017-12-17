
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
	lli n, k;
	cin >> n >> k;
	map<int,int>mp;
	vector<pair<int,int> >v;
	for(int i=0;i<n;i++) {
		lli l;
		cin >> l;
		mp.insert(make_pair(i+1,l));
		v.push_back(make_pair(l,i+1));
	}
	int arr[300005];
	memset(arr, -1, sizeof arr);
	sort(v.begin(),v.end());
	int cost = 0;
	int ptr = k+n;
	for(int i=0;i<n;i++){

		if(ptr==k){
			arr[v[i].second]=v[i].second;
			continue;
		}
		if(mp.find(ptr)==mp.end())
		cost +=  (v[i].first)*(ptr-v[i].second);
		else{
			if(mp[ptr]==v[i].first){
				arr[v[i].second]=ptr;
				mp.erase(ptr);
				ptr--;

				continue;
			}
			else {
				ptr--;
			}
		}
		arr[v[i].second]=ptr;
		mp.erase(ptr);
		ptr--;

	}
	cout << cost << endl;
	for(int i=0;i<300005;i++){
		if(arr[i]!=-1){
			cout << arr[i] << " ";
		}
	}
	cout << endl;
}