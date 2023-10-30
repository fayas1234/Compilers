%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(char *str)
{
printf("%s\n", str);
exit(0);
}
%}
%token A B NL
%%
st: x y nl {printf("\nMatched\n");yyparse();}
x: A x|A
y: B y|B
nl: NL
%%
int yywrap()
{
return 1;
}
int main()
{
yyparse();
return 0;
}
