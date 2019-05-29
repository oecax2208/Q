#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

/*
	This files contains the input handler and system comand for bash code

*/

static char tmp[10];		// a tmp variable use to hold keywords
static char name[100];		//name represent the actual input




static char _input(){
	int cnt = 0; 							//variable will be use for loop index counter	
		fputs("\ncmd > ",stdout);		
		fgets(name,100,stdin);				//from global decl
		for(int x = 0; x < strnlen(name,100); ++x){
			if(isspace(name[x])){
				
			}else{
				tmp[cnt] = name[x];			//copy non-space to tmp(from global decl);
				++cnt;
				if(isspace(name[x + 1])){
					tmp[cnt] = ';';			//insert a dummy value at end of valid character for better processing
					
					if(tmp[0] == 'd'){
						return 'd';			// code-name for keyword 'del'
					}
					else if(tmp[0] == 'p' && tmp[1] == 'u'){
						return 'Z';			//code-name for keyword    'put'
					}
					else if(tmp[0] == 'p' && tmp[1] == 's'){
						return 'p';			//code-name for keyword 'pse'
					}
					else if(tmp[0] == 't' && tmp[1] == 'c'){
						return 't';
					}
					else if(tmp[0] == 'b'){
						return 'b';
					}
					else if(tmp[0] == 'e'){
						return 'e';
					}
					else{
						fputs("Invalid Command", stderr);
						break;
					}
				}
				
			}
		}
		
	return 0;

}

bool keyword(char inm){
	if(inm == 'd'){				//test for del from previous fucntion
		int count = 0;
		char* del = "del;";
		for(int x = 0; x < 4 ; ++x){
			if(del[x] == tmp[x]) ++count;
		}
		
		if(count == 4)
		return true;		//return true for success
		
		fputs("\nInvalid command\n",stderr);
		
		
	}
	else if(inm == 'Z'){
		int count = 0;
		char*  put = "put;";
		
		for(int x = 0; x < 4; ++x){
			if(put[x] == tmp[x]) ++count;
		}
		
		if(count == 4)
		return true;
	
		fputs("\nInvalid command\n",stderr);
		
	}else if(inm == 'p'){
		int count = 0;
		char* pse = "pse;";
		
		for(int x = 0; x < 4; ++x){
			if(pse[x] == tmp[x]) ++count;
		}
		
		if(count == 4){
			fputs("\nSystem pause\n",stdout);
			sleep(3);
			return true;	
		}
		else
		fputs("\nInvalid command\n",stderr);
	}
	
	else if(inm == 't'){
		int count = 0;
		char* tclr = "tclr;";
		
		for(int x = 0; x < 5; ++x){
			if(tclr[x] == tmp[x]) ++count;
		}
		
		if(count == 5)
		return true;
		
		fputs("\nInvalid command\n",stderr);
	}
	
	else if(inm == 'b'){
		int count = 0;
		char* bclr = "bclr;";
		
		for(int x = 0; x < 5 ; ++x){
			if(bclr[x] == tmp[x]) ++count;
		}
			if(count == 5)
			return true;
			
			fputs("\nInvalid command\n",stderr);
	
	}
	
	else if(inm == 'e'){
		int count = 0;
		char* end = "end;";
		
		for(int x = 0; x < 4; ++x){
			if(end[x] == tmp[x]) ++count;
		}
			if(count == 4)
			exit(0);
			
			fputs("\nInvalid command\n",stderr);
		
	}
	
	return true;
	
}


static pause(bool index){
	
}




int main(){
	while(keyword(_input()));
	
	
}

