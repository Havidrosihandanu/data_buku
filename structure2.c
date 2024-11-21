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
// struct mahasiswa MHS;
struct buku data_buku[10] = {{"Pemrograman C", "Misyael Yosevian Wiarda", "Dino Ariel", 10 - 11 - 2003, 1, "Programming"}};
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
  printf("Masukkan NRP: ");
  fgets(&data_buku.nrp, 15, stdin);
  printf("Masukkan Nama: ");
  fgets(&data_buku.nama, 30, stdin);
  printf("Masukkan Tanggal Lahir (dd/mm/yyyy): ");
  scanf("%d %d %d", &data_buku.birthday.day, &data_buku.birthday.month, &data_buku.birthday.year);
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
    printStruct(data_mhs[i]);
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
struct mahasiswa searchingNRP(char nrp[])
{
  for (int i = 0; i < N; i++)
  {
    if (strcmp(data_mhs[i].nrp, nrp) == 0)
    {
      return data_mhs[i];
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
    else if (pilih == 3)
    {
      struct mahasiswa hasil = searchingNRP("3124500024");
      printStruct(hasil);
    }
    fflush(stdin);
    printf("\nMau memasukkan data lagi [Y/T] ? ");
    lagiMenu = getchar();
    fflush(stdin);
  } while (lagiMenu == 'Y' || lagiMenu == 'y');

  return 0;
}