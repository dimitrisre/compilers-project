/* <<<<<<<<<<<<b_scanner.c>>>>>>>>>>
 *
 * Papakwnstantinou Artemis		am:1564  email:artpap@csd.uoc.gr
 * Tsolis Dimitrios 			am:1613  email:tsolis@csd.uoc.gr
 * Sebepou Zoi      			am:1563  email:sebepou@csd.uoc.gr
 *
 */



#include "b_scanner.h"
#include "b_token.h"


extern FILE * input, * output;

/*---------alpha_yylex---------
 *Basiki synartisi leksikografikis analyshs.
 *
 * Orismata:
 * 			void * yylval: Pointer stin domi apothikeysis toy ekastote
 * 						   token
 * Epistrefei:
 * 			int  :Typos toy token
 *
 */

int alpha_yylex( void * yylval ){
	
	int state = 0;
	char c;
	while(1){
		
		/* Ean to lookAhead einai 1 tote pare tin eisodo apo ton pinaka
		 * lookAhead
		 */

		if( useLookAhead==1 ){

			c=lookAhead[l_a_cnt-1];
			l_a_cnt--;

			if(l_a_cnt == 0){

				useLookAhead=0;
				l_a_cnt = 0;
			}
		}
		else{

			c=fgetc(input);
		
			if( feof( input ) ){

				if( (OpenCom1 > CloseCom1) || (OpenCom2 > CloseCom2) ){
					fprintf(output,"Unfinished comments\n");
				}
				return ENDOF;
			}
		}
		

		state = automatic[state](c);
		
		if ( is_token(state) ){
		
			lexeme[pos]='\0';

			if ( state==INTCONST){
				((ALP)yylval)->int_value = atoi( lexeme );
			} 
			else if ( state==FLOATCONST ){
				((ALP)yylval)->d_value = atof( lexeme );
			}
			else{	
				((ALP)yylval)->s_value=(char *)malloc((strlen(lexeme)+1)*sizeof(char));
				strcpy(((ALP)yylval)->s_value,lexeme);
				if(state==ID){
					state=is_keyword(lexeme);
				}
			}
			if ( state==STRING ){
				((ALP)yylval)->lineno=lineno-tmp_lineno;
			}
			else{
				((ALP)yylval)->lineno=lineno;
			}
			((ALP)yylval)->type=state;
			

									
			pos=0;
			return state;

		}
		
		else if(state==ILLEGAL){

			((ALP)yylval)->lineno=lineno;
			((ALP)yylval)->type=state;
			lexeme[pos]='\0';
			((ALP)yylval)->s_value=(char *)malloc((strlen(lexeme)+1)*sizeof(char));
			
			strcpy(((ALP)yylval)->s_value,lexeme);
			pos=0;

			return ILLEGAL;
		}
			
		
	}
	
}

/*----------state0------------
 *Ylopoiei tin arxiki katastasi toy aytomatoy 
 *toy leksikografikoy analyti.
 *
 *Orismata:
 *			char ch:O epomenos xaraktiras apo tin eisodo
 *
 * Epistrefei:
 * 			int  :Tin epomeni katastasi toy aytomatoy stin alpha_yylex
 *
 *
 */
