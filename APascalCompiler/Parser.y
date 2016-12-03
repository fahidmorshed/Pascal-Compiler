%{


#include <stdio.h>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
#include "symboltable.h"


///////////////////////////////////////
void yyerror(char *);
extern int yyparse();
extern int yylex(void);
extern int linecount ; // declared in the lex file
/////////////////////////////////


//varibales for data segment 
SymbolInfo* variable[111];

//////////////////////temp variables/////////////////
char strTemp[10];
char strLabel[10];

SymbolTable st; /////////////symbol table


char strRes[10];
char bss[1000];
char data[10000];

int counter = 0; //number of variables

//Give name to temp variable
char* newTemp(){
	
	static int i = 1;
	
	//ItoA(i);
	sprintf(strRes,"%d",i) ;
	
	strcpy(strTemp,"temp");
	strcat(strTemp,strRes);
	
	strcat(bss,strTemp);
	strcat(bss," resd 1\n");
	
	i++;
	return strTemp;
}

//Give name to new label
char* newLabel(){

	static int i = 1;
	
	//ItoA(i);
	sprintf(strRes,"%d",i) ;
	strcpy(strLabel,"label");
	strcat(strLabel,strRes);

	i++;
	return strLabel;
}



%}

%union {
	int ival;
	double dval;
	char string[100];
	SymbolInfo *symp;
}


%nonassoc IF
%nonassoc ELSE

%token  PROGRAM BEGIN1 END VAR ARRAY OF DOTDOT INTEGER REAL
%token  <symp>	ID
%token	DO IF THEN ELSE WHILE
%token	NOT RELOP MULOP OR AND UNARY ASSIGNOP
%token	PROCEDURE FUNCTION WRITE
%token 	<dval>	NUM
%token	<ival>	MULOP
%token	<string> 	RELOP

%type 	<symp> 	expression simple_expression term factor statement
%type	<symp>	variable  statement_list optional_statements compound_statement

%left  RELOP 
%left OR '+' '-'
%left MULOP '*' '/'
%nonassoc UMINUS


%%
program : PROGRAM ID'('identifier_list')' ';' 
		declarations 
		subprogram_declarations 
		compound_statement
		{

			printf("In Program --> Start of Production Rule\n");
		}
		;
	
identifier_list : ID{
				static int i = 1;

				printf("In identifier_list :ID \n");
				if($1->typeVal){
					
					variable[counter] = (SymbolInfo *)malloc(sizeof(SymbolInfo));
					variable[counter++] = $1;
					
					//building section.bss
					if(i++ <= 1){
						strcpy(bss,$1->symbol);
						strcat(bss," resd 1\n");
					}
					else{
						strcat(bss,$1->symbol);
						strcat(bss," resd 1\n");
					}
					
					//printf("In identifier list: bss is now\n%s\n",bss);
				}
				
				//printf("The pointer for %s is %p\n",$1->symbol,$1);	
				
		}
		| identifier_list ',' ID{
		
				printf("In identifier_list ',' ID \n");
				if($3->typeVal){
					
					
					variable[counter] = (SymbolInfo *)malloc(sizeof(SymbolInfo));
					variable[counter++] = $3;
					
					//building section.bss
					
					strcat(bss,$3->symbol);
					strcat(bss," resd 1\n");
					
					//printf("In identifier list: bss is now\n%s\n",bss);
					//printf("The pointer for %s is %p\n",$3->symbol,$3);
				}
		}
		;
		
declarations	:	declarations VAR identifier_list':' type ';' 	
			{
				printf("This is the declaration\n");
			}
		|	{
				printf("No Declaration\n");
			}
		;
			
type	:	standard_type	
		{
			printf("type : standard_type\n");
			counter = 0;
		}
	|	ARRAY '[' NUM DOTDOT NUM ']' OF standard_type	
		{
			printf("type : ARRAY [ num .. num ] of standard_type\n");
			//printf("Lower index %0.lf , Upper index %0.lf\n",$3,$5);
		}
	;
	
