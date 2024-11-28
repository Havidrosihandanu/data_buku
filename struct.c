#include <stdio.h>
#include <string.h>
struct category
{
  int id;
  char name[30];
};

struct buku
{
  char judul[30];
  char pengarang[30];
  char penerbit[30];
  char tahun_terbit[30];
  struct category categories;
};

struct buku data_buku[10] = {{"Pemrograman C", "Misyael Yosevian Wiarda", "Dino Ariel", "10 - 11 - 2003", 1, "Programming"},
{"Pemrograman C", "Misyael Yosevian Wiarda", "Dino Ariel", "10 - 11 - 2003", 2, "Programming"},
{"Pemrograman C", "Misyael Yosevian Wiarda", "Dino Ariel", "10 - 11 - 2003", 3, "Programming"}};
int N = 3;
void printStruct(struct buku data_buku)
{
  printf("\n###### Data Mahasiswa ######\n");
  printf("NRP : %s\n", data_buku.judul);
  printf("PENGARANG : %s\n", data_buku.pengarang);
  printf("PENERBIT : %s\n", data_buku.penerbit);
  printf("TAHUN TERBIT : %s\n", data_buku.tahun_terbit);
  printf("CATEGORY : %s\n", data_buku.categories.name);
}

struct buku input()
{
  struct buku data_buku;
  printf("Masukkan Judul: ");
  fgets(&data_buku.judul, 15, stdin);
  printf("Masukkan Pengarang: ");
  fgets(&data_buku.pengarang, 30, stdin);
  printf("Masukkan penerbit: ");
  fgets(&data_buku.penerbit, 30, stdin);
  printf("Masukkan tahun terbit: ");
  fgets(&data_buku.tahun_terbit, 30, stdin);
  printf("Masukkan category: ");
  fgets(&data_buku.categories.name, 30, stdin);
  return data_buku;
}
void addData()
{
  char lagi;
  do
  {
    data_buku[N] = input();
    fflush(stdin);
    printf("\nMau memasukkan data lagi [Y/T] ? ");
    lagi = getchar();
    fflush(stdin);
    N++;
  } while (lagi == 'Y' || lagi == 'y');
  printStructAll(N);
}
void printStructAll(int n)
{
  for (int i = 0; i < n; i++)
  {
    printStruct(data_buku[i]);
  }
}
int menu()
{
  int pilih;
  printf("Pilihan menu\n");
  printf("1: View\n");
  printf("2: Add data\n");
  printf("3: Searching NRP\n");

  printf("Pilih: ");
  scanf("%d", &pilih);

  return pilih;
}
struct buku searchingJudul(char judul[])
{
  for (int i = 0; i < N; i++)
  {
    if (strcmp(data_buku[i].judul, judul) == 0)
    {
      return data_buku[i];
    }
  }
}
int main()
{
  char lagiMenu;
  do
  {
    int pilih = menu();
    fflush(stdin);

    if (pilih == 1)
    {
      printStructAll(N);
    }
    else if (pilih == 2)
    {
      addData();
    }
      // else if (pilih == 3)
      // {
      //   struct mahasiswa hasil = searchingNRP("3124500024");
      //   printStruct(hasil);
      // }
    fflush(stdin);
    printf("\nMau memasukkan data lagi [Y/T] ? ");
    lagiMenu = getchar();
    fflush(stdin);
  } while (lagiMenu == 'Y' || lagiMenu == 'y');

  return 0;
}