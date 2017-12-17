
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
	string ch;char a,b,c;lli count=0;
	cin >> ch;
	if(ch.size()==1){
		cout << "0" << endl;
	}
	else if(ch.size()==2 && ch[0]=='a' && ch[1]=='b'){
		cout << "1" << endl;
	}
	else if(ch.size()==2){
		cout << "0" << endl;
	}
	else{
		a=ch[0];b=ch[1];c=ch[2];
		if(a=='a' && b=='a' && c=='b'){
			a='a';b='a';count+=3;
		}
		else if(a=='a' && b=='b' && c=='b'){
			a='b';b='a';count+=2;
		}
		else if(a=='a' && b=='b' && c=='a'){
			a='a';b='a';count+=1;
		}
		else if(a=='b' && b=='a' && c=='b'){
			a='b';b='a';count+=1;
		}
		for(int i=3;i<ch.size();i++){
			c=ch[i];
			if(a=='a' && b=='a' && c=='b'){
				a='a';b='a';count+=3;
			}
			else if(a=='a' && b=='b' && c=='b'){
				a='b';b='a';count+=2;
			}
			else if(a=='a' && b=='b' && c=='a'){
				a='a';b='a';count+=1;
			}
			else if(a=='b' && b=='a' && c=='b'){
				a='b';b='a';count+=1;
			}
			else{
				a=b;b=c;
			}	
			//trace1(count);
			count=count%1000000007;
		}
		cout << count << endl;

	}
	return 0;
}