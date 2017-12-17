#include<stdio.h>

int main(){
	double n,g;
	scanf("%lf %lf", &n,&g);
	double ans = ((n/g)/g);
	double ans2 = (n/(g*g));
	printf("%lf %lf\n", ans,ans2);
	return 0;
}
