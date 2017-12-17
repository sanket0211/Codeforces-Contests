

#include <bits/stdc++.h>

using namespace std;

int main(){
	long long int a, b,c;
	cin >> a >> b >> c;
	//cout << (-5%5) << endl;
	if(c==0){
		if(a==b){
			cout << "YES" << endl;
			return 0;
		}
		else{
			cout << "NO" << endl;
			return 0;
		}
	}
	if((b-a)*c <0){
		cout << "NO" << endl;
			return 0;
	}
	
	if((b-a)%c==0){
		cout << "YES" << endl;
	}
	else  {
		cout << "NO" << endl;
	}
	return 0;
}
