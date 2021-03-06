%{
#include <iostream>
#include <cstdio>
#include <cstring>
#include<fstream>
using namespace std;

FILE *fp; 
ofstream outputFile;

#define SIZE 20     //row numbers
#define ARRAYSIZE 20    //temp char array for hesh function

int heshFunc(string key, int slots=SIZE); //folded hash function
bool searchSymbolName(string name, int hesh);   //linkedlist only
bool searchSymbolType(string type, int hesh);   //linkedlist only (not used yet)
void printHesh(int hesh);                       //prints a particula row
void insertSymbol(string name, string type, int hesh);      //insert symbol into a row
bool deleteSymbol(string name, int hesh);       //delete from a row

//the basic elements of a heshTable
class SymbolInfo{
public:
    string symbolName;
    string symbolType;
    SymbolInfo* next;

    SymbolInfo(string name, string type){
        symbolName = name;
        symbolType = type;
        next = NULL;
    }

    void printToken(){
       // cout << symbolName << " " << symbolType;
        outputFile<<"< "<<symbolName<<", "<<symbolType<<" >";
    }
};

class SymbolTable{
public:
    SymbolInfo** infoTable = new SymbolInfo*[SIZE];

    void Insert(string name,string type){
        
        int hesh = heshFunc(name);
        if(searchSymbolName(name, hesh)){
            outputFile<<"\""<<name<<"\""<<" already exists in the table"<<endl<<endl<<endl;
            return;
        }
        insertSymbol(name, type, hesh);
        return;
    }

    bool Lookup(){
        string name;
        cout << "Name: ";
        cin >> name;
        int hesh = heshFunc(name);
        if(searchSymbolName(name, hesh)){
            cout << "Match found.\n";
            return true;
        }
        else{
            cout << "No match found.\n";
            return false;
        }
    }

    void deleteToken(){
        string name;
        cout << "Name: ";
        cin >> name;
        int hesh = heshFunc(name);
        if(deleteSymbol(name, hesh)){
            cout << "Deleted.\n";
            return;
        }
        cout << "Failed to delete.\n";
    }
};

SymbolTable symbolTable;

int heshFunc(string key, int slots){
    int foldedLength = key.length() / 2;
    long int totalSum = 0;

    //splitting the string into 2 bytes each, multiplying them and adding them, then mod
    for(int i=0; i<foldedLength; i++){
        char charArray[ARRAYSIZE];
        strcpy(charArray, key.substr(i*2, (i*2) + 2).c_str());
        long int multi = 1;
        int len=0;
        for(int i=0; charArray[i]!='\0' ; i++){
            len++;
        }
        for(int j=0; j<len; j++){
            totalSum += charArray[j] * multi;
            multi *= 269; //prime
        }
    }
    //if some bytes still remains
    char charArray[ARRAYSIZE];
    strcpy(charArray, key.substr(foldedLength * 2).c_str());
    long multi = 1;
    int len = 0;
    for(int i=0; charArray[i]!='\0' ; i++){
            len++;
        }
    for(int i=0; i<len; i++){
        totalSum += charArray[i] * multi;
        multi *= 269;
    }
    return (abs(totalSum)%slots);
}

bool searchSymbolName(string name, int hesh){
    if(symbolTable.infoTable[hesh] == NULL){
        //cout << "Sorry, the list is empty.\n";
        return false;
    }
    SymbolInfo* iterator_token;
    iterator_token = symbolTable.infoTable[hesh];

    while(true){
        //if(strcmp(iterator_token->symbolName, name) == 0){
        if(iterator_token->symbolName.compare(name) == 0){
            //cout << "Match found.\n";
            return true;
        }
        if(iterator_token->next == NULL){
            //cout << "Sorry, no such token in found.\n";
            return false;
        }
        iterator_token = iterator_token->next;
    }
}

bool searchSymbolType(string type, int hesh){
    if(symbolTable.infoTable[hesh] == NULL){
        //cout << "Sorry, the list is empty.\n";
        return false;
    }
    SymbolInfo* iterator_token;
    iterator_token = symbolTable.infoTable[hesh];
    while(true){
        //if(strcmp(iterator_token->symbolType, type) == 0){
        if(iterator_token->symbolType.compare(type) == 0){
            //cout << "Match found.\n";
            return true;
        }
        if(iterator_token->next == NULL){
            //cout << "Sorry, the list is empty.\n";
            return false;
        }
        iterator_token = iterator_token->next;
    }
}

void dump(){
    for(int i=0; i<SIZE; i++){
        if(symbolTable.infoTable[i] != NULL){
            outputFile<<"[" << i <<"]---> ";
            int x = heshFunc(symbolTable.infoTable[i]->symbolName);
            printHesh(x);
        }
    }
}

void printHesh(int hesh){
    SymbolInfo* iterator_token;
    iterator_token = symbolTable.infoTable[hesh];
    //cout << "Printing Tokens with hesh"<< hesh <<": \n";
    while(iterator_token!=NULL){
        iterator_token->printToken();
        iterator_token = iterator_token->next;
    }
    outputFile<<endl;
}

void insertSymbol(string name, string type, int hesh){
    SymbolInfo* newToken = new SymbolInfo(name, type);
    if(symbolTable.infoTable[hesh] == NULL){
        symbolTable.infoTable[hesh] = newToken;
        //cout << "SymbolInfo Inserted.\n";
        return;
    }
    SymbolInfo* iterator_token = symbolTable.infoTable[hesh];
    while(true){
        if(iterator_token->next != NULL){
            iterator_token = iterator_token->next;
        }
        else{
            iterator_token->next = newToken;
            //cout << "SymbolInfo Inserted.\n";
            return;
        }
    }
}

bool deleteSymbol(string name, int hesh){
    if(searchSymbolName(name, hesh)){
        SymbolInfo* prev_token = symbolTable.infoTable[hesh];
        //if(strcmp(head->symbolName, name) == 0){
        if(symbolTable.infoTable[hesh]->symbolName.compare(name) == 0){
            symbolTable.infoTable[hesh] = NULL;
            delete prev_token;
            //cout << "Deleted. List is empty.\n";
            return true;
        }
        SymbolInfo* curr_token = prev_token->next;
        while(curr_token!=NULL){
            //if(strcmp(curr_token->symbolName, name) == 0){
            if(curr_token->symbolName.compare(name) == 0){
                prev_token->next = curr_token->next;
                delete curr_token;
                //cout << "Deleted.\n";
                return true;
            }
            prev_token = curr_token;
            curr_token = curr_token->next;
        }
        cout << "Oups! Something's wrong!";
        return false;
    }
    else{
        return false;
    }
}

int lineCount = 0;
%}

