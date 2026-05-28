#include <stdio.h>
#include <string.h>

int main()
{
    char arr1[1005];
    char arr2[1005];
    int n;
    int flag2 = 1;
    scanf("%d",&n);
    scanf("%s",arr1);
    scanf("%s",arr2);
    int largo = strlen(arr1);   
    for (int i = 0; i < largo; i++) {
        if (n % 2 == 0) {
            if (arr1[i] != arr2[i]) flag2 = 0;
        } else {
            if (arr1[i] == arr2[i]) flag2 = 0;
        }
    }
    if (flag2) 
    {
        printf("Deletion succeeded\n");
    } 
    else
    {
        printf("Deletion failed\n");
    }
    return 0;
}