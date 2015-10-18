#include"symboltable.h"
#include<stdio.h>
#include<stdlib.h>


extern int yylineno;
//extern int call_flag;

int id_scope(char *name,int Scope,int upScope,int upScope2){
	
	int cnt = 0;
	int search = 0;

	upScope=search_actFunc(Scope);

	
	
	if(upScope != -1)
		upScope2=search_actFunc(upScope);
	
	for(cnt=Scope; cnt>=upScope+1; cnt--){

		if ( lookup(name,cnt,1) ){
			search = 1;
			break;
		}

	}
	if( upScope != -1 ){
		
		if ( !lookup(name,upScope,2)    && !lookup(name,0,1)     &&
		   	 !lookup(name,upScope2+1,1) && !lookup(name,Scope,2) &&
		     search==0 ){
			 insert(Scope,name,yylineno,1);
			 return 1;
		}
		else{
				if( lookup(name,upScope,2)  ){
						fprintf(stderr,"Conflict : Redefinition of symbol:%s at line:%d\n",name,yylineno);
						return 0;
				}
				else if(lookup(name,upScope2+1,1) && !lookup(name,upScope+1,1) && upScope!=0 && (upScope - upScope2 > 1) ){
					fprintf(stderr,"Illegal use of formal argument of upper function:%s at line:%d\n",name,yylineno);
					return 0;
		    	}								
		}
	}
	else{
		if ( !lookup(name,Scope,1) && !lookup(name,Scope,2) &&
			 !lookup(name,0,1)     && !lookup(name,0,2) ){
					insert(Scope,name,yylineno,1);
					return 1;
		}
		else if( lookup(name,0,2) ){
			printf("Conflict : Redefinition of symbol: %s at line:%d\n",name,yylineno);
			return 0;
		}
		else{
			
			return 1;
		}
  	}

  	search = 0;
	return 1;
}


int local_id_scope(char *name, int Scope){

	if(Scope==0){
	   	fprintf(stderr,"error:local keyword in global scope at line:%d\n",yylineno);
		return 0;
	}
	else{
	  	if ( !lookup( name , Scope , 1 ) ){
			insert(Scope, name, yylineno, 1);
			return 1;
		}
	} 
    return 1;
}

int global_id_scope(char *name, int Scope){


	if(Scope==0){
		if( !lookup(name, 0, 1) &&	!lookup(name,0,2) ){
			
			insert(Scope,name,yylineno,1);
			return 1;
		}
	}
	else{
	  	if( !lookup(name, 0, 1) &&	!lookup(name,0,2)){
			
				fprintf(stderr,"Undifine symbol:%s at line:%d\n",name,yylineno);
				return 0;
		}
	}
}

int tableitem_scope(char * name, int Scope , int upScope ){

	if( upScope != -1 ){
		
			if( !lookup(name,upScope+1,1) && !lookup(name,Scope,1) && !lookup(name,0,1) )
						insert(Scope,name,yylineno,1);
						
			
	}
	else if( !lookup( name,Scope,1 ) && !lookup(name,0,1) )
	             		insert(Scope,name,yylineno,1);
											
    return 1;

}

int fid_scope(char * name, int Scope, int upScope){
	
	if(upScope!=-1){

		if( !lookup(name,Scope,2) && !lookup(name,0,2)
			&& !lookup(name,Scope,1) && !lookup(name,0,1)){
			insert(Scope,name,yylineno,2);
			return 1;
		}
		else{
			fprintf(stderr,"Redifine symbol:%s at line:%d\n",name,yylineno);
			return 0;
		}
   }	
   else if( !lookup(name,Scope,2) && !lookup(name,0,2) &&  !lookup(name,Scope,1) && !lookup(name,0,1) ){
		insert(Scope,name,yylineno,2);
		return 1;
   }
   else{
		fprintf(stderr,"Redifine symbol:%s at line:%d\n",name,yylineno);
		return 0;
   }
   return 1;

}
