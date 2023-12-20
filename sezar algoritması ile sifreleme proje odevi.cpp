#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ogrenci
{
     char birlesmis_ad[70];
     char sifrelenmis_ad[70];
     int sifreyi_cozumleyecek_sayi;
     int ogrenci_no;
	
};
void sifreleme(struct ogrenci *bilgi)
{
	int i;
	
     
	for(i=0;i<strlen(bilgi->birlesmis_ad);i++)
	{
	 	bilgi->sifrelenmis_ad[i]=bilgi->birlesmis_ad[i]+=7;
	
	}
	
}
void dosyaya_yazma(struct ogrenci *bilgi)
{
	FILE *dosya;
	dosya=fopen("sifrelimetin.txt","w");
	
	int i;
	if(dosya==NULL)
	{
		printf("dosya kayıtlı degil");
	}
	else
	{
		fprintf(dosya,"%s",bilgi->sifrelenmis_ad);
		
	}
	fclose(dosya);
	printf("\n\nsifreli ad soyad birlestirilip olusturulmus dosyaya eklendi");
	
}
void enbuyuk_asalcarpan_bulma(struct ogrenci *bilgi)
{
	int i,j,k=0,m=0;
	int tum_carpanlar[100];
	int asal_carpanlar[100];
	int enbuyuk_asal_carpan;
	printf("\n\nogrenci numaranizi giriniz: ");
	scanf("%d",&bilgi->ogrenci_no);
	
	for(i=1;i<=bilgi->ogrenci_no;i++)
	{
	    if(bilgi->ogrenci_no%i==0)
	    {
	    	tum_carpanlar[k]=i;
	    	k++;
		}
	}
	for(i=0;i<k;i++)
	{
		for(j=2;j<tum_carpanlar[i];j++)
		{
			
			if(tum_carpanlar[i]%j!=0)
			{
				asal_carpanlar[m]=tum_carpanlar[i];
			}
			
			
			else
			{
				asal_carpanlar[m]=0;
				break;
			}	
		}	
		if(tum_carpanlar[i]==2)
		{
			asal_carpanlar[m]=2;
			}	
		m++;
	}
	enbuyuk_asal_carpan=asal_carpanlar[0];
	for(i=1;i<m;i++)
	{
		if(asal_carpanlar[i]>enbuyuk_asal_carpan)
		{
			enbuyuk_asal_carpan=asal_carpanlar[i];
		}		
	}
	bilgi->sifreyi_cozumleyecek_sayi=enbuyuk_asal_carpan;	
}
void dosyadan_okuma(struct ogrenci *bilgi)
{
	int i=0,j;
	char karakter;
	
	FILE *dosya;
	dosya=fopen("sifrelimetin.txt","r");
	
	if(dosya==NULL)
	{
		printf("dosya bulunamadi");
	}
	else
	{
		printf("dosyadaki sifreli metin: ");
			do
		{
			karakter=getc(dosya);
			if(karakter!=EOF)
			{
				
				putchar(karakter);
				
		    }
	}while(karakter!=EOF);
	fclose(dosya);
	}
}
void sifre_cozumleme(struct ogrenci *bilgi)
{
	int i;
	char sifresi_cozulmus_ad[70];
	printf("\n\nsifresi cozumlus metin : ");
	for(i=0;i<strlen(bilgi->sifrelenmis_ad);i++)
	{
		bilgi->sifrelenmis_ad[i]-=7;
		printf("%c",bilgi->sifrelenmis_ad[i]);
	}
	printf("\nogrenci numarasi : %d",bilgi->ogrenci_no);
	
}

int main()
{
   struct ogrenci bilgi;
   int ebac;//en buyuk asal carpan
   	char isim[35];
	char soyisim[35];
	printf("isim giriniz: ");
    gets(isim);
    printf("soyisim giriniz: ");
    gets(soyisim);
	
	strcpy(bilgi.birlesmis_ad,strcat(isim,soyisim));//string birlestirme 
	
	sifreleme(&bilgi);
    dosyaya_yazma(&bilgi);
    
    enbuyuk_asalcarpan_bulma(&bilgi);
    
    while(1)
    {
    	printf("\n\noogrenci numaranizin en buyuk asal carpani nedir:");
        scanf("%d",&ebac);
    	if(ebac==bilgi.sifreyi_cozumleyecek_sayi)
       {
       	dosyadan_okuma(&bilgi);
    	sifre_cozumleme(&bilgi);
    	
    	break;
	    }
	    else
	    {
		printf("parola yanlis tekrar deneyiniz");
	     }
	}
	return 0;
}
