
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
	lli n, m;
	cin >> n >> m;
	vector<string>v;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		v.push_back(s);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			trace1(v[i][j]);
			if(v[i][j]!='R'&& v[i][j]!='B' && v[i][j]!='G'){
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	lli width=1,height=1;
	for(int i=1;i<m;i++){
		if(v[0][i]!=v[0][i-1]){
			break;
		}
		else{
			width++;
		}
	}
	for(int i=1;i<n;i++){
		if(v[i][0]!=v[i-1][0]){
			break;
		}
		else{
			height++;
		}
	}
	//trace2(height,width);


	int r_i=-1,r_j=-1,g_i=-1,g_j=-1,b_i=-1,b_j=-1;int flag=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(v[i][j]=='R' && r_i==-1){
				r_i=i;r_j=j;
				flag=1;
			}
			else if(v[i][j]=='B' && b_i==-1){
				b_i=i;b_j=j;
				flag=2;
			}
			else if(v[i][j]=='G' && g_i==-1){
				g_i=i;g_j=j;
				flag=3;
			}
			

		}
		
	}
	if(r_i==-1 || b_i==-1 || g_i==-1){
		cout << "NO" << endl;
		return 0;
	}
	trace3(r_i,b_i,g_i);
	trace3(r_j,b_j,g_j);
	int r_w=0,r_h=0,b_h=0,b_w=0,g_w=0,g_h=0;
	for(int i=r_i;i<n;i++){
		r_w=0;
		if(v[i][r_j]=='R'){
			r_h++;
		}
		else{
			if(r_h!=height){
				cout << "NO"<< endl;
				return 0;
			}
			break;
		}
		for(int j=r_j;j<m;j++){
			if(v[i][j]=='R'){
				r_w++;
			}
			else{
				break;
			}
		}
		if(r_w!=width){
			cout << "NO" << endl;
			return 0;
		}
	}
	trace1(r_w);
	for(int i=b_i;i<n;i++){
		b_w=0;
		if(v[i][b_j]=='B'){
			b_h++;
		}
		else{
			if(b_h!=height){
				cout << "NO"<< endl;
				return 0;
			}
			break;
		}
		for(int j=b_j;j<m;j++){
			if(v[i][j]=='B'){
				b_w++;
			}
			else{
				break;
			}
		}
		if(b_w!=width){
			cout << "NO" << endl;
			return 0;
		}
	}
	trace1(b_w);
	for(int i=g_i;i<n;i++){
		g_w=0;
		if(v[i][g_j]=='G'){
			g_h++;
		}
		else{
			if(g_h!=height){
				cout << "NO"<< endl;
				return 0;
			}
			break;
		}
		for(int j=g_j;j<m;j++){
			if(v[i][j]=='G'){
				g_w++;
			}
			else{
				break;
			}
		}
		if(g_w!=width){
			cout << "NO" << endl;
			return 0;
		}
	}
	int r_f=0,b_f=0,g_f=0;
	for(int i=0;i<m;i++){
		if(v[r_i][i]=='R'){
			r_f++;
		}
	}
	if(r_f!=width){
		cout << "NO" << endl;
			return 0;
	}
	//trace1(r_f);
	for(int i=0;i<m;i++){
		if(v[b_i][i]=='B'){
			b_f++;
		}
	}
	//trace1(r_f);
	if(b_f!=width){
		cout << "NO" << endl;
			return 0;
	}
	trace1(r_f);
	for(int i=0;i<m;i++){
		if(v[g_i][i]=='G'){
			g_f++;
		}
	}
	if(g_f!=width){
		cout << "NO" << endl;
			return 0;
	}

	int r_f2=0,b_f2=0,g_f2=0;
	for(int i=0;i<n;i++){
		if(v[i][r_j]=='R'){
			r_f2++;
		}
	}
	if(r_f2!=height){
		cout << "NO" << endl;
			return 0;
	}

	for(int i=0;i<n;i++){
		if(v[i][b_j]=='B'){
			b_f2++;
		}
	}

	if(b_f2!=height){
		cout << "NO" << endl;
			return 0;
	}
	//trace1(r_f);
	for(int i=0;i<n;i++){
		if(v[i][g_j]=='G'){
			g_f2++;
		}
	}
	//trace1(r_f);
	if(g_f2!=height){
		cout << "NO" << endl;
			return 0;
	}


	cout << "YES" << endl;
	return 0;
}