#include <stdio.h>
#include <stdlib.h>
int fibo(int k)
{
	if(k==0)
	{
		return 0;
	}
	else if(k==1)
	{
		return 1;
	}

	else
	{
		return(fibo(k-2)+fibo(k-1));
	}

	
	
}


int main()
{
	
	int n,a=0,b=1;
	printf("kac adet sayi ile fibonacci dizisi olusturacaksin:");
	scanf("%d",&n);
	
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\n",fibo(i));
	}
	
	
	
	
	
	
	return 0;
}
