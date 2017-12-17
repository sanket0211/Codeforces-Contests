
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
	string g,in;map<char,int>mp;
	cin >> g >> in;
	lli n;vector<string>vec;
	cin >> n;
	for(int i=0;i<n;i++){
		string temp;
		cin >> temp;	
		vec.push_back(temp);
	}
	for(int i=0;i<g.size();i++){
		if(mp.find(g[i])==mp.end()){
			mp.insert(make_pair(g[i],1));
		}
	}
	for(int i=0;i<n;i++){
		string temp=vec[i];
		int ptr=0;int j;
		for( j=0;j<in.size();j++){
			//trace2(temp[ptr])
			if(ptr>=temp.size()){
				if(in[j]=='*'){
					continue;
				}
				else{
					cout << "NO" << endl;
					break;
				}
			}
			if(temp[ptr]==in[j]){
				ptr++;
				continue;
			}
			else if(temp[ptr]!=in[j]){
				if(in[j]=='?'){
					if(mp.find(temp[ptr])!=mp.end()){
						ptr++;
						continue;
					}
					else{
						cout << "NO" << endl;
						//return 0;
						break;
					}
				}
				else if(in[j]=='*'){
					while(mp.find(temp[ptr])==mp.end()){
						if(j<in.size()-1){
							if(in[j+1]==temp[ptr]){
								break;
							}
						}

						ptr++;//trace1(j);
						if(ptr>=temp.size()){
							break;
						}
					}
				}
				else{
					cout << "NO" << endl;
					break;
				}
			}
		}
		//trace1(j);
		//trace1(ptr);
		if(j==in.size()){
			if(ptr>=temp.size()){
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
	
}