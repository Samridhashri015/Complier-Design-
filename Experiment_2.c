#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 20
char trans[50][50];
int stateCount=0;
void initialize(){
int i,j;
for(i=0;i<50;i++)
for(j=0;j<50;j++)
trans[i][j]=' ';
}
void addTransition(int from,int to,char symbol){
trans[from][to]=symbol;
}
int main(){
char regex[MAX];
int i,start=0,end=0;
initialize();
printf("REGULAR EXPRESSION TO NFA\n");
printf("Enter Regular Expression: ");
scanf("%s",regex);
int len=strlen(regex);
for(i=0;i<len;i++){
if(isalpha(regex[i])){
addTransition(stateCount,stateCount+1,regex[i]);
stateCount++;
}
else if(regex[i]=='|'){
int prevStart=stateCount-1;
addTransition(prevStart+1,prevStart+2,'E');
addTransition(prevStart+2,prevStart+3,regex[i+1]);
stateCount+=3;
i++;
}
else if(regex[i]=='*'){
addTransition(stateCount,stateCount-1,'E');
addTransition(stateCount-1,stateCount,'E');
}
else if(regex[i]=='+'){
addTransition(stateCount-1,stateCount-2,'E');
}
}
end=stateCount;
printf("\nTransition Table:\n\n  ");
for(i=0;i<=end;i++)
printf("%d ",i);
printf("\n");
for(i=0;i<=end;i++){
printf("%d ",i);
int j;
for(j=0;j<=end;j++)
printf("%c ",trans[i][j]);
printf("\n");
}
printf("\nStart State: 0\n");
printf("Final State: %d\n",end);
return 0;
}