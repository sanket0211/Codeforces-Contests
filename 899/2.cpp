
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
	int arr[48]={31, 28, 31, 30, 31, 30,31,31,30,31,30,31,31,28, 31, 30, 31, 30,31,31,30,31,30,31,31,28, 31, 30, 31, 30,31,31,30,31,30,31,31,28, 31, 30, 31, 30,31,31,30,31,30,31};
	int arr1[48]={31,29, 31, 30, 31, 30,31,31,30,31,30,31,31,28, 31, 30, 31, 30,31,31,30,31,30,31,31,28, 31, 30, 31, 30,31,31,30,31,30,31,31,28, 31, 30, 31, 30,31,31,30,31,30,31};
	int arr2[48]={31,28, 31, 30, 31, 30,31,31,30,31,30,31,31,29, 31, 30, 31, 30,31,31,30,31,30,31,31,28, 31, 30, 31, 30,31,31,30,31,30,31,31,28, 31, 30, 31, 30,31,31,30,31,30,31};
	int arr3[48]={31,28, 31, 30, 31, 30,31,31,30,31,30,31,31,28, 31, 30, 31, 30,31,31,30,31,30,31,31,29, 31, 30, 31, 30,31,31,30,31,30,31,31,28, 31, 30, 31, 30,31,31,30,31,30,31};
	int arr4[48]={31,28, 31, 30, 31, 30,31,31,30,31,30,31,31,28, 31, 30, 31, 30,31,31,30,31,30,31,31,28, 31, 30, 31, 30,31,31,30,31,30,31,31,29, 31, 30, 31, 30,31,31,30,31,30,31};
	
	vector<int>v;
	for(int i=0;i<n;i++){
		lli k;
		cin >> k;
		v.push_back(k);
	}

	for(int i=0;i<48;i++){
		if(arr[i]==v[0]){
			lli ptr1=i,ptr2=0;
			while(ptr2<v.size()){
				if(arr[ptr1]==v[ptr2]){
					ptr1++;ptr2++;
					ptr1=ptr1%24;
				}
				else break;
			}
			if(ptr2==v.size()){
				cout << "YES" << endl;
				return 0;
			}



		}

	}

	for(int i=0;i<48;i++){
		if(arr1[i]==v[0]){
			lli ptr1=i,ptr2=0;
			while(ptr2<v.size()){
				if(arr1[ptr1]==v[ptr2]){
					ptr1++;ptr2++;
					ptr1=ptr1%24;
				}
				else break;
			}
			if(ptr2==v.size()){
				cout << "YES" << endl;
				return 0;
			}



		}

	}

	for(int i=0;i<48;i++){
		if(arr2[i]==v[0]){
			lli ptr1=i,ptr2=0;
			while(ptr2<v.size()){
				if(arr2[ptr1]==v[ptr2]){
					ptr1++;ptr2++;
					ptr1=ptr1%24;
				}
				else break;
			}
			if(ptr2==v.size()){
				cout << "YES" << endl;
				return 0;
			}



		}

	}

	for(int i=0;i<48;i++){
		if(arr3[i]==v[0]){
			lli ptr1=i,ptr2=0;
			while(ptr2<v.size()){
				if(arr3[ptr1]==v[ptr2]){
					ptr1++;ptr2++;
					ptr1=ptr1%24;
				}
				else break;
			}
			if(ptr2==v.size()){
				cout << "YES" << endl;
				return 0;
			}



		}

	}

	for(int i=0;i<48;i++){
		if(arr4[i]==v[0]){
			lli ptr1=i,ptr2=0;
			while(ptr2<v.size()){
				if(arr4[ptr1]==v[ptr2]){
					ptr1++;ptr2++;
					ptr1=ptr1%24;
				}
				else break;
			}
			if(ptr2==v.size()){
				cout << "YES" << endl;
				return 0;
			}



		}

	}
	cout << "NO" << endl;
	return 0;
}