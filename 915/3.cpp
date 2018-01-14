
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
lli m;

int check(vector<int>&v1){
	lli sum=0;
	sort(v1.begin(),v1.end());
	for(int i=v1.size()-1;i>=0;i--){
		sum=sum+v1[i];
		sum=sum*10;
	}
	sum=sum/10;
	trace2(sum,m);
	if(sum<=m){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	vector<int>v1;vector<int>v2;
	lli a,b;cin >> a >> b;
	lli c=b;lli d=a;m=b;
	while(a>0){
		lli dig=a%10;v1.push_back(dig);a=a/10;
	}
	while(b>0){
		lli dig=b%10;v2.push_back(dig);b=b/10;
	}
	b=c;
	if(v1==v2){
		cout << d<<endl;
		return 0;
	}




	vector<int>temp2;
	for(int i=v2.size()-1;i>=0;i--){
		temp2.push_back(v2[i]);
	}
	v2=temp2;
	if(v2.size()>v1.size()){
		sort(v1.begin(),v1.end());lli s2=0;
		for(int i=v1.size()-1;i>=0;i--){
			s2=s2+v1[i];
			s2=s2*10;
		}
		s2=s2/10;
		cout << s2 << endl;
		return 0;
	}
	sort(v1.begin(),v1.end());lli final=LONG_MIN;
	lli cnt=0;
	if(v1.size()>v2.size()){
		while(!check(v1)){
			
			v1.erase(v1.begin());
			cnt++;
		}
	}
	if(v2.size()>v1.size()){
		sort(v1.begin(),v1.end());lli s2=0;
		for(int i=v1.size()-1;i>=0;i--){
			s2=s2+v1[i];
			s2=s2*10;
		}
		s2=s2/10;
		for(int i=0;i<cnt;i++){
			cout << '0';
		}
		cout << s2 << endl;
		return 0;
	}
	//sort(v2.begin(),v2.end());
	int dig=v2[0];vector<int>temp=v1;
	vector<int>ans,ans2;
	for(int j=0;j<v2.size();j++){
		dig=v2[j];lli mini=LONG_MIN;int ind=-1;int ind2=-1;
		for(int i=0;i<v1.size();i++){
			//trace2(mini,v1[i]);
			if(v1[i]>mini&&v1[i]<dig){
				mini=v1[i];ind=i;
			}
			if(v1[i]==dig){
				ind2=i;
			}
		}
		temp=v1;
		//trace2(ind,ind2);
		if(ind!=-1){
			v1.erase(v1.begin()+ind);

			sort(v1.begin(),v1.end());
			
			ans.push_back(mini);
			for(int i=ans.size()-1;i>=0;i--){
				v1.push_back(ans[i]);
			}
			
			int m=0;lli sum=0;
			for(int i=v1.size()-1;i>=0;i--){
				sum=sum + v1[i];
				sum=sum*10;
				//trace2(sum,v1[i]);
			}
			sum=sum/10;
			//trace2(sum,final);
			if(sum<=b && sum>=final){
				
				final=sum;sum=0;
			}
		}
		//trace1(final);
		if(ind2!=-1){
			v1=temp;
			ans2.push_back(v1[ind2]);
			ans=ans2;
			v1.erase(v1.begin()+ind2);

		}

	}
	for(int i=0;i<cnt;i++){
		cout << "0";
	}
	cout << final << endl;
	return 0;
}