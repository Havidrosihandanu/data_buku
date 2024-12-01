#include <stdio.h>
#include <string.h>
struct penerbit
{
  char name[30];
  char alamat[50];
};

struct buku
{
  char judul[30];
  char pengarang[30];
  char tahun_terbit[30];
  struct penerbit data_penerbit;
};

struct buku data_buku[10] = {
    {"Pemrograman C", "Dino Ariel", "10 - 11 - 2003", "Havid", "Ponorogo"},
    {"Web Desain", "Dino Ariel", "10 - 11 - 2003", "Havid", "Ponorogo"},
    {"Fisika", "Dino Ariel", "10 - 11 - 2003", "Havid", "Ponorogo"},
    {"Matematika C", "Dino Ariel", "10 - 11 - 2003", "Havid", "Ponorogo"}};

int N = 3;
void printStruct(struct buku data_buku)
{
  printf("\n========== Data Buku ==========\n");
  printf("JUDUL : %s\n", data_buku.judul);
  printf("PENGARANG : %s\n", data_buku.pengarang);
  printf("TAHUN TERBIT : %s\n", data_buku.tahun_terbit);
  printf("PENERBIT : %s\n", data_buku.data_penerbit.name);
  printf("ALAMAT PENERBIT : %s\n", data_buku.data_penerbit.alamat);
}

struct buku input()
{
  struct buku data_buku;
  printf("Masukkan Judul: ");
  fgets(&data_buku.judul, 15, stdin);
  printf("Masukkan Pengarang: ");
  fgets(&data_buku.pengarang, 30, stdin);
  printf("Masukkan tahun terbit: ");
  fgets(&data_buku.tahun_terbit, 30, stdin);
  printf("Masukkan Penerbit: ");
  fgets(&data_buku.data_penerbit.name, 30, stdin);
  printf("Masukkan Alamat Penerbit: ");
  fgets(&data_buku.data_penerbit.alamat, 30, stdin);
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
  int pilihan;
  printf("Pilihan menu\n");
  printf("1: Show Buku\n");
  printf("2: Add Buku\n");
  printf("3: Searching By Judul\n");

  printf("Pilih: ");
  scanf("%d", &pilihan);

  return pilihan;
}

struct buku searchingJudul(char judul[])
{
  int found = 0;
  for (int i = 0; i < N; i++)
  {
    if (strstr(data_buku[i].judul, judul))
    {
      // Jika ditemukan, tampilkan data buku
      printf("\nBuku ditemukan:\n");
      printStruct(data_buku[i]);
      found = 1;
    }
  }
  if (!found)
  {
    printf("Buku dengan judul \"%s\" tidak ditemukan.\n", judul);
  }
}
int main()
{
  char search[200];
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
    else if (pilih == 3)
    {
      printf("Masukkan kata kunci: ");
      fgets(search, 30, stdin);
      search[strcspn(search, "\n")] = '\0';
      searchingJudul(search);
      printf(search);
    }
    fflush(stdin);
    printf("\nMau memasukkan data lagi [Y/T] ? ");
    lagiMenu = getchar();
    fflush(stdin);
  } while (lagiMenu == 'Y' || lagiMenu == 'y');

  return 0;
}