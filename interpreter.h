/*	
	(c) FREE SOFTWARE TO USE AND EDIT
	
	PROGRAMMER: JOEL
	LANGUAGE : C
	DES: WRITING A SIMPLE VIRTUAL-COMPUTER INTERPRETER FOR MEMORY MANAGEMENT AND BASIC ARTHIMETIC OPERATORS
	
	Compiler: TDM-GCC 5.1.0 but should compile in all C11 standard support.
	Static memory were favoured over dynamic and the little overhead was adjusted use system precise types
	
	Program is multithreaded using pthread.h over thread.h in C11 standard
*/

#include"cmd.h"


#define max_len 100 			//max text length


#define input_err_len		"\n\t\tCommand to small to be interpreted\n\n"		
#define invalid_char		"\n\t\tFirst character cannot be empty\n\n"					
#define err_cmd_temp	 	"\n\t\tCommand Code missing '#'\n\n"
#define invalid_cmd			"\n\t\tis not reconiled as a command\n\n"

//This condition is achieve when result error code is unknown see err_handler function
#define unknown_err			"Unknown Error occured"

typedef struct{
	
	char input[100];
	bool validate;
		
}interpreter;

//This one liner function is use for effective error msg display using the error code as correspoinding to the macros pre-defined
const char* err_handler(int err_code) { return (err_code == 1)?input_err_len:(err_code == 2)?invalid_char:(err_code == 3)?err_cmd_temp:(err_code == 4)?invalid_cmd:unknown_err;}


void paser(){
	
	int type = 0; 										// This 'type' var is use to perform valid text check with the strstr();
	
	static char* value[] = {
		"#ADD",
		"#SUB",
		"#MUL",
		"#HELP",
		"#SYS",
		"#EXIT",
		
		//DIV and MOD not supported at this time
		"#DIV"
		
	};
	
	static interpreter var  = {alignof(max_align_t)};   	//Align struct on hardware for effective manipulating and create an "instance" of "interpreter"			
	
	var.validate = true;									//validation of input..{baicaly have no effect, just for free flow}
	
	fputs("Enter command >>> ",stdout);						// fgets(FILE*,const *restrict str) is quite similar to printf("%s",...);
	fgets(var.input,max_len,stdin);							
	
	
	/*This 'for' loop use the 'type' variable to get the number of 
	input entered become the first space' ' or tab'\t' is entered
	*/
	for(int x = 0; x < strnlen(var.input,max_len); ++x){
		if(var.input[x] == ' ' || var.input[x] == '\t'){
			type = x;
			break;
		}
	}
	
	while(strnlen(var.input,max_len)-1 <= 4 ){				//This while loop validate numbers of char entered
		var.validate = false;
		fputs(err_handler(1),stdout);
		fputs("Enter command >>> ",stdout);	
		fgets(var.input,max_len,stdin);
	}
	while(var.input[0] == ' ' || var.input[0] == '\t'){   	//This while loop validate for  for empty char input
		var.validate = false;
		fputs(err_handler(2),stdout);
		fputs("Enter command >>> ",stdout);	
		fgets(var.input,max_len,stdin);
	}
	
	while(var.input[0] != '#'){								//This while loop validate for first character
		var.validate = false;
		fputs(err_handler(3),stdout);
		fputs("Enter command >>> ",stdout);	
		fgets(var.input,max_len,stdin);
	}
	
	
	while(var.validate = false){							//This final while piece may not be reach but for hardware safety
		fputs(err_handler(0),stdout);
		fputs("Enter command >>> ",stdout);	
		fgets(var.input,max_len,stdin);
	}
	
	
	
	//This branch statement uses make fast checkup and allocate to proper functions defined in "cmd.h"
	if(strstr(var.input,value[0]) && type == 4){
		ADD(var.input);
	}else if(strstr(var.input,value[1]) && type == 4){
		SUB(var.input);
	}else if(strstr(var.input,value[2]) && type == 4){
		MUL(var.input);
	}else if(strstr(var.input,value[3]) && type == 4){
		HELP();
	}else if(strstr(var.input,value[4]) && type == 4){
		SYSTEM();
	}else if(strstr(var.input,value[5]) && type == 4){
		TERMINATE();
	}else if(strstr(var.input,value[6]) && type == 4){
		fprintf(stderr,"\n\t\t %s\n\n","Division not supportted as this time");
	}else{
		fprintf(stderr,"\n\t\t%s\t\tis not a valid input\n\n",var.input);	
		paser();  //Note that fuction is recursional...
	}
	
}

