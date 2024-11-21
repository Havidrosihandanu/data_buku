#include <stdio.h>
#include <string.h>

int main() {
   char word1[50];
   char word2[50];

   strcpy(word1, "Hello, I'm student Informatics Engineering");
   strncpy(word2, word1, 5);
   word2[5] = '\0';  

   printf("Word 1  : %s\n", word1);
   printf("Word 2  : %s\n", word2);

   return 0;
}
