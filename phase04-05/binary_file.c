#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "binary_file.h"


int totNC = 0;
int totNS = 0;
int totNL = 0;
int totUF = 0;
int totIN = 0;
int totVA = 0;



struct userfunc * no_star(struct userfunc **old,struct userfunc *new){
	int i;

	new = (struct userfunc *)malloc(sizeof(struct userfunc)*totUF);
	for(i=0; i<totUF; i++){
		new[i].address = old[i]->address;
		new[i].localSize = old[i]->localSize;
		new[i].id = strdup(old[i]->id);
	}

	return new;
}

/////////////////enconding functions//////////////////////////////

int generate_bin_code(unsigned int quadCnt,instruction avm_incode ){
	int i;
	for( i=0; i<quadCnt+1; i++){
		fwrite(&avm_incode[i],sizeof(struct instruction),1,binary_ofile);
		
	}
	return 0;
}

int generate_number_table(double *numConsts,unsigned totalNumConsts){

	fwrite(&totalNumConsts,sizeof(int),1,binary_ofile);
	fwrite(numConsts,sizeof(double),totalNumConsts,binary_ofile);
	return 0;
}

int generate_string_table(char * stringConsts[],unsigned totalStringConsts){

	int i,j;
	fwrite(&totalStringConsts,sizeof(int),1,binary_ofile);
	
	for(i=0; i<totalStringConsts; i++){
		j=strlen(stringConsts[i])+1;
		fwrite(&j,sizeof(int),1,binary_ofile);
		fwrite(stringConsts[i],sizeof(char),j,binary_ofile);
	}
}

int generate_libfuns_table(char * nameLibFuncs[],unsigned  totalNameLibFuncs){

	int i,j;
	fwrite(&totalNameLibFuncs,sizeof(unsigned),1,binary_ofile);
		for(i=0; i<totalNameLibFuncs; i++){
		j=strlen(nameLibFuncs[i])+1;
		fwrite(&j,sizeof(int),1,binary_ofile);
		fwrite(nameLibFuncs[i],sizeof(char),j,binary_ofile);
	}

}

int generate_userfuns_table(userfunc * userFuncs, unsigned totalUserFuncs ){
	int i , j;

	funcTable = no_star(userFuncs,funcTable);
	fwrite(&totalUserFuncs,sizeof(unsigned),1,binary_ofile);

	for(i=0; i<totalUserFuncs; i++){

		j=strlen(funcTable[i].id)+1;		
		fwrite(&j,sizeof(int),1,binary_ofile);
		fwrite(funcTable[i].id,sizeof( char ),j,binary_ofile);

		fwrite(&(funcTable[i].localSize),sizeof(unsigned),1,binary_ofile);
		fwrite(&(funcTable[i].address),sizeof(unsigned),1,binary_ofile);
		
	}

}

int generate_bin_tables(struct userfunc **userFuncs,char *NameLibFuncs[],char *stringConsts[],double *numConsts,
						unsigned totalNumConsts,unsigned totalStringConsts,unsigned totalNameLibFuncs,unsigned totalUserFuncs
 ){
	
	generate_number_table(numConsts,totalNumConsts);
	generate_string_table(stringConsts,totalStringConsts);
	generate_libfuns_table(NameLibFuncs,totalNameLibFuncs);
	generate_userfuns_table(userFuncs,totalUserFuncs);
	
	return 0;
}

	


int create_binary( char *filename,struct userfunc **userFuncs,char *NameLibFuncs[],char *stringConsts[],double *numConsts,
						instruction avm_incode,int num_of_programm_vars,unsigned int quadCnt, unsigned totalNumConsts,unsigned totalStringConsts,unsigned totalNameLibFuncs,unsigned totalUserFuncs
 ){

	totUF = totalUserFuncs;
	int magic_number = 340200501;
	int num_of_instrs = quadCnt;
	
	if((binary_ofile = fopen(filename,"wb")) == NULL){
		fprintf(stdout,"Cannot open binary file for output\n");
		exit(1);
	}

	fwrite(&magic_number,sizeof(int),1,binary_ofile);
	fwrite(&num_of_programm_vars,sizeof(int),1,binary_ofile);
	fwrite(&num_of_instrs,sizeof(int),1,binary_ofile);
	generate_bin_tables(userFuncs,NameLibFuncs,stringConsts,numConsts,
						totalNumConsts,totalStringConsts,totalNameLibFuncs,totalUserFuncs);
	generate_bin_code(quadCnt,avm_incode);
	
	fclose(binary_ofile);
	return 0;
}



