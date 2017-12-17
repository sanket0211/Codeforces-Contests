#include <iostream>
using namespace std;
int n, x, m, sec, ans = 1, y[100100];
int main() {
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> x;
		if(x > m)y[x] = 1, sec = m, m = x;
		else if(x > sec)y[m]--, sec = x;
	}
	for(int i = 1; i <= n; ++i)if(y[i] < y[ans])ans = i;
	cout << ans;
}