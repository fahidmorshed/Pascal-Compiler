#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

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
        cout << symbolName << " " << symbolType;
    }
};

//SymbolInfo** symbolTable = new SymbolInfo*[SIZE];

//the heshTable
class SymbolTable{
public:
    SymbolInfo** infoTable = new SymbolInfo*[SIZE];

    void Insert(){
        string name, type;
        cout << "Name and Type: ";
        cin >> name;
        cin >> type;
        int hesh = heshFunc(name);
        if(searchSymbolName(name, hesh)){
            cout << "Symbol already exists.\n";
            return;
        }
        insertSymbol(name, type, hesh);
        cout << "Symbol inserted." << hesh << "\n";
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
            cout << i << ": ";
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
        cout << "\t";
        iterator_token = iterator_token->next;
    }
    cout << endl;
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

int main()
{
    //int i;
    int choice;

    do{
        cout << "MENU:\n\n\t1.Insert\n\t2.Lookup\n\t3.Dump\n\t4.Delete\n\t0.Exit\n\n";
        cout << "Choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                symbolTable.Insert();
                break;
            case 2:
                symbolTable.Lookup();
                break;
            case 3:
                dump();
                break;
            case 4:
                symbolTable.deleteToken();
                break;
            default:
                cout << "Wrong Choice!\n";
                break;
        }
    }while(choice!=0);

    /*do{
        cout << "MENU:\n\n\t1.Insert\n\t2.Delete\n\t3.Search by name\n\t4.Search by type\n\t5.Print all\n\t0.Exit\n\n";
        cout << "Choice: ";
        cin >> choice;
        string name, type;
        switch(choice){
            case 1:
                cout << "Insert a token.\nName Type: ";
                cin >> name;
                cin >> type;
                cin >> i;
                insertSymbol(name, type, i);
                break;
            case 2:
                cout << "Delete a token.\nName: ";
                cin >> name;
                cin >> i;
                deleteSymbol(name, i);
                break;
            case 3:
                cout << "Search a token.\nName: ";
                cin >> name;
                cin >> i;
                searchSymbolName(name, i);
                break;
            case 4:
                cout << "Search a token type.\nType: ";
                cin >> type;
                cin >> i;
                searchSymbolType(type, i);
                break;
            case 5:
                cin >> i;
                printHesh(i);
                break;
            case 0:
                break;
        }
    }
    while(choice!=0);*/
    cout << "\nTHANK YOU!\n" << endl;
    return 0;
}
