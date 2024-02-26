#include <stdio.h>
int main() {
  int a[10], frame[10], no, k, avail, count = 0;
  printf("\n ENTER THE NUMBER OF PAGES:\n");
  scanf("%d", &no);
  printf("\n ENTER THE PAGE NUMBER :\n");
  for (k = 1; k <= no; k++)
    scanf("%d", &a[k]);
  printf("\n ENTER THE NUMBER OF FRAMES :");
  scanf("%d", &no);
  for (k = 0; k < no; k++)
    frame[k] = -1;
  j = 0;
  printf("\tref string\t page frames\n");
  for (k = 1; k <= no; k++) {
    printf("%d\t\t", a[k]);
    avail = 0;
    for (i = 0; i < no; i++)
      if (frame[i] == a[k])
        avail = 1;
    if (avail == 0) {
      frame[j] = a[k];
      j = (j + 1) % no;
      count++;
      for (i = 0; i < no; i++)
        printf("%d\t", frame[i]);
    }
    printf("\n");
  }
  printf("Page Fault Is %d", count);
  return 0;
}
