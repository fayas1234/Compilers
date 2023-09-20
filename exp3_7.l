%{
int lines=1;
%}

%%
"\n" {lines++;printf("%d ",lines);}
"$" {return(0);}
. {;}
%%

int yywrap(){
}

int main()
{
	printf("\nEnter lines:\n1 ");
	
	yylex();
}
	
