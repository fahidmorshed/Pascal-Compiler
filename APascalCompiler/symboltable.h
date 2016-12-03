#define SIZE 100

class SymbolInfo{

	public:
		char symbol[100];		//Hold the lexeme value i.e identifier name
							//It may also be used to save temproary variable
		char type[100];		//type information
		char code[10000];		//Hold the code
		double value;
		bool numVal;
		bool typeVal;
		char branchInfo[10];
		char branchCont[10];
		int which;
		char dataType[100];
		SymbolInfo * next;
};

class SymbolTable{

	public:
		SymbolInfo *total[SIZE]; 

	public:
		SymbolTable(){
		
			for(int i = 0 ;i < SIZE ; i++){
				
				total[i] = (SymbolInfo *)malloc(sizeof(SymbolInfo));
				total[i]->next = NULL;
				
			}
		}
		SymbolInfo* Insert(char *,char *);
		SymbolInfo* Lookup(char* ,char *);
		void Dump();
};
