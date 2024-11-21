#include <stdio.h>
#include <string.h>
int main()
{
    char str1[100], str2[100];

    printf("masukkan string 1:");
    fgets(str1, 100, stdin);
    str1[strcspn(str1, "\n")] = '\0';

    strlwr(str1);
    printf("str 1 sebelum reverse: %s\n", str1);

    strcpy(str2, str1);
    printf("str 2: %s\n", str2);

    strrev(str1);
    printf("str 1 setelah reverse: %s\n", str1);

    str2[strcspn(str2, "\n")] = '\0';
    if (strcmp(str1, str2) == 0)
    {
        printf("palindrome\n");
    }
    else
    {
        printf("bukan palindrome\n");
    }
}