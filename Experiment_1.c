#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
int checkKeyword(char *str){
char
*kw[]={"int","float","char","double","if","else","while","for","do","break","continue","return","void
","switch","case","long","short","unsigned","signed","static","struct"};
int total=sizeof(kw)/sizeof(kw[0]);
for(int i=0;i<total;i++){
if(strcmp(str,kw[i])==0)
return 1;
}
return 0;
}
int validIdentifier(char *str){
if(isdigit(str[0]))
return 0;
for(int i=0;str[i]!='\0';i++){
if(!isalnum(str[i])&&str[i]!='_')
return 0;
}
return 1;
}
int main(){
FILE *file;
char ch;
char token[MAX];
int index=0;
file=fopen("program.txt","r");
if(file==NULL){
printf("File not found.\n");
return 1;
}
printf("Tokens Identified:\n");
while((ch=fgetc(file))!=EOF){
if(isalnum(ch)||ch=='_'){
token[index++]=ch;
}
else{
if(index>0){
token[index]='\0';
if(checkKeyword(token))
printf("Keyword : %s\n",token);
else if(validIdentifier(token))
printf("Identifier : %s\n",token);
else
printf("Invalid Token : %s\n",token);
index=0;
}
if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='='||ch=='%')
printf("Operator : %c\n",ch);
if(ch=='('||ch==')'||ch==';'||ch==',')
printf("Special Symbol : %c\n",ch);
}
}
fclose(file);
return 0;
}
