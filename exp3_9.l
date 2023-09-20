
%%
"abc" {printf("ABC");}
[a-zA-Z0-9] {printf("%s",yytext);}
"\n" {printf("\n");return(0);}
%%

