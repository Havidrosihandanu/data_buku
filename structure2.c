#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 10

struct Penerbit
{
  char name[30];
  char alamat[50];
};

struct Buku
{
  char judul[30];
  char pengarang[30];
  char tahun_terbit[30];
  struct Penerbit data_penerbit;
};

struct Buku data_buku[MAX_BOOKS] = {
    {"Code Complete: A Practical Handbook of Software Construction", "Steve McConnell", "2004", {"Microsoft Press", "Redmond, Washington, USA"}},
    {"Refactoring: Improving the Design of Existing Code", "Martin Fowler", "1999", {"Addison-Wesley", "Boston, Massachusetts, USA"}},
    {"Software Engineering: A Practitioner's Approach", "Roger S. Pressman", "2014", {"McGraw-Hill Education", "New York, USA"}},
    {"The Mythical Man-Month: Essays on Software Engineering", "Frederick P. Brooks Jr.", "1975", {"Addison-Wesley", "Boston, Massachusetts, USA"}},
    {"Patterns of Enterprise Application Architecture", "Martin Fowler", "2002", {"Addison-Wesley", "Boston, Massachusetts, USA"}},
    {"Agile Estimating and Planning", "Mike Cohn", "2005", {"Prentice Hall", "Upper Saddle River, New Jersey, USA"}}};

int countBookData = 6;


void printStruct(struct Buku data_buku)
{
  printf("TITLE: %s\n", data_buku.judul);
  printf("AUTHOR: %s\n", data_buku.pengarang);
  printf("PUBLICATION YEARS: %s\n", data_buku.tahun_terbit);
  printf("PUBLISHER NAME: %s\n", data_buku.data_penerbit.name);
  printf("PUBLISHER ADDRESS: %s\n", data_buku.data_penerbit.alamat);
}

struct Buku input()
{
  struct Buku data_buku;
  printf("Insert Book Title: ");
  fgets(data_buku.judul, sizeof(data_buku.judul), stdin);
  data_buku.judul[strcspn(data_buku.judul, "\n")] = '\0';

  printf("Insert Book Author: ");
  fgets(data_buku.pengarang, sizeof(data_buku.pengarang), stdin);
  data_buku.pengarang[strcspn(data_buku.pengarang, "\n")] = '\0';

  printf("Insert Book Year of Publication: ");
  fgets(data_buku.tahun_terbit, sizeof(data_buku.tahun_terbit), stdin);
  data_buku.tahun_terbit[strcspn(data_buku.tahun_terbit, "\n")] = '\0';

  printf("Insert Publisher Name: ");
  fgets(data_buku.data_penerbit.name, sizeof(data_buku.data_penerbit.name), stdin);
  data_buku.data_penerbit.name[strcspn(data_buku.data_penerbit.name, "\n")] = '\0';

  printf("Insert Publisher Address: ");
  fgets(data_buku.data_penerbit.alamat, sizeof(data_buku.data_penerbit.alamat), stdin);
  data_buku.data_penerbit.alamat[strcspn(data_buku.data_penerbit.alamat, "\n")] = '\0';

  return data_buku;
}

void addData()
{
  char lagi;
  do
  {
    if (countBookData >= MAX_BOOKS)
    {
      printf("\nData storage is full. Cannot add more books.\n");
      break;
    }

    data_buku[countBookData] = input();
    countBookData++;

    do
    {
      printf("\nWant to enter data again [Y/T]? ");
      scanf(" %c", &lagi);
      getchar();
      lagi = toupper(lagi);
    } while (lagi != 'Y' && lagi != 'T');

  } while (lagi == 'Y');

  printStructAll(countBookData);
}

void printStructAll(int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("\n");
    printStruct(data_buku[i]);
    printf("_______________________________________________\n");
  }
}

int menu()
{
  int pilihan;
  printf("Select Menu\n");
  printf("1: Show All Books\n");
  printf("2: Add Book\n");
  printf("3: Search Books\n");

  printf("Choose: ");
  scanf("%d", &pilihan);
  getchar();
  return pilihan;
}

void searching(char data[], int pil)
{
  int found = 0;
  if (pil == 1)
  {
    printf("\nBook with title \"%s\" found:\n", data);
  }
  else if (pil == 2)
  {
    printf("\nBook with publisher \"%s\" found:\n", data);
  }
  else
  {
    printf("\nBook with publication year \"%s\" found:\n", data);
  }
  for (int i = 0; i < countBookData; i++)
  {
    if (pil == 1)
    {
      if (strstr(data_buku[i].judul, data))
      {
        printf("\n");
        printStruct(data_buku[i]);
        printf("_______________________________________________\n");
        found = 1;
      }
    }
    else if (pil == 2)
    {
      if (strstr(data_buku[i].data_penerbit.name, data))
      {
        printf("\n");
        printStruct(data_buku[i]);
        printf("_______________________________________________\n");
        found = 1;
      }
    }
    else if (pil == 3)
    {
      if (strstr(data_buku[i].tahun_terbit, data))
      {
        printf("\n");
        printStruct(data_buku[i]);
        printf("_______________________________________________\n");
        found = 1;
      }
    }
    else
    {
      printf("\nInvalid input.\n");
    }
  }
  if (!found)
  {
    if (pil == 1)
    {
      printf("\nNo books found with Title\"%s\".\n", data);
    }
    else if (pil == 2)
    {
      printf("\nNo books found with Publisher\"%s\".\n", data);
    }
    else
    {
      printf("\nNo books found with Publication Year\"%s\".\n", data);
    }
  }
}

int main()
{
  char search[200];
  char lagiMenu;
  do
  {
    int pilih = menu();

    if (pilih == 1)
    {
      printf("\n==================== BOOKS DATA ====================\n");
      printStructAll(countBookData);
    }
    else if (pilih == 2)
    {
      addData();
    }
    else if (pilih == 3)
    {
      int pilihan;
      printf("Search By ?\n");
      printf("1. Title\n");
      printf("2. Publisher\n");
      printf("3. Publication Year\n");
      printf("Choose: ");
      scanf("%d", &pilihan);
      getchar();

      printf("Input Keywords: ");
      fgets(search, sizeof(search), stdin);
      search[strcspn(search, "\n")] = '\0';
      searching(search, pilihan);
    }
    else
    {
      printf("\nInvalid Input\n");
    }

    printf("\nBack to Main Menu? [Y/T] ");
    lagiMenu = getchar();
    getchar();
  } while (lagiMenu == 'Y' || lagiMenu == 'y');

  return 0;
}