standard_type	:	INTEGER	{	
				printf("standard_type :  integer\n");
				
				for(int i = 0 ; i < counter ; i++){
					strcpy(variable[i]->dataType,"INTEGER");
				}
				counter = 0;
			}
		|		REAL		{	
				printf("standard_type is REAL\n");
				
				for(int i = 0 ; i < counter ; i++){
					strcpy(variable[i]->dataType,"REAL");
				}
				counter = 0;
			}
		;

	
subprogram_declarations	:	subprogram_declarations subprogram_declaration ';'
				{
					printf("subprog_declarations : subprog_declarations subprogram declarations ;\n");
				}
			|	
				{
					printf("subprogram declarations :  empty\n");
				}
			;
			
subprogram_declaration	:	subprogram_head declarations compound_statement
				{
					printf("subprog_declaration :subprogram_head declarations compound_statement \n");
				}
			;
	
subprogram_head		:	FUNCTION ID arguments ':' standard_type ';'
				{
					printf("subprogram_head		:	FUNCTION ID arguments ':' standard_type ';'\n");
				}
			|	PROCEDURE ID arguments ';' 
				{
					printf("subprogram  head : procedure ID agrguments;\n");
				}
			;
		
arguments	:	'(' parameter_list ')' 
			{
				printf("arguments : ( parameter_list )\n");
			}
		|	
			{
				printf("arguments :  empty\n");
			}
		;
		
parameter_list	:	identifier_list ':' type	
			{
				printf("parameter_list : type\n");
			}
		|	parameter_list ';' identifier_list ':' type 
			{
				printf("parameter_list ; parameter_list ';' identifier_list ':' type\n");
			}
		;
		
compound_statement	:	BEGIN1
				optional_statements
				END 		{
					printf("\ncompound_statement  : BEGIN1\n\toptional_statements\n\tEND\n");
					SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
					
					strcpy(temp->code,$2->code);
					
					$$=temp;
				}
			;
			
optional_statements	:	statement_list
				{
					printf("optional_statements	:	statement_list\n");
					
					
					SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
					strcpy(temp->code,$1->code);
					
					$$=temp;
				} 
			|	{
					//printf("optional-statement empty \n");
				}
			;
statement_list	:	statement
			{
			
				printf("statement_list	:	statement\n");
				
				SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
				strcpy(temp->code,$1->code);
				
				//printf("The code %s\n",$1->code);
				
				$$=temp;
				
				
			} 
		|	statement_list ';' statement	
			{
				printf("statement_list	: : statement_list ';' statement\n");
				//printf("The symbol now %s\n",$3->symbol);
				
				SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
				//temp = st.Lookup("Code","Help");

				//strcat(data,$3->code);				
							
				//printf("---------------------------------\nThe Code for $1 \n%s\n",$1->code);			
				//printf("---------------------------------\nThe Code for $3 \n%s\n",$3->code);			
				
				strcpy(temp->code,$1->code);
				strcat(temp->code,$3->code);
				
				strcpy(data,temp->code);
				
				$$ = temp;
			}
		;

		
