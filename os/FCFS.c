#include <stdio.h>
int main() {
  int pid[15];
  int bt[15];
  int n;
  printf("Enter the number of processes: ");
  scanf("%d", &n);

  printf("Enter process id of all the processes: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &pid[i]);
  }
  printf("Enter burst time of all the processes: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &bt[i]);
  }
  int i, wt[n];
  wt[0] = 0;
  for (i = 1; i < n; i++) // for calculating waiting time
  {
    wt[i] = bt[i - 1] + wt[i - 1];
  }
  printf("Process ID Burst Time Waiting Time TurnAround Time\n");
  float twt = 0.0; // calculating total waiting time
  float tat = 0.0; // calculating total turnaround time
  for (i = 0; i < n; i++) {
    twt += wt[i];
    tat += (wt[i] + bt[i]);
    printf("%d\t\t", pid[i]);
    printf("%d\t\t", bt[i]);
    printf("%d\t\t", wt[i]);
    printf("%d\n", bt[i] + wt[i]);
  }
  float att, awt;
  awt = twt / n; // for calculating average waiting time
  att = tat / n; // for calculating average turnaround time
  printf("Avg. waiting time= %f\n", awt);
  printf("Avg. turnaround time= %f\n", att);

  return 0; // added return statement
}
