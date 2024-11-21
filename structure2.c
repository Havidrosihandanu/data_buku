#include <stdio.h>
#include <string.h>
struct category
{
  int id, name;
};

struct buku
{
  char nrp[15];
  char nama[30];
  struct category categories;
};
struct mahasiswa MHS;
struct mahasiswa data_mhs[10] = {{"3124500039", "Misyael Yosevian Wiarda", 9, 11, 2003},
                                 {"3124500024", "Rafif Yosevian Wiarda", 12, 8, 2005},
                                 {"3124500029", "padidi Yosevian Wiarda", 9, 10, 2009}};
int N = 3;
void printStruct(struct mahasiswa data)
{
  printf("\n###### Data Mahasiswa ######\n");
  printf("NRP : %s\n", data.nrp);
  printf("Nama : %s\n", data.nama);
  printf("Tanggal lahir : %d/%d/%d\n\n", data.birthday.day, data.birthday.month, data.birthday.year);
}

struct mahasiswa input()
{
  struct mahasiswa mhs;
  printf("Masukkan NRP: ");
  fgets(&mhs.nrp, 15, stdin);
  printf("Masukkan Nama: ");
  fgets(&mhs.nama, 30, stdin);
  printf("Masukkan Tanggal Lahir (dd/mm/yyyy): ");
  scanf("%d %d %d", &mhs.birthday.day, &mhs.birthday.month, &mhs.birthday.year);
  return mhs;
}
void addData()
{
  char lagi;
  do
  {
    data_mhs[N] = input();
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