statement	:	variable ASSIGNOP expression
			{
			
				//Fine, it is working well
				//mov eax,3
				//or
				//mov dword[x],eax

			
				printf("statement	:	variable ASSIGNOP expression\n");

			
				if($3->numVal){
					$1->value = $3->value;
					
					//adding previous codes
					strcpy($1->code,$3->code);
					
					//generating new code
					
					
					strcat($1->code,"mov eax,");
					//ItoA($3->value);
					sprintf(strRes,"%d",$3->value) ;
					strcat($1->code,strRes);
					strcat($1->code,"\n");
					strcat($1->code,"mov dword[");
					strcat($1->code,$1->symbol);
					strcat($1->code,"],");
					strcat($1->code,"eax\n");
					
					
					printf("The code is %s",$1->code);
				}
			
				else{
					$1->value = $3->value;
					
					//adding previous codes
					strcpy($1->code,$3->code);
					
					//generating new codes
					strcat($1->code,"mov eax,dword[");
					strcat($1->code,$3->symbol);
					strcat($1->code,"]\n");
					strcat($1->code,"mov dword[");
					strcat($1->code,$1->symbol);
					strcat($1->code,"],eax\n");
					
					//printf("The code is %s",$1->code);
				}
				
				SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
				//temp = st.Insert("Code","Help");
				strcpy(temp->code,$1->code);
				strcpy(temp->symbol,$1->symbol);
				
			//	printf("The pointer for %s is %p\n",$1->symbol,$1);
			//	printf("Before passing the code is %s\n",$1->code);

				$$ = temp;
				
				
			}	
			
		|	WRITE '(' ID ')'
			{
				//printf("In write id\n");
				
				SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
				temp->code[0] = '\0';
				
				//mov eax,[x]
				//push eax
				//call printFunc
				//pop eax
				
				strcat(temp->code,"\nmov eax,dword[");
				strcat(temp->code,$3->symbol);
				strcat(temp->code,"]\n");
				strcat(temp->code,"push eax\n");
				strcat(temp->code,"call printFunc\n");
				strcat(temp->code,"pop eax\n");
				
				$$=temp;
			}	
			
		|	procedure_statement	
			{
				printf("statement -> procedure_statement\n");
			}
		|	compound_statement	
			{
				printf("statement -> compound_statement\n");
			}
		|	IF expression THEN statement  %prec IF
			{
				printf("statement -> if exp then statement\n");
				
				char tempLabel[10];
				char string[1000];
				
				strcpy(string,$4->code);
				
				SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
				temp->code[0] = '\0';
				strcat(temp->code,$2->code);			//add code from expression
				
				
				newLabel();
				strcpy(tempLabel,strLabel);			//keeping backup
				
								
				strcat(temp->code,$2->branchInfo);		//cmp x,y; jg label1; 
				strcat(temp->code," ");
				strcat(temp->code,strLabel);
				strcat(temp->code,"\n");
				
				strcat(temp->code,"jmp ");			//jmp label2
				newLabel();						
				strcat(temp->code,strLabel);
				strcat(temp->code,"\n\n");
				
				strcat(temp->code,tempLabel);			//label1:
				strcat(temp->code,":\n\n");			
				
				strcat(temp->code,string);			//code for statement
			
				strcat(temp->code,strLabel);			//label2:
				strcat(temp->code,":\n\n");	
			
			
				$$ = temp;				
			}
		|	IF expression THEN statement ELSE statement	
			{
				printf("statement -> if exp then statement else statement\n");
				
				char temp1[100],temp2[100];
				char tempLabel[10];
				
				printf("And in if-else the address $4-> %p,name %s,code %s\n",$4,$4->symbol,$4->code);
				strcpy(temp1,$4->code);
				strcpy(temp2,$6->code);
				
				printf("$4->code %s\n",$4->code);
				printf("$6->code %s\n",$6->code);
				
				
				SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
				temp->code[0] = '\0';
				
				
				//adding code for expression
				strcat(temp->code,$2->code);
				
				newLabel();
				strcpy(tempLabel,strLabel);
				strcat(temp->code,$2->branchInfo);		// jg label1; 
				strcat(temp->code," ");
				strcat(temp->code,strLabel);
				strcat(temp->code,"\n");
				
				strcat(temp->code,"jmp ");			//jmp label2
				newLabel();						
				strcat(temp->code,strLabel);				
				strcat(temp->code,"\n\n");
				
				strcat(temp->code,tempLabel);			//label1:
				strcat(temp->code,":\n\n");
				
				strcat(temp->code,temp1);			//code under label1
				
				strcpy(tempLabel,strLabel);
				
				strcat(temp->code,"jmp ");			//jmp label3(skipping label2:)
				newLabel();
				strcat(temp->code,strLabel);	
				strcat(temp->code,"\n\n");		
				
				strcat(temp->code,tempLabel);			//label2:
				strcat(temp->code,":\n\n");
				strcat(temp->code,temp2);			//code under label2
				
				strcat(temp->code,strLabel);			//label3:
				strcat(temp->code,":\n\n");
			
				$$ = temp;				
				
			}
		|   	WHILE expression DO statement	
			{
				printf("statement : WHILE expression DO statement\n");
				
				char tempLabel[10];
				char tempLabel1[10],tempLabel2[10];
				char string[100];
				
				//printf("The pointer is %");
				//printf("$4->symbol %s\n",$4->symbol);
				strcpy(string,$4->code);		//Another problem
				
				//printf("problem finding\n");
				
				SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
				temp->code[0] = '\0';
				
				strcat(temp->code,$2->code);
				strcat(temp->code,$2->branchCont);			//jle 
				newLabel();
				strcat(temp->code," ");
				strcat(temp->code,strLabel);				//label1
				strcat(temp->code,"\n\n");
				
				strcpy(tempLabel,strLabel);
				
				strcat(temp->code,"mov ecx,eax\n");		//before looping
				strcat(temp->code,"push ebx\n\n");
				
				
				
				newLabel();							//label:
				strcat(temp->code,strLabel);
				strcat(temp->code,":\n\n");
				
				
				strcat(temp->code,"pop ebx\n");
				strcat(temp->code,"push ebx\n");
				strcat(temp->code,"mov ecx,dword[");
				strcat(temp->code,$2->symbol);
				strcat(temp->code,"]\n");
				
				strcat(temp->code,"cmp ecx,ebx\n");
				strcat(temp->code,$2->branchCont);
				strcat(temp->code," ");
				strcpy(tempLabel1,strLabel);				//looping label - label3 tempLabel1
				newLabel();
				strcat(temp->code,strLabel);				//label4
				strcat(temp->code,"\n\n");
				
				//printf("Problem finding1 \n");
				
				strcat(temp->code,string);				//problem is here
				
				//printf("Problem finding2\n");
				
				strcat(temp->code,"jmp ");
				strcat(temp->code,tempLabel1);
				strcat(temp->code,"\n\n");
				
				strcat(temp->code,strLabel);
				strcat(temp->code,":\n");
				
				strcat(temp->code,"pop ebx\n\n");
				strcat(temp->code,tempLabel);
				strcat(temp->code,":\n\n");
				
				$$ = temp;
			}
		;
	