////////////////decoding functions////////////////////////////
double * get_bin_numConsts(void){//double *numTable){
	int i;
	fread(&totNC,sizeof(int),1,binary_ofile);
	numTable = (double *)malloc(totNC*sizeof(double));

	fread(numTable,sizeof(double),totNC,binary_ofile);
	//return numTable;
}


char ** get_bin_stringConsts(void){//char *strTable[]){
	int i,j;
	fread(&totNS,sizeof(int),1,binary_ofile);
	strTable = (char **)malloc(sizeof(char*)*totNS);
	
	for(i=0; i<totNS; i++){
		fread(&j,sizeof(int),1,binary_ofile);
		strTable[i] = (char *)malloc(j*sizeof(char));
		fread(strTable[i],sizeof(char),j,binary_ofile);
	}


	//return strTable;
	
}


struct userfunc *get_bin_userfuncs(void){//struct userfunc ** funcTable){
	int i,j;
	

	fread(&totUF,sizeof(int),1,binary_ofile);
	funcTable = (struct userfunc *)malloc(sizeof(struct userfunc)*totUF);
	

	for(i=0; i<totUF; i++){
		
		fread(&j,sizeof(int),1,binary_ofile);
		funcTable[i].id = (char *)malloc(j*sizeof(char));
		fread(funcTable[i].id,sizeof( char ),j,binary_ofile);

		fread(&(funcTable[i].localSize),sizeof(unsigned),1,binary_ofile);
		fread(&(funcTable[i].address),sizeof(unsigned),1,binary_ofile);

		
	}


	//return funcTable;

	
}


char ** get_bin_nameLibFuncs(void){//char * libFunTable[]){
	int i,j;
	
	fread(&totNL,sizeof(unsigned),1,binary_ofile);
	libFunTable = (char **)malloc(sizeof(char*)*totNL);
	
	
	for(i=0; i<totNL; i++){
		fread(&j,sizeof(int),1,binary_ofile);
		libFunTable[i]= (char *)malloc(j*sizeof(char));
		fread(libFunTable[i],sizeof(char),j,binary_ofile);
	}
	
	//return libFunTable;
	
}
struct instruction *get_bin_code(void){// struct instruction *instr_table ){
	int i;
	
	instr_table = (struct instruction *)malloc(sizeof(struct instruction)*totIN);
	for( i=0; i<totIN; i++){
		//instr_table[i] = (struct instruction *)malloc(sizeof(struct instruction)*totIN);
		
		fread(&instr_table[i],sizeof(struct instruction),1,binary_ofile);
		
	}
	//return instr_table;
}


int decode_binary(char *filename){//,double *numTable,char *strTable[],struct userfunc **funcTable,char *libFunTable[],struct instruction *instTable){
	int magic_number,num_of_instrs,num_of_programm_vars;
	int i;
	if((binary_ofile = fopen(filename,"rb")) == NULL){
		fprintf(stdout,"Cannot open binary file for input\n");
		exit(1);
	}

	fread(&magic_number,sizeof(int),1,binary_ofile);
	if( magic_number != 340200501 ){
		fprintf(stdout,"Bad binary file header.\nReconstruct binary.\n");
		fclose(binary_ofile);
		exit(1);
	}
	
	fread(&totVA,sizeof(int),1,binary_ofile);
	
	fread(&num_of_instrs,sizeof(int),1,binary_ofile);
	totIN = num_of_instrs;

	get_bin_numConsts();
	get_bin_stringConsts();
	get_bin_nameLibFuncs();
	get_bin_userfuncs();
	get_bin_code();
	fclose(binary_ofile);
	return num_of_instrs;	
}

