%{
#include <stdio.h>

int ch;

%}

%%

"(+91)-"[0-9]{10}  {
             if(ch==2)
             	printf("Recognized a 10-digit phone number with international code: %s\n", yytext);
             return(0);
           }
           
[0-9]{10}  {
             if(ch==1)
             	printf("Recognized a 10-digit phone number: %s\n", yytext);
             return(0);
           }


.|\n      { /* Ignore all other characters */ }

%%

int main() {
    printf("Enter a string (Ctrl-D to end):\n");
    
    do
    {
    	printf("\n1-Phone number\n");
    	printf("2-Phone number with international code\n");
    	
    	printf("\nEnter your choice:");
    	
    	scanf("%d",&ch);
    	
    	if(ch==0 && ch>2) 
    		return(0);
    		
    	yylex();
    		
    }while(ch!=0);
    
}

