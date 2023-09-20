%{
int lines=0,words=0,blanks=0,chars=0;
%}

%%
"\n" {lines++;}
[a-zA-Z0-9]+ {words++;chars+=yyleng;}
" " {blanks++;}
"$" {return(0);}
%%

int yywrap(){
}

int main()
{
	printf("\nEnter a line:\n");
	
	yylex();
	
	printf("\nNumber of lines is %d\n",lines);
	printf("\nNumber of words is %d\n",words);
	printf("\nNumber of blanks is %d\n",blanks);
	printf("\nNumber of characters is %d\n",chars);
}
	
