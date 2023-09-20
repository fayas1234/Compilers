%{
int vowels=0,consonants=0;
%}

%%
[aeiouAEIOU] {vowels++;}
[A-Za-z] {consonants++;}
"$" {return(0);}
.|"\n" {;}
%%

int yywrap(){
}

int main()
{
	printf("\nEnter a line:\n");
	
	yylex();
	
	printf("\nNumber of vowels is %d\n",vowels);
	printf("\nNumber of consonants is %d\n",consonants);
}
	
