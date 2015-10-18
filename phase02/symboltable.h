#ifndef _SYMBOLTABLE_H_
#define _SYMBOLTABLE_H_

typedef struct symbolTableRecord * S_entry;

int insert(  int Scope , char * name , int line , int V_or_F  );

int Lookup( char * name , int scope , int v_or_f );

void Hide( int );

void print();

void Init_symbolTable();

void destroy_symboltable();

char * create_funcName(char *name);

#endif
