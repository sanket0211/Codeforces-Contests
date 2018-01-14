#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,p,l,r,ans = 1987654321,tmp;
ll dis(ll a,ll b){
	if(a>b){
		return a-b;
	}
	return b-a;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>p>>l>>r;
	if(l == 1 && r == n){
		cout<<0;
		return 0;
	}
	if(l == 1){
		cout<<dis(p,r)+1;
		return 0;
	}
	if(r == n){
		cout<<dis(p,l)+1;
		return 0;
	}
	tmp = dis(p,l)+1;
	//cout<<min(dis(p,l),min(dis(1,l)+1,dis(n,l)+1))<<endl;
	ans = min(ans,tmp+dis(l,r)+1);
	//cout<<min(dis(l,r),min(dis(r,n)+1,dis(1,r)+1))<<endl;
	tmp = dis(p,r)+1;
	//cout<<min(dis(p,r),min(dis(r,n)+1,dis(1,r)+1))<<endl;
	ans = min(ans,tmp+dis(l,r)+1);
	//cout<<min(dis(r,l),min(dis(1,l)+1,dis(n,l)+1))<<endl;
	cout<<ans;
}