variable	:	ID	
			{	
				SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
				strcpy(temp->symbol,$1->symbol);
				temp->code[0] = '\0';
				
				//$1->code[0] = '\0';
				
				$$ = temp;
				
				//printf("In variable:ID\nThe code for %s is %s\n",$1->symbol,$1->code);
			}
		|	ID '[' expression ']'	
			{	printf("variable -> id [ expression ]\n");	}
		;

procedure_statement	:	ID	
			{	printf("procedure_statement -> id\n");	}
			|	ID '(' expression_list ')' 
			{	printf("procedure_statement -> id ( exp_list )\n");	}
			;

expression_list	:	expression 
			{    printf("expression_list	:	expression\n");	
			}
		|	expression_list ',' expression
			{	printf("expression_list	:expression_list ',' expression\n");	}	
		;

expression	:	simple_expression
			{	
				printf("expression	:	simple_expression\n");	
				$$ = $1;
				//printf("The string is %s\n",$1->code);
			} 
		|	simple_expression RELOP simple_expression {	
				printf("expression -> simple_expression RELOP simple_expression\n");	
			
				
				SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
				temp->code[0] = temp->symbol[0] = '\0';
				
				//mov eax,[x]
				//mov ebx,[y]
				//cmp eax,ebx
				
				strcat(temp->code,$1->code);
				strcat(temp->code,$3->code);
		
				//value decides the branching
				double decide = $1->value - $3->value;
	
				if($1->numVal && $3->numVal){
					strcat(temp->code,"mov eax,");
					//ItoA($1->value);
					sprintf(strRes,"%d",$1->value) ;
					strcat(temp->code,strRes);
					strcat(temp->code,"\n");
				
					strcat(temp->code,"mov ebx,");
					//ItoA($3->value);
					sprintf(strRes,"%d",$3->value) ;
					strcat(temp->code,strRes);
					strcat(temp->code,"\n");							
				}
				
				else if($1->numVal && !$3->numVal){
					strcat(temp->code,"mov ebx,dword[");
					strcat(temp->code,$3->symbol);
					strcat(temp->code,"]\n");
					strcat(temp->code,"mov eax,");
					//ItoA($1->value);
					sprintf(strRes,"%d",$1->value) ;
					strcat(temp->code,strRes);
					strcat(temp->code,"\n");
				
				}
				
				else if(!$1->numVal && $3->numVal){
					strcat(temp->code,"mov eax,dword[");
					strcat(temp->code,$1->symbol);
					strcat(temp->code,"]\n");
					strcat(temp->code,"mov ebx,");
					//ItoA($3->value);
					sprintf(strRes,"%d",$3->value) ;
					printf("The value of strRes is %s\n",strRes);
					strcat(temp->code,strRes);
					strcat(temp->code,"\n");
				}
				
				else {
					strcat(temp->code,"mov eax,dword[");
					strcat(temp->code,$1->symbol);
					strcat(temp->code,"]\n");
					strcat(temp->code,"mov ebx,dword[");
					strcat(temp->code,$3->symbol);
					strcat(temp->code,"]\n");
				}
				
				strcat(temp->code,"cmp eax,ebx\n");
				
				if(!strcmp($2,"=")){
					strcpy(temp->branchInfo,"je");
					strcpy(temp->branchCont,"jne");
							
				}else if(!strcmp($2,"<>")){
					strcpy(temp->branchInfo,"jne");
					strcpy(temp->branchCont,"je");
					
				}else if(!strcmp($2,"<")){
					strcpy(temp->branchInfo,"jl");
					strcpy(temp->branchCont,"jge");
				}else if(!strcmp($2,"<=")){
					strcpy(temp->branchInfo,"jle");
					strcpy(temp->branchCont,"jg");
					
				}else if(!strcmp($2,">")){
					strcpy(temp->branchInfo,"jg");
					strcpy(temp->branchCont,"jle");					
				}else if(!strcmp($2,">=")){
					strcpy(temp->branchInfo,"jge");
					strcpy(temp->branchCont,"jl");
				}			
				
				
				strcpy(temp->symbol,$1->symbol);
				$$ = temp;
				//printf("The jumping info is %s\n",temp->branchInfo);
			}
		;