int state0(char ch){
	
	
	if(ch=='['){
	
		
		lexeme[pos++]=ch;
				
	return L_BR;
	}			
	else if( ch == ']' ){
	
			lexeme[pos++]=ch;
			return R_BR;
	}
	else if ( ch == '{' ){
		
			lexeme[pos++]=ch;
			return L_AG;
	}
	else if ( ch == '}' ){
		
			lexeme[pos++]=ch;
			return R_AG;
	}
	else if ( ch == ';' ){
		
			lexeme[pos++]=ch;
			return SEMICOL;
	}
	else if ( ch == '.' ){			
		
			lexeme[pos++]=ch;
			return FULLST;
	}
	else if ( ch == ':' ){			
		
			lexeme[pos++]=ch;
			return D_FULLST;
	}
	else if ( ch == ',' ){
		
			lexeme[pos++]=ch;
			return COMMA;
	}
	else if ( ch == '\n' ){
	
		lineno++;
		return STATE(0);
	
	}
	else if ( isspace((int)ch) != 0 ){
		
	
		return STATE(0);
	}
	else if ( ch == '=' ){
		
		lexeme[pos++]=ch;
		return STATE(1);
	}
	else if ( ch == '+' ){
		
		lexeme[pos++] = ch;
		return STATE(2);
	}	
	else if( ch == '-')
	{
		lexeme[pos++] = ch;
		return STATE(3);
	}
	else if( ch == '<'){
		lexeme[pos++] = ch;
		return STATE(4);
	}			
	else if( ch == '>'){
		lexeme[pos++] = ch;
		return STATE(5);
	}	
	else if( ch == '%'){
		lexeme[pos++] = ch;
		return MOD_OP;
	}
	else if( ch == '!'){
		lexeme[pos++] = ch;
		return STATE(6);
	}
	else if( isdigit((int)ch)!=0){		
		 lexeme[pos++] = ch;
		 return STATE(7);
		
	}
	else if ( ch == '.' ){
		lexeme[pos++] = ch;
		return FULLST;
	}
	else if( isalpha((int)ch) != 0 || ch=='_'){
		lexeme[pos++] = ch;
		return STATE(10);
	}
	else if ( ch == '\"' ){
		lexeme[pos++] = ch;
		return STATE(11);
	}
	else if ( ch == '#' ){
		fprintf(output,"Ignored # commnets\n");
		return STATE(12);
	}
	else if( ch == '/'){
		lexeme[pos++] = ch;
		return STATE(13);
	}
	else if( ch == '*'){
		lexeme[pos++] = ch;
		return MULL_OP;
	}
	else if( ch == '('){
		lexeme[pos++] = ch;
		return STATE(17);
	}
	else if( ch == ')' ){
		lexeme[pos++] = ch;
		return R_PAR;
	}
	else{
		lexeme[pos++] = ch;
		return ILLEGAL;
	}
	
	
}

/*--------state1->state20-------
 * Ylopoioyn tis diafores katastasis toy aytomatoy 
 *analoga me ton epomeno xaraktira eisodoy.
 *
 *
 */

int state1(char c){

	switch(c){

		case '=':
			lexeme[pos++]=c;
			return EQ_OP;

		default:
			Retract(c);
			return ASS_OP;
	}

}

int state2 ( char c ){

	switch ( c ){

		case '+':
			lexeme[pos++] = c;
			return PLUSPLUS_OP;
		default:
			Retract(c);
			return PLUS_OP;
		}
}

int state3 ( char c ){

	switch ( c ){

		case '-':
				lexeme[pos++] = c ;
				return SUBSUB_OP;
		default:
				Retract( c );
				return SUB_OP;
	}
}

int state4 ( char c ){

	switch ( c ){

		case '=':
				lexeme[pos++] = c;
				return LEQ_OP;
		default:
				Retract ( c );
				return LESS_OP;

	}			
}

int state5 ( char c ){

	switch ( c ){

		case '=':
				lexeme[pos++] = c;
				return GEQ_OP;
		default:
				Retract ( c );
				return GRE_OP;
		}
}

int state6 ( char c ){

	switch ( c ){
			
			case '=':
				lexeme[pos++] = c;
				return NEQ_OP;
			default:
				Retract( c );
				return ILLEGAL;
	}
}

int state7 ( char c){

	if ( isdigit((int)c) != 0 ){ 
		lexeme[pos++]=c;
		return STATE(7);
	}
	else if( c == '.' ){
					
		lexeme[pos++]='.';
		return STATE(8);
	}
	
	else{
		Retract( c );
		return INTCONST;

	}
	
}

int state8( char c ){
	
	if(isdigit((int)c)!=0){
		
		lexeme[pos++] = c;
		return STATE(9);
	}
	else{
	
		Retract(c);
		pos--;
		Retract(lexeme[pos]);
		return INTCONST;
	}
}

int state9( char c ){

	if(isdigit((int)c)!=0){

		lexeme[pos++]=c;
		return STATE(9);
	}
	else{

		Retract(c);
		return FLOATCONST;
	}

}

int state10( char c ){

	if ( isalnum((int)c) != 0 || c == '_' ){

		lexeme[pos++] = c;
		return STATE(10);
		
	}
	else{
		Retract(c);
		return ID;
	}
}

