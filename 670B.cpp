


#include <bits/stdc++.h>

using namespace std;

int main(){
	long long int n,k,num;
	vector<int>id;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> num;
		id.push_back(num);
	}
	long long int l = sqrt(k*2);
	if(l*(l+1)<(k*2)){
		num=l;
			
	}
	else if(l*(l+1)>(k*2)){
		num=l-1;
	}
	else {
		cout << id[l-1] << endl;
			return 0;
	}
	/*//cout << "l "<<l << endl;
	for(int j=sqrt(k*2);j<=k*2;j++){
		//cout << j << endl;
		if(j*(j+1)>(k*2)){
			num=j-1;
			//cout << num << endl;
			break;
		}
		if(j*(j+1)==(k*2)){
			cout << id[j-1] << endl;
			return 0;
		}

	}*/

	//cout << num << endl;
	num=(num*(num+1))/2;
	num=k-num;
	cout << id[num-1] << endl;
	return 0;
}

