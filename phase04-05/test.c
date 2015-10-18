#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum malakia{
	ena,dyo
};

int main(){
	enum malakia m,z;
	FILE *tetete;
	m=ena;
	tetete=fopen("tete","wb");
	fwrite(&a,sizeof(char),1,tetete);
	fclose(tetete);
	
	tetete=fopen("tete","rb");
	fread(&b,sizeof(int),1,tetete);
	printf("b=%d\n",b);
	printf("sizeof m:%u",sizeof(m));
	fclose(tetete);
	return 0;
}