WS [ \t\v\f\r]+
NEWLINE [\n]
LETTER [a-zA-Z]
DIGIT [0-9]
UNDERSCORE [_]

ADDOP ("+")|("-")|("or")
MULOP ("and")|("div")|("*")|("mod")|("/")

BRACKET ("[")|("]")
PAREN ("(")|(")")

RELOP ("<")|(">")|("<=")|(">=")|("=")|("<>")

UNREC ("@")|("~")
COMMENT "{"[^}]*"}"

KEYWORD ("program")|("if")|("not")|("end")|("begin")|("else")|("then")|("do")|("while")|("function")|("procedure")|("integer")|("real")|("var")|("of")|("array")|("write")

NUM {DIGIT}+(\.{DIGIT}+)?(E[+-]?{DIGIT}+(\.{DIGIT}+)?)?

ID ({LETTER}|{UNDERSCORE})+({LETTER}|{UNDERSCORE}|{DIGIT})*
STRINGS "\""([^\"])*"\""

ILLID ({DIGIT}|{UNREC})+({LETTER}|{UNDERSCORE}|{DIGIT})*
ILLNUM ((\.{DIGIT}+)+(E[+-]?{DIGIT}+(\.{DIGIT}+)?)?)|({DIGIT}+(\.{DIGIT}+)+)
%%
{WS}        {
                //Do Nothing
            }
{NEWLINE}   {
                lineCount += 1;
                
            }
{STRINGS}   {
		//fprintf(fp,"< ADDOP,%s >",yytext);
                outputFile<< "line "<<lineCount<<": " << "String "<<"\""<<yytext<<"\""<<" is found"<<endl<<endl;
		lineCount++;
	    }
{ADDOP}     {
                fprintf(fp,"< ADDOP,%s >",yytext);
                outputFile<< "line "<<lineCount<<": "<<"\""<<yytext<<"\""<<" found"<<endl;
                symbolTable.Insert(yytext,"ADDOP");

                
                outputFile<<"Symbol Table :"<<endl;
                dump();
		outputFile<<endl<<endl;
	    }

{MULOP}     {
		fprintf(fp,"< MULOP,%s >",yytext);
                outputFile<< "line "<<lineCount<<": "<<"\""<<yytext<<"\""<<" found"<<endl;
                symbolTable.Insert(yytext,"MULOP");

                
                outputFile<<"Symbol Table :"<<endl;
                dump();
		outputFile<<endl<<endl;
            }

{RELOP}     {
                fprintf(fp,"< RELOP,%s >",yytext);
                outputFile<< "line "<<lineCount<<": "<<"\""<<yytext<<"\""<<" found"<<endl;
                symbolTable.Insert(yytext,"RELOP");

                
                outputFile<<"Symbol Table :"<<endl;
                dump();
		outputFile<<endl<<endl;
	    }

{PAREN}     {
                fprintf(fp,"< PAREN,%s >",yytext);
                outputFile<< "line "<<lineCount<<": "<<"\""<<yytext<<"\""<<" found"<<endl;
                symbolTable.Insert(yytext,"PAREN");

                
                outputFile<<"Symbol Table :"<<endl;
                dump();
		outputFile<<endl<<endl;
	    }

{BRACKET}   {
                fprintf(fp,"< BRACKET,%s >",yytext);
                outputFile<< "line "<<lineCount<<": "<<"\""<<yytext<<"\""<<" found"<<endl;
                symbolTable.Insert(yytext,"BRACKET");

                
                outputFile<<"Symbol Table :"<<endl;
                dump();
		outputFile<<endl<<endl;
	    }
":="        {
                fprintf(fp,"< ASSIGNOP,%s >",yytext);
                outputFile<< "line "<<lineCount<<": "<<"\""<<yytext<<"\""<<" found"<<endl;
                symbolTable.Insert(yytext,"ASSIGNOP");

                
                outputFile<<"Symbol Table :"<<endl;
                dump();
            	outputFile<<endl<<endl;
	    }
":"         { 
                fprintf(fp,"< COLON,%s >",yytext);
                outputFile<< "line "<<lineCount<<": "<<"\""<<yytext<<"\""<<" found"<<endl;
	        symbolTable.Insert(yytext,"COLON");
                
                
                outputFile<<"Symbol Table :"<<endl;
                dump();
		outputFile<<endl<<endl;
            }
";"         { 
                fprintf(fp,"< SEMICOLON,%s >",yytext);
                outputFile<< "line "<<lineCount<<": "<<"\""<<yytext<<"\""<<" found"<<endl;
	        symbolTable.Insert(yytext,"SEMICOLON");
               
                outputFile<<"Symbol Table :"<<endl<<endl;
                dump();
		outputFile<<endl<<endl;
            }
","         { 
                fprintf(fp,"< COMMA,%s >",yytext);
                outputFile<< "line "<<lineCount<<": "<<"\""<<yytext<<"\""<<" found"<<endl;
	        symbolTable.Insert(yytext,"COMMA");
               
                outputFile<<"Symbol Table :"<<endl<<endl;
                dump();
		outputFile<<endl<<endl;
            }
"."         {
                fprintf(fp,"< DOT,%s >",yytext);
                outputFile<< "line "<<lineCount<<": "<<"\""<<yytext<<"\""<<" found"<<endl;
                symbolTable.Insert(yytext,"DOT");
 
             
                outputFile<<"Symbol Table :"<<endl;
                dump();
		outputFile<<endl<<endl;
            }
".."        {
                fprintf(fp,"< DOTDOT,%s >",yytext);
                outputFile<< "line "<<lineCount<<": "<<"\""<<yytext<<"\""<<" found"<<endl;
                symbolTable.Insert(yytext,"DOTDOT");
 
             
                outputFile<<"Symbol Table :"<<endl;
                dump();
		outputFile<<endl<<endl;
            }
{KEYWORD}   {
                fprintf(fp,"< %s >",yytext);
                outputFile<< "line "<<lineCount<<": "<<"KEYWORD "<<"\""<<yytext<<"\""<<" found"<<endl<<endl;
 
            }
{COMMENT}   {
               
                outputFile<< "line "<<lineCount<<": "<<"Comment found: "<<yytext<<endl<<endl;
            }
{ID}        {
                fprintf(fp,"< ID,%s >",yytext);
                outputFile<< "line "<<lineCount<<": "<<"\""<<yytext<<"\""<<" found"<<endl;
                symbolTable.Insert(yytext,"ID");
 
             
                outputFile<<"Symbol Table :"<<endl;
                dump();
		outputFile<<endl<<endl;
            }
{NUM}       {
                fprintf(fp,"< NUM,%s >",yytext);
                outputFile<< "line "<<lineCount<<": "<<"\""<<yytext<<"\""<<" found"<<endl;
                symbolTable.Insert(yytext,"NUM");
 
             
                outputFile<<"Symbol Table :"<<endl;
                dump();
		outputFile<<endl<<endl;
            }

{UNREC}     {
		outputFile<< "line " << lineCount << ": " << "\"ERROR :UNRECOGNIZED CHARACTERS\" found" << endl << endl;

	    }
{ILLID}     {
		outputFile<< "line " << lineCount << ": " << "\"ERROR :ILL FORMED IDENTIFIER\" found" << endl << endl;
	
	    }
{ILLNUM}    {
		outputFile<< "line " << lineCount << ": " << "\"ERROR :ILL FORMED NUMBER \" found" << endl << endl;

	    }
%%
int main(int argc, char **argv)
{
        freopen(argv[1],"r",stdin); 
        outputFile.open(argv[2]);
        fp=fopen(argv[3],"w");
        
        yylex();
	dump();
        outputFile<<"Total number of lines: "<<lineCount<<endl;
     	fclose(fp);
	outputFile.close();
        return 0;
}
