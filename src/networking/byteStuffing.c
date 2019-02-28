#include <stdio.h>
#include <string.h>
void sender(char *s, char *newData){
newData[0]='$';
int n = strlen(s), i, count=1;
for(i=0;i<n;i++){
if(s[i]!='$' && s[i]!='@')
newData[count++]=s[i];
else {
newData[count++]='$';
newData[count++]=s[i];
}
}
newData[count++]='$';
}
void receiver(char *s){
printf("\nByte stuffed data: %s\n", s);
char recData[100];
int n = strlen(s), i, count=0;
for(i=1;i<n-1;i++){
if(s[i]=='$' && i+1<n-1)recData[count++]=s[++i];
else
recData[count++]=s[i];
}
printf("\nReceived Word: %s", recData);
}
void main(){
char s[100], newData[101];
printf("Enter a string: ");
scanf("%s",s);
sender(s, newData);
receiver(newData);
}
