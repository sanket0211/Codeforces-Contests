
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
	string s;
	cin >> s;
	int cnt=0;
	//vector<int>arr(26,0);
	int vf=0;string temp="";int ptr=0;int ptr2=0;int un=0;
	if(s.size()<2){
		cout << s << endl;
		return 0;
	}
	for(int i=0;i<2;i++){
		temp+=s[i];
	}
	ptr2=2;
	while(ptr2<s.size()){
		//arr[s[ptr2]-'a']++;
		
		if(ptr2-ptr==2){
			vector<int>arr(26,0);
			for(int a=ptr;a<=ptr2;a++){
				arr[s[a]-'a']++;
				if(s[a]=='a'||s[a]=='e'||s[a]=='i'||s[a]=='o'||s[a]=='u'){
					vf=1;
				}
			}
			//arr[s[ptr2]-'a']++;
			int un=0;
			for(int i=0;i<26;i++){
				if(arr[i]>=1){
					un++;
				}
			}
			if(un>=2&&vf==0){
				temp+=" ";
				arr[s[ptr]-'a']--;
				ptr++;
				vf=0;
				temp+=s[ptr2];
				ptr2++;
				
			}
			else{
				arr[s[ptr]-'a']--;
				ptr++;
				vf=0;
				temp+=s[ptr2];
				ptr2++;
			}
		}
		
	}
	cout << temp << endl;
	return 0;
}