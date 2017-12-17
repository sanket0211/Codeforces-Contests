
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

vvi primefactors; vector<int> primenumbers;
 vector< long long int > primesieve;
// A function to print all prime factors of a given number n
void primeFactors(int n,int num)
{
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        //printf("%d ", 2);
        primefactors[num].PB(2);
        n = n/2;
    }
 
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            //printf("%d ", i);
        	primefactors[num].PB(i);
            n = n/i;
        }
    }
 
    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2)
        //printf ("%d ", n);
        primefactors[num].PB(n);
}

long long int checkPrime(lli n){
	if(primesieve[n]==1){
		return 1;
	}
	else return 0;
}

void sieve(){
	primesieve.resize(1000000);
	//memset (primesieve,1,1000000);
	for(int i=0;i<=100000;i++){
		primesieve[i]=1;
	}
	for(int i=2;i<=1000000;i++){
		if(primesieve[i]==1){
			primenumbers.PB(i);
			for(int j=2;i*j<=1000000;j++){
				primesieve[i*j]=0;
			}
		}
	}
}

/* Driver program to test above function */
int main()
{	
	string str;sieve();int flag=1;
	//for(int i=0;i<20;i++){
	//	cout << primenumbers[i] << " ";
	//}
	//cout << endl;
	int j=0;int count=0;
	for(int i=1;i<=20;i++){
		cout << primenumbers[j] << endl;
		 fflush(stdout); 
		 cin >> str;
		 if(str[0]=='y' && count==0){
		 	count++;
		 	//j++;
		 	if(primenumbers[j]*primenumbers[j]<=100){
			 	cout << primenumbers[j]*primenumbers[j] << endl;i++;
			 	fflush(stdout);
			 	cin >> str;
			 	if(str[0]=='y'){
			 		flag=2;
			 		break;
			 	}
			 }
		 	j++;

		 }
		 else if(str[0]=='y' && count>0){
		 	flag=2;
		 	break;
		 }
		 else if(str[0]=='n'){
		 	j++;
		 }


		 if(count>=2){
		 	flag=2;
		 	break;
		 }
	}
	if(flag==1){
		cout << "prime" << endl;
	}
	else if(flag==2){
		cout << "composite" << endl;
	}
    //cout << GCD(56,88) << endl;;
    return 0;
}
