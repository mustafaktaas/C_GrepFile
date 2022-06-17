#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int grepFile(char *fname, char *str) 
{
	FILE *fp , *fptr;
	int satir_no = 1;
	int son_durum = 0;
	char temp[512];

	if((fp = fopen(fname, "r")) == NULL) 
	{
		return(-1);
	}

    fptr = fopen("SatirNo.txt","a");   

    fprintf(fptr,"\n'%s' kelimesinin bulunduğu satırlar : ",str);

	while(fgets(temp, 512, fp) != NULL) { 
		if((strstr(temp, str)) != NULL) {     
            fprintf(fptr,"%d;  ",satir_no);
			son_durum++;			
		}      
		satir_no++;
	}

    	fclose(fp);
		fclose(fptr);

	if(son_durum == 0) {
		printf("Eşleşen kelime bulunamadı.\n\n");
	}
    else 
    {
        printf("'%s' kelimesi bu yazıda %d adet bulunuyor. Hangi satırlarda olduğunu öğrenmek için SatirNo.txt isimli dosyanın içerisine bakabilirsiniz.\n\n",str, son_durum);
    }
	
   	return(0);
}

int main(int argc, char *argv[]) {
	
	int sonuc; 
	system("clear");

    if (argc != 3 )
	{
	    printf(" WARNING!!! \n USAGE = ./grepFile testFile.txt lorem\n\n");
		exit(-1);
	}
	else
	{
		sonuc = grepFile(argv[1], argv[2]);
	}
		
	return(0);
}
