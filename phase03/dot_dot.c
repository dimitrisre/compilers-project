#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Loading(){
	char a = '.';
	int i;
	int j;
	char fstr[100];
	
	
	for(j=5 ; j<6; j++){
		fprintf(stderr,"\033[1;3%dmInitializing parser\033[0m",j);
		//fprintf(stderr,fstr);
		sleep(1);
		
		for(i=0 ; i< 6; i++){
			fprintf(stderr,"\033[1;3%dm%c\033[0m",i,a);
			//fprintf(stderr,fstr,a);
			sleep(1);
		
		}
		for(i=0; i < 8; i++){
			fprintf(stderr,"\b \b");
		}
		for(i=0; i < strlen("Initializing parser");i++){
			fprintf(stderr,"\b \b");
		}
	}
	return;
}