int state11( char c ){

   
   if ( isascii(c) != 0 && c != '\"' && c !='\\' && c != '\n' ){
	
		stringflag = 0;
		lexeme[pos++] = c;
		return STATE(11);
	}
	else if ( c == '\n' ){

		//lexeme[pos++] = c;
		tmp_lineno++;
		lineno++;
		return STATE(11);
	}
	else if ( c == '\\' ){

			stringflag=1;
			lexeme[pos++] = c;
			return STATE(11);
	}
	else if( stringflag == 1 && c == '\"' ){
	
		stringflag = 0;
		lexeme[pos++] = c;
		return STATE(11);
	}	
	else if ( c == '\"' && stringflag == 0 ){
		lexeme[pos++] = c;
		return STRING;
	}
	return ILLEGAL;

}

int state12(char c ){
		
	if( c!='\n' ){

		return STATE(12);
	}
	else{

		lineno++;
		return STATE(0);
	}
	
}

int state13( char c ){

	if(c == '/'){

		pos = 0;
		fprintf(output,"Ignored // comments\n");
		return STATE(12);
	}
	else if ( c != '*'){
		Retract(c);
		return DIV_OP;
	}
	else{
		pos = 0; 
		OpenCom1++;
		fprintf(output,"Start ignoring comments 1.\n");
		if ( comFlag_2 == 0 ){

				comFlag_1 = 1;
		}
		return STATE(14);   			//Metavash sth state14 ( arxikh twn "/*  */" )
	}
	
}

int state14( char c ){

	if( c!='*' && c != '/' && c !='\n' && c != '(' ){

		return STATE(14);
	}
	else if(c == '*'){

		return STATE(15);
	}
	else if( c == '\n' ){

		lineno++;
		return STATE(14);
	}
	else if( c == '/'){

		return STATE(16);
	}
	else if ( c == '('){
		
		return STATE(20);
	
	}
	else{
		return STATE(14);
	}

}

/*-----------state15--------------
 * Elegxei to telos sxoliwn
 * xrhsimopoiwntas thn Call_back
 * gia epistrofh sthn state0 'h gia paramonh
 * stis katastaseis twn sxoliwn.
 *
 */
int state15( char c ){

	if( c == '/'){

		CloseCom1++;
		
	}
	else if( c == ')'){
		CloseCom2++;
				
	}
	return STATE(Call_back());
	
}

int state16( char c ){

	if(c == '*'){

		OpenCom1++;
		
	}
	return STATE(14);

}

int state17( char c ){
	
	if ( c != '*'){
		Retract(c);
		return L_PAR;
	}
	else{
		pos = 0;
		fprintf(output,"Start igoring comments 2.\n");
		OpenCom2++;
		if ( comFlag_1 == 0 ){

				comFlag_2 = 1;
		}
		return STATE(18);   			// Arxikh twn  " (*   *) " sxoliwn
	}
}

int state18( char c ){

	if( c!='*' && c != '(' && c !='\n' && c != '/'){
		return STATE(18);
	}
	else if(c == '*'){
		return STATE(19);
	}
	else if( c == '\n' ){
		lineno++;
		return STATE(18);
	}
	else if( c == '('){
		return STATE(20);
	}
	else if ( c == '/' ){
		return STATE(16);
	}
	else{
		return STATE(18);
	}
}


/*--------state19---------------
 * Omoia leitourgia me state15
 *
 */

int state19( char c ){

	if( c == ')'){

		CloseCom2++;
		
	}
	else if( c == '/'){
		CloseCom1++;
				
	}
	return STATE(Call_back());
	
}

int state20( char c ){

	if(c == '*'){
		OpenCom2++;
	}
	return STATE(18);
} 


/*~.~.~.~.~.~.~.BOHTHIKES SYNARTISEIS.~.~.~.~.~.~.~*/
/* Xrisimopoieitai gia epanafora stin state 0 'h sth state 14 k 18.
 *   Ta comFlag_1 & comFlag_2 einai anamena otan ta arxika sxolia einai ( / * )
 * 'h ( ( * ) antistoixa.
 * 	  An kleisoyn ( counters twn opening == counters twn closing )
 * ,paraleipontai ta eswterika anoigmata 'h kleisimata
 * ta opoia den kanoun match me to styl sxoliwn pou deixnei to anameno
 * flag. 
 *
 */
