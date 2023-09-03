//Program to implement lexical analyser

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char keywords[32][10] = {"auto","break","case","char","const","continue","default",
"do","double","else","enum","extern","float","for","goto",
"if","int","long","register","return","short","signed",
"sizeof","static","struct","switch","typedef","union",
"unsigned","void","volatile","while"};

int isKeyword(char arr[])
{
	int key=0;
	
	for(int i=0;i<32;i++)
	{
		if(strcmp(keywords[i],arr)==0)
		{
			key=1;
			break;
		}
	}
	
	return(key);
}

void main()
{
	char ch,buffer[15],operators[]="+-*/%";
	
	char lp[]="{[(",rp[]="}])";
	
	FILE *f1;
	int i,j=0;
	f1 = fopen("input.c","r");
	
	if(f1==NULL)
	{
		printf("error while opening the file\n");
		exit(0);
	}
	
	
	while((ch=fgetc(f1))!=EOF)
	{
	   int op=0;
	   for(i=0;i<5;i++)
	   {
		   if(ch==operators[i])
		   {
		   
		   	if(ch=='/')
		   	{
		   		char temp=fgetc(f1);
		   		
		   		if(ch==temp)
		   		{
		   			ch=temp;
		   			goto l2;
		   		}
		   		if(temp=='*')
		   		{
		   			ch=temp;
		   			goto l1;
		   		}
		   	}
		   	
		   	printf("OP ");
		   	
		   	op=1;
		   	break;
		   }
	   }
	   
	   
	   if(op==0)
	   {
	   	
	   	   if(ch=='=')
	   	   {
	   	   	printf("ASSIGN ");
	   	   	continue;
	   	   }
	   	   
		   if(ch=='"')
		   {
		   	while((ch=fgetc(f1))!='"');
		   	
		   	printf("LITERAL ");
		   	continue;
		   }
		  
		   if(ch=='#')
		   {
		   	while((ch=fgetc(f1))!='\n');
		   	
		   	continue;
		   }
		   
		   l1:
		   if(ch=='*')
		   {
		   
		   	while((ch=fgetc(f1))!='/');
		   	
		   	continue;
		   }
		   
		   l2:
		   if(ch=='/')
		   {
		   	
		   	while((ch=fgetc(f1))!='\n');
		   	
		   	continue;
		   }
		   
		   for(i=0;i<3;i++)
		   {
			if(ch==lp[i])
			{
			   printf("PUNC ");
			   break;
			}
		   }
		   	
		   for(i=0;i<3;i++)
		   {
			if(ch==rp[i])
			{
			   printf("PUNC ");
			   break;
			}
		   }
		   
		    	
		   if(ch==',')
		   {
		   	printf("PUNC ");
		   	continue;
		   }
		   
		   if(ch==';')
		   {
		   	printf("PUNC ");
		   	continue;
		   }
		   
		   if(isalnum(ch))
		   {
		   	buffer[j++]=ch;
		   }
		   else if((ch==' ' || ch=='\n') && j!=0)
		   {
			   buffer[j]='\0';
			  
			     
			   if(isKeyword(buffer) == 1)
			   	printf("KEY ");
			   else
			   {
			   	int flag=0;
			   	for(int i=0;i<j;i++)
			   	{
			   		if(!isdigit(buffer[i]))
			   		{
			   			flag=1;
			   			break;
			   		}
			   	}
			   	
			   	if(flag==0)
			   		printf("LITERAL ");
			   	else
			   		printf("ID ");
			   }
			   
			   j=0;
		   }
	   	
	   }
	  
	  
	}
	
	printf("\n");
	fclose(f1);

}
