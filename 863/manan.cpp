#include<stdio.h>
int main()
{
	int n,j,a[200],r,i=0,count=0;
	scanf("%d",&n);
	if(n%10==0)
	{
		while(n%10==0)
		{
			n=n/10;
		}
	}
//	printf("%d ",n);
	while(n!=0)
	{
		r=n%10;
		a[i]=r;
		i++;
		n=n/10;
	}
	for(j=0;j<i;j++)
	{
		if(a[j]==a[i-j-1])
			count++;
		else
			break;
	}
	if(count==i)
		printf("YES\n");
	else printf("NO\n");
	return 0;
}