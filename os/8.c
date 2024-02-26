#include <stdio.h>
#include <stdlib.h> // added header file for system function
#include <string.h> // added header file for strcmp and strcpy functions
struct dir {
  char dname[10]; // added array to store directory name
  int fcnt;       // added variable to store file count
  char fname[10][10]; // added array to store file names
} dir; // declared a variable of type struct dir
int main() {
  int i, ch;
  char f[30];
  system("cls"); // clear the screen
  dir.fcnt = 0;
  printf("\nEnter name of directory: ");
  scanf("%s", dir.dname);
  while (1) {
    printf("\n\n 1. Create File\t2. Delete File\t3. Search File \n 4. Display Files\t5. Exit\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      printf("\n Enter the name of the file: ");
      scanf("%s", dir.fname[dir.fcnt]);
      dir.fcnt++;
      break;
    case 2:
      printf("\n Enter the name of the file: ");
      scanf("%s", f);
      for (i = 0; i < dir.fcnt; i++) {
        if (strcmp(f, dir.fname[i]) == 0) {
          printf("File %s is deleted", f);
          strcpy(dir.fname[i], dir.fname[dir.fcnt - 1]);
          break;
        }
      }
      if (i == dir.fcnt)
        printf("File %s not found", f);
      else
        dir.fcnt--;
      break;
    case 3:
      printf("\n Enter the name of the file: ");
      scanf("%s", f);
      for (i = 0; i < dir.fcnt; i++) {
        if (strcmp(f, dir.fname[i]) == 0) {
          printf("File %s is found", f);
          break;
        }
      }
      if (i == dir.fcnt)
        printf("File %s not found", f);
      break;
    case 4:
      if (dir.fcnt == 0)
        printf("\n Directory Empty");
      else {
        printf("\n The Files are: ");
        for (i = 0; i < dir.fcnt; i++)
          printf("\t%s", dir.fname[i]);
      }
      break;
    default:
      exit(0);
    }
  }
  getchar(); // wait for a key press
  return 0;
}