simple_expression	:	term
				{	printf("simple_expression : term\n");	
					$$ = $1;
				} 
			|	'-' term %prec UNARY
				{	printf("simple_expression : Minus\n");
						//$$ = -$2;
					}
				
			|	simple_expression '+' term 
				{	
				
					
					
					printf("simple_expression : simple_expression addop term\n");	
					//printf("going to add\n");
					
					SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
					temp->code[0] = temp->symbol[0] = '\0';
					
					
					
					//First Expression
					if($1->numVal){
							strcat($1->code,"mov eax,");
							//ItoA($1->value);
							sprintf(strRes,"%d",$1->value) ;
							strcat($1->code,strRes);	
							strcat($1->code,"\n");	
										
					}
					else if($1->symbol){
						strcat($1->code,"mov eax,dword[");
						strcat($1->code,$1->symbol);
						strcat($1->code,"]\n");
						
					}
					
					else{
						
					}
					
					//second Expression
					if($3->numVal){
						strcat($3->code,"add eax,");
						//ItoA($3->value);
						sprintf(strRes,"%d",$3->value) ;
						strcat($3->code,strRes);	
						strcat($3->code,"\n");
					}
					else{
						printf("I am here the problem\n");
					
						strcat($3->code,"add eax,dword[");			//Some problem
						strcat($3->code,$3->symbol);
						strcat($3->code,"]\n");					//problem here
					}
					
					
					strcpy(temp->code,$1->code);		//temp->code = $1->code
					strcat(temp->code,$3->code);
					
					strcat(temp->code,"mov dword[");
					newTemp();
					strcat(temp->code,strTemp);
					strcat(temp->code,"],");
					strcat(temp->code,"eax\n");
					
					
					strcpy(temp->symbol,strTemp);
					temp->value = $1->value + $3->value;
					
					printf("temp->code is %s\n",temp->code);		//how it is right?
					
					$$ = temp ;
				}
			| 	simple_expression '-' term{
					
					//It's also working
					
					printf("going to subtract\n");
						
					//Wow! This is working
					
					SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
					temp->code[0] = temp->symbol[0] = '\0';
					
					
					
					//First Expression
					if($1->numVal){
							strcat($1->code,"mov eax,");
							//ItoA($1->value);
							sprintf(strRes,"%d",$1->value) ;
							strcat($1->code,strRes);	
							strcat($1->code,"\n");	
					}
					else {
						strcat($1->code,"mov eax,dword[");
						strcat($1->code,$1->symbol);
						strcat($1->code,"]\n");	
					}
					
					
					//second Expression
					if($3->numVal){
						strcat($3->code,"sub eax,");
					//	ItoA($3->value);
						sprintf(strRes,"%d",$3->value) ;
						strcat($3->code,strRes);	
						strcat($3->code,"\n");
					}
					else{
						strcat($3->code,"sub eax,[");
						strcat($3->code,$3->symbol);
						strcat($3->code,"];\n");
					}
					
					
					strcpy(temp->code,$1->code);		//temp->code = $1->code
					strcat(temp->code,$3->code);
					
					strcat(temp->code,"mov dword[");
					newTemp();
					strcat(temp->code,strTemp);
					strcat(temp->code,"],");
					strcat(temp->code,"eax\n");
					
					
					strcpy(temp->symbol,strTemp);
					temp->value = $1->value - $3->value;
					
					printf("temp->code is %s\n",temp->code);
					
					$$ = temp ;
			}
			;

