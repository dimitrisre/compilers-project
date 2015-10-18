#ifndef _SCOPES_H_
#define _SCOPES_H_


	int id_scope(char *, int , int , int);
	int local_id_scope(char *, int);
    int  fid_scope(char * name, int Scope, int upScope);
	int tableitem_scope(char * name, int Scope , int upScope );
	int global_id_scope(char *name, int Scope);



#endif
