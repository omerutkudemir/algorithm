#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	
	char dizi1[100],dizi2[100];
	int i,k=0,j,d;
	
	printf("lutfen bir kelime giriniz: ");
	gets(dizi1);
	
	for(i=(strlen(dizi1)-1);i>=0;i--)
	{
		
		dizi2[k]=dizi1[i];
		k++;
		
	}
	while(j<strlen(dizi1))
	{
		if(dizi1[j]==dizi2[j])
{
	d=1;
}
else 
{
    d=0;
    break;
}
j++;
	}

	if(d==1)
	{
		printf("dizi palandrom");
	}
	else
	{
		printf("dizi palandrom deil");
	}
	
return 0;	
}
