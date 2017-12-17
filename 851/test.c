#include<stdio.h>
#include<math.h>

int main(){
	float n,m,a,x,y;
	long long int l,b,t;
		

	1<=n<=1000000000;
	1<=m<=1000000000;
	1<=a<=1000000000;
	scanf("%f %f %f",  &n, &m, &a);
	//printf("%f\n", n);
	x=n/a;
	y=m/a;
	//printf("%f\n", x);
	l=ceil(x);
	b = ceil(y);

	t = l*b;
	printf("%lld\n",t );
	return 0;
}