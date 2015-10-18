#ifndef _SYMBOLTABLE_H_
#define _SYMBOLTABLE_H_





typedef struct symbolTableRecord * S_entry;

int insert(  int Scope , char * name , int line , int V_or_F  );

int Lookup( char * name , int scope , int v_or_f );

void Hide( int );

void print();

void Init_symbolTable();

void destroy_symboltable();

char * create_funcName( void );

void reset_fun_cnt(void);

enum scopespace_t currScopeSpace(void);

S_entry find_rec( char *, int , int  );

char * find_name( S_entry , int);

int    find_func( S_entry );


int insert_arguments( int scope );

#endif
