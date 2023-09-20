%{
int count=0;
%}

%%
"\n" {count++;}
"$" {return(0);}
. {;}
%%

int yywrap(){
}

int main()
{
	printf("\nEnter a line:\n");
	
	yylex();
	
	printf("\nNumber of lines is %d\n",count);
}
	
