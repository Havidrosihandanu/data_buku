#include <stdio.h>
#include <string.h>

int main()
{
    char word[100] = " INFORMATICS ENGINEERING, ELECTRONIC ENGINEERING, MULTIMEDIA CREATIVE ";
    char *tok;
    tok = strtok(word, ",");
    while (tok != 0)
    {
        printf("%s\n", tok);
        tok = strtok(0, ",");
    }
    return 0;
}
