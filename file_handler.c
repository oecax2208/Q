/*
	SCION > 0.1
	BETA VERSION
	OPEN SOURCE
	TARGET:  WINDOWS.O.S
	This File is for the user registeration and storing 
*/

#include<stdio.h>
#include<string.h>
#include<stddef.h>
#include<stdalign.h>
#include<assert.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<stdbool.h>
#include<stdint.h>

#define max_len 20


static bool set_admin(void){

	char password[max_len];
	FILE* ftype = fopen("beta.txt","w+");
	
	if(ftype){
		
		fputs("Set your password (maximum length 20)> ",stdout);
		fgets(password,max_len + 1,stdin);
		fputs(password,ftype);
		
		fclose(ftype);	
		return true;
	}
	fprintf(stderr,"%s","Program could not write on hard disk, check partition setting, security setup or memory space");
	return false;
}

static bool check_admin(void){
	char password[max_len];
	char F_password[max_len];
	FILE* ftype = fopen("beta.txt","r+");
	
	if(ftype){
		
		fputs("Enter password >",stdout);
		fgets(password,max_len+1,stdin);
		fgets(F_password,max_len + 1, ftype);
		
		if(strcmp(F_password,password) == 0){
			fputs("INput accepted",stdout);
			fclose(ftype);
			return true;
		}else{
			fputs("Invalid Input",stdout);
			return false;
		}

	}
	
	fprintf(stderr,"%s","Program could not write on hard disk, check partition setting, security setup or memory space");
	return false;

}

int main(){
	set_admin();
	check_admin();
	

}

