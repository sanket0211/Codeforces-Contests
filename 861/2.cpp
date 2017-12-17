
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
	lli n,m,k;
	vector< pair<int,int> >vp;
	cin >> n >> k;
	if(k==0){
		if(n==1){
			cout << "1" << endl;
			return 0;
		}
		else{
			cout << "-1" << endl;
			return 0;
		}
	}
	map<int,int>mp;
	for(int i=0;i<k;i++){
		int a,b;
		cin >> a >> b;
		mp.insert(make_pair(a,b));
		vp.push_back(make_pair(a,b));
	}
	sort(vp.begin(),vp.end());int flag=0;	
	int cnt=0,f_nf;int ff, n_f,start,end,l;
	for(int i=1;i<vp.size();i++){
		if(vp[i-1].second==vp[i].S){
			continue;
		}
		start=vp[i-1].first;end=vp[i].first;
		ff = vp[i-1].S;cnt=0;
		for(int m=start;m<end;m++){

			if(m%ff==0){
				n_f = m/ff;
				for(l=0;l<k;l++){
					if( vp[l].F%n_f ==0){
						if( vp[l].S != (vp[l].F/n_f) ){
							break;
						}
					}
					else{
						if( (vp[l].S-1) != (vp[l].F/n_f) ){
							break;
						}
					}
				}
				if(l==k){
					cnt++;
					f_nf=n_f;
				}
			}

		}
		if(cnt==1){
			flag=1;
			//trace2(i,f_nf);
			break;
		}
	}
	if(flag==0){
		cout << "-1" << endl;
		return 0;
	}
	else{
		if(n%f_nf==0){
			cout << n/f_nf << endl;
		}
		else{
			cout << (n/f_nf)+1 << endl;	
		}
		return 0;
	}

	

}