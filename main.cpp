//we need two modules
//first module will check if all the syntaxes are correct
//second module will show the output accordingly

#include <stdio.h>
#include <string.h>

int program_syntax_check(FILE *fr);


int main(){                           //main function will do one job get the input from user and write it in file then we can access the file and execute the program by reading statements accordingly
	char sentence[500];
	int flag=0;
	char flag_sentence[]="return 0;";
	
	printf("//you need to write a basic c program with if else");
	printf("\n//start writing the file and once \"you write return 0 }\" the program will automatically execute\n");
	
	FILE *f1=fopen("newProgram.txt","w");
	if(f1==NULL){
		printf("\nerror creating file!\n");
	}
	else{
		while(flag<2){
			gets(sentence);
			fprintf(f1,"%s\n",sentence);
			if(flag==1){
				flag++;
			}
			if(strcmp(sentence,flag_sentence)==0){
				flag++;
			}
		}
	}
	fclose(f1);
	
	FILE *fr=fopen("newProgram.txt","r");
	
	program_syntax_check(fr);
	return 0;
}

int program_syntax_check(FILE *fr){
	char current_line[500];
	int num=0;
	int main_flag=0;
	while(fgets(current_line,500,fr)!=NULL){
			num++;
		//printf("%scurrent_line[0]:%c\n",current_line,current_line[0]);
	
		if(current_line[0]="#"){                                                                     //to check all the header file syntax are correct
			if(strcmp(current_line,"#include <",10)!=0 && strcmp(current_line,"#include<",9)!=0){
				printf("\nsyntax error on line %d\n",num);
				return -1;
			}
			else if(current_line[strlen(current_line)-1]!=">"){
				printf("\nsyntax error on line %d\n",num);
				return -1;
			}
		}
		
		elif if(strcmp(current_line,"print(",6)==0){                                               //to check all the printf statements have no syntax error
			if(strcmp(current_line,"printf(",7)!=0){
				printf("\nsyntax error on line %d\n",num);
				return -1;
			}
			else if(current_line[strlen(current_line)-1]!=";" && current_line[strlen(current_line)-2]!=")"){
				printf("\nsyntax error on line %d\n",num);
				return -1;
			}	
		}
		
		else if(strcmp(current_line,"int main",8)){                                                     //to check int main function is present and syntactically correct
			main_flag=1;
			if(strcmp(current_line,"int main()",10)!=0){
				printf("\nsyntax error on line %d\n",num);
				return -1;
			}
		}
		
		else if(strcmp(current_line,"if(",3)||strcmp(current_line,"if (",4)){
			
		}
		
	
	
	
	
	
	
	
	
	
	
	
	}
	
	
	
	
}