term	:	factor	
		{
			printf("term	:	factor\n") ;
			//printf("The value of result factor is %lf\n",$1);	
			$$=$1;
		}
	|	term MULOP factor {
				printf("term	:	term MULOP factor\n") ;
				
				SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
				temp->code[0] = temp->symbol[0] = '\0';
				
				if($2 == 42 || $2 == 47 || $2 == 320){
					//multiplication - 42
					//division - 47
					
					
					//First Expression
					if($1->numVal){
						//mov eax,3
						strcat($1->code,"mov eax,");
						//ItoA($1->value);
						sprintf(strRes,"%d",$1->value) ;
						strcat($1->code,strRes);	
						strcat($1->code,"\n");	
					}
					else {
						//mov eax,dword[x]	
						strcat($1->code,"mov eax,dword[");
						strcat($1->code,$1->symbol);
						strcat($1->code,"]\n");	
					}
					
					//second expression
					if($3->numVal){
						//mov ebx,1
						strcat($3->code,"mov ebx,");
						//ItoA($3->value);
						sprintf(strRes,"%d",$3->value) ;
						strcat($3->code,strRes);	
						strcat($3->code,"\n");	
					}
					else {
						//mov ebx,dword[y]
						strcat($3->code,"mov ebx,dword[");
						strcat($3->code,$3->symbol);
						strcat($3->code,"]\n");	
					}
					
					
					strcpy(temp->code,$1->code);		//temp->code = $1->code
					strcat(temp->code,$3->code);
					
										
					if($2 == 42){
						//printf("i am in if to multiply\n");
						
						strcat(temp->code,"mul eax\n");
						temp->value = $1->value * $3->value;
					}
					else {
					//	printf("i am in else to divide\n");
					
						strcat(temp->code,"mov edx,0\n");
						strcat(temp->code,"div ebx\n");
						if($2 == 47)
							temp->value = $1->value / $3->value;
						else temp->value = (int)$1->value % (int)$3->value;
					}

					newTemp();
					strcat(temp->code,"mov dword[");					
					strcat(temp->code,strTemp);
					strcat(temp->code,"],");
					
					if($2 != 320)
						strcat(temp->code,"eax\n");
					else strcat(temp->code,"edx\n");
					
					strcpy(temp->symbol,strTemp);
					
					$$=temp;
					
					//printf("The value is now %d\n",temp->value);	
				}
				
				else;
			}

