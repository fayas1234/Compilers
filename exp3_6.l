%%
[a-zA-Z0-9]+ {printf("word:%s length:%d\n",yytext,yyleng);}
"$" {return(0);}
.|"\n" {;}
%%

int yywrap(){
}

int main()
{
	printf("\nEnter a line:\n");
	
	yylex();
}
	
