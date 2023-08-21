//Program to implement lexical analyser

#include <stdio.h>
#include <string.h>

void main()
{

	char str[2048];
	
	FILE *f1=fopen("input.txt","r");
	
	while(!feof(f1))
	{
		fgets(str+strlen(str),sizeof(str)-strlen(str),f1);
	}
	
	int i=0;
	
	int len=strlen(str);
	
	while(i<=len)
	{
		if(str[i]=='/')
		{	
			//Ignore
			while(str[i]!='\n')
				l++;
		}
		
		if(str[i]=='#' || str[i]==',' || str[i]==';')
		{
			printf("PUNC ");
		}
		
		if(isalpha(str[i]))
		{
			char arr[200];
			memset(arr,'\0',sizeof(arr));
			
			int index=0;
			
			while(isalpha(str[i])
			{
				arr[index++]=str[i];
				i++;
			}
			
			if(isKeyword(arr))
			{
				printf("KEYWD ");
			}
			else
			{
				printf("ID ");
			}
			
		}
			
				
		 
}

