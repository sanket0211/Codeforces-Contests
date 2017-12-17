
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


lli num(string s){
	lli n=s.size();
	lli ans=0;lli m=1;
	//trace1(s);
	for(int i=n-1;i>=0;i--){
		ans = ans + (s[i]-'0')*m;
		m=m*10;
	}
	//trace1(ans);
	//trace1(ans);
	return ans;
}

int main(){
	lli k,p;
	lli sum=0;
	cin >> k >> p;
	vector<string>ve;
	lli cnt=0;
	lli m=0;
	vector<string>temp;
	//temp.push_back("00");
	while(cnt<k){
		for(int i=0;i<ve.size();i++){
			string s1="";string s2="";
			
			s1=s1+(char)(m+48);
			s2=s2+(char)(m+48);
			string s=s1+ve[i]+s2;
			if(m==0){
				temp.push_back(s);
				
				continue;
			}
			sum=sum + num(s);
			sum=sum%p;
			cnt++;
			temp.push_back(s);
			if(cnt==k){
				cout << sum << endl;
				return 0;
			}
		}
		if(ve.size()==0){
			//int i=0;i<ve.size();i++){
			string s1="";string s2="";
			
			s1=s1+(char)(m+48);
			s2=s2+(char)(m+48);
			if(m==0){
				temp.push_back(s1+s2);
				m++;
				continue;
			}
			//s1=s1+'1';
			//s2=s2+'1';
			//trace2(s1,s2);
			//string s =(string) s1+(string)s2;
			//string s=s1+ve[i]+s2;
			sum=sum + num(s1+s2);
			//trace1(sum);
			sum=sum%p;
			cnt++;
			if(cnt==k){
				cout << sum << endl;
				return 0;
			}
			temp.push_back(s1+s2);	
		}
		m++;
		if(m==10){
			ve.clear();
			m=0;
			for(int j=0;j<temp.size();j++){
				ve.push_back(temp[j]);
				//trace1(temp[j]);
				
			}
			temp.clear();
		}
	}
	return 0;
}