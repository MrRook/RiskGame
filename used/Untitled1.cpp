#include<stdio.h>

int main()
{
FILE *fp;
unsigned char ch;
/* file 'abc.c' contains "This is Effervescence MM12 " */
fp=fopen("abc.c", "r");
if(fp == NULL)
{
printf("Unable to open file");
}
while((ch=getc(fp)) != EOF)
printf("%c", ch);

fclose(fp);
printf("\n", ch);
return 0;
}