factor	:	ID 
		{	
			printf("factor -> ID \n");
			
			SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
			temp->code[0] = '\0';
			strcpy(temp->symbol,$1->symbol);
			
			//$1->code[0] = '\0';
			
			//$$ = $1;
			$$ = temp;
			
		}
	|	ID '(' expression_list ')' 
		{	printf("factor -> ID '(' expression_list ')' \n");	
			
			//$$ = $1->value;
				
		}
	|	NUM 
		{	printf("factor -> num value is %lf\n",$1);
		
			SymbolInfo* first = st.Insert("num1","NUM");
			first->value = $1;	
			first->numVal = true;
			first->code[0] = '\0';
			
			if(first->numVal)
				printf("numVal is true\n");
			
			$$ = first;	
			
		}
	|	'(' expression ')' 
		{	printf("factor : ( expression )\n");	
			$$ = $2;	
		}
	|	NOT factor 
		{	printf("factor : NOT factor\n");	}
	;


%%

int main(int argc,char*argv[])
{	



	char str[20];
	yyparse();
	freopen(argv[1],"r",stdin) ;
	
	
	
	
	
	
	
	
	//assembly code
	printf("\\\\\\\\\\\\\\\\\\\\\Assembly Code\\\\\\\\\\\\\n") ;
	strcat(bss,"buffer resb 1\n");
	strcat(bss,"temp resb 10\n");
 
 	printf("section .data\n\n");
 	printf("section .bss\n\n");
 	printf("%s\n\n",bss);
 	printf("section .text\n\nglobal _start\n\n_start:\n");
 	printf("%s\n",data);
 	printf("mov eax,1\nmov ebx,0\nint 80h\n");
 	
 	//Writing the function in string
	printf("mov ecx,0\n\n");
	printf("printFunc:\n\nmov dx,0\nmov bx,10\ndiv bx\nadd dl,30h\nmov [temp+ecx],dl\ninc ecx\n");
	printf("cmp ax,0\njne printFunc\n\n");
	printf("print:\ndec ecx\nmov al,[temp+ecx]\nmov byte[buffer],al\n\npusha\nmov eax,4\nmov ebx,1\n");
	printf("mov ecx,buffer\nmov edx,1\nint 80h\n\npopa\n\ncmp ecx,0\njne print\n\n");
	printf("mov byte[buffer],10\n\nmov eax,4\nmov ebx,1\nmov ecx,buffer\nmov edx,1\nint 80h\n\n");
	printf("ret\n");
	
	
	
	return 0;
	
}

void yyerror(char *msg)
{
	printf("%s found at line %d\n", msg,linecount);
}


SymbolInfo* SymbolTable::Insert(char *str1,char *str2){


	
	int symbol = 0;
	
	//printf("String is %s key is %d\n",str1,symbol);
	
	SymbolInfo *returnPointer = Lookup(str1,str2);
	return returnPointer;
}

SymbolInfo* SymbolTable::Lookup(char *str1,char* str2){

	int index = 0;
	
	for( int i = 0 ; str1[i] ; i++)
		index += str1[i];
	index %= 20;


	SymbolInfo *p = total[index];
	if(p->next == NULL){
		
		
		SymbolInfo *New = (SymbolInfo *)malloc(sizeof(SymbolInfo));
		strcpy(New->symbol,str1);
		if(str2)
			strcpy(New->type,str2);
		New->next = NULL;
		p->next = New;
		
		//printf("Inserted the string %s in table\n ",New->symbol);
		
		return New;
		
	}
	
	
	do{
		p = p -> next;
		if(p->symbol && !strcmp(str1,p->symbol))
			return p;
	
	}while(p->next);

	SymbolInfo *New = (SymbolInfo *)malloc(sizeof(SymbolInfo));
	strcpy(New->symbol,str1);
	if(str2)
		strcpy(New->type,str2);
	New->next = NULL;
	p->next = New;

	return New;
}

void SymbolTable::Dump(){


	printf("\nSymbol Table\n\n");

	SymbolInfo* p;
	for(int i = 0 ; i < SIZE ; i++){
	
		p = total[i]; 
		if(p -> next != NULL){
			
			printf("At index[%d]\n",i);
			int i = 0;
			
			do{
				p = p->next;
				printf("\t%s %lf\n type %s\n",p->symbol,p->value,p->dataType);
				
			}while(p->next != NULL);		
			printf("\n");
		}
	}

	printf("\nSymbolTable\n");
}
