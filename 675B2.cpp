

#include <bits/stdc++.h>
using namespace std;
int main(){
	long long int n,a,b,c,d;
	vector <long long int> vec;
	cin >> n >> a >> b >> c >> d;
	long long int sqr1=a+b;
	long long int sqr2=a+c;
	long long int sqr3=b+d;
	long long int sqr4=c+d;
	vec.push_back(sqr1);
	vec.push_back(sqr2);
	vec.push_back(sqr3);
	sort(vec.begin(),vec.end());
	long long int max = vec[2];
	long long int sum=0,tot=0;
	for(int i=1;i<=n;i++){
		sum=a+b+i;
		long long int f = sum-a-c;
		long long int s=sum-b-d;
		long long int t=sum-c-d;
		if(f>=1 && f<=n && s>=1 && s<=n && t>=1 && t<=n){
			tot=tot+n;
		}
		
	}
	cout << tot << endl;

}