#include <stdio.h>
#include<stdlib.h>

int main()
{
	
	FILE *dosya;
	char karakter;
	
	dosya=fopen("belge.txt","r");
	if(dosya==NULL)
	{
		printf("dosya olusturulamadi");
	}
	else
	{
		
		
		do
		{
			karakter=getc(dosya);
			if(karakter!=EOF)
			{
				putchar(karakter);
			}
			
		}while(karakter!=EOF);
		
		
		fclose(dosya);
		printf("\nokuma islemi tamamlandi");
	}
	
	
	return 0;
}
