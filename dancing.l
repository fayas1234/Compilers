%{
#include <stdio.h>
#include <ctype.h> // For isupper and islower functions
%}

%%

[A-Za-z]+ {
             return(0);
           }

.|\n       { /* Ignore all other characters */ }

%%

void fun()
{
    // Loop through each character in the matched string
    for(int i = 0; i < yyleng; i++) 
    {
    	if(islower(yytext[i])) // If character is lowercase
    		yytext[i] = toupper(yytext[i]); // Convert to uppercase
    	
    	else if(isupper(yytext[i])) // If character is uppercase
    		yytext[i] = tolower(yytext[i]); // Convert to lowercase
    }
             
    printf("Converted string: %s, Length: %d\n", yytext, yyleng);
}

int main() {
    printf("Enter a string (Ctrl-D to end):\n");
    
    int ch;
    
    while(ch!=0)
    {

    	yylex();
    	fun();
    	
    	printf("\nDo you want to continue:");
    	scanf("%d",&ch);
    }
    
    return 0;
}

