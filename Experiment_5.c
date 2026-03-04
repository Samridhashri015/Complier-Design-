#include<stdio.h>
#include<string.h>
#include<ctype.h>
char prod[10][10];
char first[10],follow[10];
int n;
void findFirst(char c){
int i;
if(!isupper(c)){
printf("%c ",c);
return;
}
for(i=0;i<n;i++){
if(prod[i][0]==c){
if(prod[i][2]=='#')
printf("# ");
else if(!isupper(prod[i][2]))
printf("%c ",prod[i][2]);
else
findFirst(prod[i][2]);
}
}
}
void findFollow(char c){
int i,j;
if(prod[0][0]==c)
printf("$ ");
for(i=0;i<n;i++){
for(j=2;j<strlen(prod[i]);j++){
if(prod[i][j]==c){
if(prod[i][j+1]!='\0'){
if(!isupper(prod[i][j+1]))
printf("%c ",prod[i][j+1]);
else
findFirst(prod[i][j+1]);
}
else if(c!=prod[i][0])
findFollow(prod[i][0]);
}
}
}
}
int main(){
int i;
printf("Enter number of productions: ");
scanf("%d",&n);
printf("Enter productions in form A=B (use # for epsilon):\n");
for(i=0;i<n;i++)
scanf("%s",prod[i]);
printf("\nFIRST Sets:\n");
for(i=0;i<n;i++){
printf("FIRST(%c) = { ",prod[i][0]);
findFirst(prod[i][0]);
printf("}\n");
}
printf("\nFOLLOW Sets:\n");
for(i=0;i<n;i++){
printf("FOLLOW(%c) = { ",prod[i][0]);
findFollow(prod[i][0]);
printf("}\n");
}
return 0;
}
