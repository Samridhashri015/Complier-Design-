#include<stdio.h>
#include<string.h>
int main(){
char lhs,prod1[50],prod2[50],alpha[50],beta[50];
printf("Enter Left Recursive Production (Example: E=E+T): ");
scanf("%c=%s",&lhs,prod1);
if(prod1[0]==lhs){
strcpy(alpha,prod1+1);
printf("Enter Non Recursive Production (Example: E=T): ");
scanf(" %c=%s",&lhs,prod2);
strcpy(beta,prod2);
printf("\nAfter Removing Left Recursion:\n");
printf("%c -> %s%c'\n",lhs,beta,lhs);
printf("%c' -> %s%c' | e\n",lhs,alpha,lhs);
}
else{
printf("\nNo Immediate Left Recursion Found.\n");
}
return 0;
}
