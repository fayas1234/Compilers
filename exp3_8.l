%%
[\n|\t|A-Z|" "] {;}
. {fputs(yytext,yyout);}
%%

int yywrap(){
}

int main()
{
	yyin=fopen("input.txt","r");
	yyout=fopen("output.txt","w");
	
	yylex();
	
	printf("Done \n");
	return(0);
}
	
