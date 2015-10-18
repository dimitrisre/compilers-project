#ifndef _B_SCANNER_H_
#define _B_SCANNER_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<ctype.h>
#define MAX_LEXEME 2048
#define STATE(x) x

//Prototypa synartiseon

int state0( char );
int state1( char );
int state2( char );
int state3( char );
int state4( char );
int state5( char );
int state6( char );
int state7( char );
int state8( char );
int state9( char );
int state10( char );
int state11( char );
int state12( char );
int state13( char );
int state14( char );
int state15( char );
int state16( char );
int state17( char );
int state18( char );
int state19( char );
int state20( char );


//Boi8itikes Synarthseis 

int is_token  (  int   );
int Call_back (  void  );
int is_keyword(  char *);
void Retract  (  char  );

int pos = 0 ; 		//I current thesi sto lexeme
char lexeme[MAX_LEXEME];

/*Pinakas katastasewn
 *
 */
int (*automatic[])(char)={
						  state0,state1,state2,state3,state4,state5,state6,state7,
						  state8,state9,state10,state11,state12,state13,state14,
						  state15,state16,state17,state18,state19,state20
						  };


int    lineno = 1 , tmp_lineno = 0; //tmp_lineno: metavliti gia ton 
									//ypologismo tis grammis emfanisis toy string
int    useLookAhead = 0 , l_a_cnt = 0;
char   lookAhead[2] = { 0 , 0 };
int    stringflag = 0;
int    comFlag_1  = 0 , comFlag_2 = 0;
size_t OpenCom1 = 0 , CloseCom1 = 0 , OpenCom2 = 0 , CloseCom2 = 0 ;

#endif
