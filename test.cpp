#include<stdio.h>
#include<string.h>

int main()
{
    char a[10];
    fgets(a,10,stdin);
    printf("%s",a);
    if(strcmp(a,"haha")==0) printf("haha");
    if(strcmp(a,"haha")!=1) printf("not haha");
}