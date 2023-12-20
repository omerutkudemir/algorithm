#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char *cumle;

	cumle=(char *)malloc(50*sizeof(char));
	
	gets(cumle);
	
	int i;
	
	char gecici;
	
	for(i=0;i<strlen(cumle)/2;i++)
	{
		gecici=cumle[i];
		cumle[i]=cumle[strlen(cumle)-1-i];
		cumle[strlen(cumle)-1-i]=gecici;
}
	for(i=0;i<strlen(cumle);i++)
	{
		printf("%c",*(cumle+i));
	}
	
	free(cumle)
	
	return 0;
}
