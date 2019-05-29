#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define max_len 100


typedef struct iter{
	char* input;
	bool check;	
	int caller;
}iter;

void* init(struct iter* node){
	/*
		ensure proper dyn -allocation
	*/
	
	node->input = (char*)malloc(sizeof(char) * max_len);
		
	if(node->input != NULL){
		node->check = true;
		node->caller = 1002;
	}	
	
	if(!node->check){
		fputs("Error, couldn't allocate memory",stderr);
		exit(0);
	}
	
	return node;	
}

void* input(struct iter* node){
	/*
		input handler mechanism
	*/
	
handler:
	{	
		if(!node->check){
		fputs("Error, couldn't allocate memory",stderr);
		exit(0);
		}
	}
	
	if(!(fgets(node->input,max_len,stdin))){
		node->check = false;
		goto handler;
	}
	
	node->check = true;
	return node;
}

void* kw_process(struct iter* node){
	/*
	  KeyWord_process machnism
	  since the interpreter is a 
	  "startup" interpreter
		all cmds follow this sequence
		
		#kword #optor #comd
		del		=      case.txt   //delete case.txt file
		
		create  > case.txt		 // create case.txt file
		
		read    < case.txt		// read    case.txt file
		
		so the function is basically checking for a valid keyword
		int lcount {count input, since keyword differ in len}	
	*/

	
	static char* del = "del";
	static char* create = "create";
	static char* read = "read";
	static char* end = "end";
	static char* pse = "pause";
	
	for(int x = 0; x < strnlen(node->input,max_len); ++x){
		if(!isspace(node->input[x])){
			/*
				scan using the first char to match keyword,
				using 'goto' and making sure nothing escapes
				into any other label or spagehtti code
				tho spagehtti taste dummy :)
			*/
			if(node->input[x] == 'd') goto d;
			else if(node->input[x] == 'c') goto c;
			else if(node->input[x] == 'r') goto r;
			else if(node->input[x] == 'e') goto e;
			else if(node->input[x] == 'p') goto p;
			else{
				fputs("\tError, invalid keyword.\n \t keywords are del , create , read , end , pause",stderr);
				exit(0);
			}
			
			
		d:{				
			int lcount = 0;
			int p = x;
			for(size_t i = 0; i < strnlen(del,4); ++i){
				if(node->input[p] == del[lcount]){
					++p;
					++lcount;
				}
			}
			
			if(lcount ==  strnlen(del,4) && isspace(node->input[p])) return del;      //isspace(node->input[x]) avoids words like dellll
			fputs("\tError, invalid keyword do you mean 'del'",stderr);
			exit(0);
		}
			
			
		c:{	
			int lcount = 0;
			int p = x;
			for(size_t i = 0; i < strnlen(create,7); ++i){
				if(node->input[p] == create[lcount]){
					++p;
					++lcount;
				}
			}
			
			if(lcount == strnlen(create,7) && isspace(node->input[p]))return create;
			fputs("\tError, invalid keyword do you mean create",stderr);
			exit(0);
		}
		
		r:{
			int lcount = 0;
			int p = x;
			for(size_t i = 0; i < strnlen(read,5); ++i){
				if(node->input[p] == read[lcount]){
					++p;
					++lcount;
				}
			}
			
			if(lcount == strnlen(read,5) && isspace(node->input[p]))return read;
			fputs("\tError, invalid keyword do you mean read",stderr);
			exit(0);
			
		}
		
		e:{
			int lcount = 0;
			int p = x;
			
			for(size_t i = 0; i < strnlen(end,4); ++i){
				if(node->input[p] == end[lcount]){
					++p;
					++lcount;
				}
			}
			
			if(lcount == strnlen(end,4) && isspace(node->input[p])) return end;
			fputs("\tError, invalid keyword to terminate type 'end' ",stderr);
			exit(0);
		}
		
		p:{
			int lcount = 0;
			int p = x;
			
			for(size_t i = 0; i < strnlen(pse,6); ++i){
				if(node->input[p] == pse[lcount]){
					++p;
					++lcount;
				}
			}
			
			if(lcount == strnlen(pse,6) && isspace(node->input[p]))  return pse;		//pse means pause not pse
			fputs("Error, invalid keyword do you mean 'pse' ",stderr);
			exit(0);
		
		}		
		}
	}
	
	return node;
}

void* op_process(struct iter* node){
	
}



int main(int argc, char** argv){
	iter* start = (iter*)malloc(sizeof(iter));
	init(start);
	input(start);
	kw_process(start);
	
}
