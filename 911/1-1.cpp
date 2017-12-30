# include <bits/stdc++.h>

using namespace std;

int main(){
	int size;
	cin>>size;

	int real[size],arr[size];
	for(int i=0;i<size;i++){
		cin>>real[i];
		arr[i]=real[i];
	}

	sort(real,real+size);

	int min=real[0];
	int minDis=INT_MAX;
	int prev;
	for(int i=0;i<size;i++){
		if(arr[i]==min){
			prev=i;
			i++;
			while(i<size){
				if(arr[i]==min){
					int distance=i-prev;
					minDis=fmin(minDis,distance);
					prev=i;
				}
				i++;
			}
			
		}
	}

	cout<<minDis;
}