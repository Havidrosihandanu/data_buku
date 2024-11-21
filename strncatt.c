#include <stdio.h>
#include <string.h>
int main() {
   char word1[50];
   char word2[50] = " Students Informatics Engineering";

   strcpy(word1, "Hello");
   strncat(word1, word2, 21);

   printf("%s\n", word1);
}