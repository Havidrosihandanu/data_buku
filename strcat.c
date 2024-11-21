#include <stdio.h>
#include <string.h>
int main() {
   char word[20];

   strcpy(word, "Hello");
   strcat(word, " world!");

   printf("%s\n", word);
}