int Call_back(){

	if ( (OpenCom1 != CloseCom1) && ( comFlag_1 == 1 ) && (comFlag_2 == 0 )){
		return STATE(14);
	}
	else if ( (OpenCom1 == CloseCom1) && ( comFlag_1 == 1 ) && (comFlag_2 == 0)) {
		comFlag_1 = 0;
		OpenCom1  = 0;
		OpenCom2  = 0;
		CloseCom1 = 0;
		CloseCom2 = 0;
		fprintf(output,"Finished ignoring comments 1.\n");
		return STATE(0);
	}
	else if ( (OpenCom2 != CloseCom2) && ( comFlag_1 == 0 )  && (comFlag_2 == 1)){
		return STATE(18);
	}
	else if ( (OpenCom2 == CloseCom2) && ( comFlag_1 == 0 ) && (comFlag_2 == 1)){
		comFlag_2 = 0;
		OpenCom2  = 0;
		OpenCom1  = 0;
		CloseCom2 = 0;
		CloseCom1 = 0;
		fprintf(output,"Finished ignoring comments 2.\n");
		return STATE(0);
	}

	return ILLEGAL;	
}

/*---------Retract----------
 * Anabei to flag useLooAhead wste o epomenos xaraktiras na min einai 
 * apo tin eisodo alla apo ton pinaka lookAhead pinaka o opoios krataei 
 * toys xaraktires poy eginan Retract.
 *
 * Parametroi:
 * 				char c : O xaraktiras poy tha ginei Retract
 *
 */
void Retract(char c){

	
	useLookAhead = 1;
	lookAhead[l_a_cnt++] = c;
	
}


/*------------is_token--------------
 *Elegxei an i katastasi toy aytomatoy einai teliki
 *
 *Parametroi:
 *			int st : To state pros elegxo 
 *
 *Epistrefei:
 *			int   : 1 ean einai teliki alliws 0		
 *
 */
int is_token(int st){

	if(st>=INTCONST && st<=D_FULLST){
		return 1;
	}
	return 0;
}

/*----------is_keyword-----------
 *Ksexorizei ta identifiers apo ta keywords
 *
 * Parametroi:
 * 			char *lex : To lexeme poy epistepse to aytomato
 * 
 * Epistrefei:
 * 			int  : Ton typo toy keyword alliws IDENTIFIER
 */
int is_keyword( char *lex ){
	
	if ( strcmp(lex,"if") == 0 ){
		return IF_KEYWORD;
	}
	else if ( strcmp(lex,"for") == 0 ){
		return FOR_KEYWORD;
	}
	else 	if ( strcmp(lex,"else") == 0 ){
		return ELSE_KEYWORD;
	}
	else if ( strcmp(lex,"function") == 0 ){
		return FUNCTION_KEYWORD;
	}
	else if ( strcmp(lex,"while") == 0 ){
		return WHILE_KEYWORD;
	}
	else if ( strcmp(lex,"return") == 0 ){
		return RETURN_KEYWORD;
	}
	else if ( strcmp(lex,"break") == 0 ){
		return BREAK_KEYWORD;
	}
	else if ( strcmp(lex,"continue") == 0 ){
		return CONTINUE_KEYWORD;
	}
	else if ( strcmp(lex,"true") == 0 ){
		return TRUE_KEYWORD;
	}
	else if ( strcmp(lex,"false") == 0 ){
		return FALSE_KEYWORD;
	}
	else if ( strcmp(lex,"nil") == 0 ){
		return NIL_KEYWORD;
	}
	else if ( strcmp(lex,"and") == 0 ){
		return AND_KEYWORD;
	}
	else if ( strcmp(lex,"or") == 0 ){
		return OR_KEYWORD;
	}
	else if ( strcmp(lex,"not") == 0 ){
		return NOT_KEYWORD;
	}
	else if ( strcmp(lex,"global") == 0 ){
		return GLOBAL_KEYWORD;
	}
	else if ( strcmp(lex,"local") == 0 ){
		return LOCAL_KEYWORD;
	}
	else{
		return ID;
	}
	
}



//END OF b_scanner.c
