

#include <bits/stdc++.h>
using namespace std;
int main(){
	long long int n,a,b,c,d;
	vector <long long int> vec;
	cin >> n >> a >> b >> c >> d;
	long long int sqr1=a+b;
	long long int sqr2=a+c+2;
	long long int sqr3=b+d+2;
	long long int sqr4=c+d+2;
	vec.push_back(sqr1);
	vec.push_back(sqr2);
	vec.push_back(sqr3);
	sort(vec.begin(),vec.end());
	long long int max = vec[2];
	long long int sum=0;
	for(int i=0;i<n;i++){
		long long int first = n-(max+i-(a+b+i+1))+1;
		if(first<=0){
			break;
		}
		cout << first << endl;
		sum=sum+first;
	}
	cout << sum << endl;

	
	return 0;

}