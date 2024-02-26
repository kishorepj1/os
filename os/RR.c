#include <stdio.h>
#include <conio.h>
void main() {
  int i, NOP, sum = 0, count = 0, y, quant, wt = 0, tat = 0, at[10], bt[10],
      temp[10];
  float avg_wt, avg_tat;
  printf(" Total number of process in the system: ");
  scanf("%d", &NOP);

  y = NOP; // Assign the number of process to variable y
  // Use for loop to enter the details of the process like Arrival time and the
  // Burst Time
  for (i = 0; i < NOP; i++) {
    printf("\n Enter the Arrival and Burst time of the Process[%d]\n", i + 1);
    printf(" Arrival time is: \t");
    scanf("%d", &at[i]); // Accept arrival time
    printf(" \nBurst time is: \t");
    scanf("%d", &bt[i]); // Accept the Burst time
    temp[i] = bt[i];     // store the burst time in temp array
  }
  printf("Enter the Time Quantum for the process: \t"); // Accept the Time quantum
  scanf("%d", &quant);
  // Display the process No, burst time, Turn Around Time and the waiting time
  printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");
  for (sum = 0, i = 0; y != 0;) {
    if (temp[i] <= quant && temp[i] > 0) {
      sum = sum + temp[i];
      temp[i] = 0;
      count = 1;
    } else if (temp[i] > 0) {
      temp[i] = temp[i] - quant;
      sum = sum + quant;
    }
    if (temp[i] == 0 && count == 1) { // define the conditions
      y--;                            // decrement the process no.
      printf("\nProcess No %d \t\t", i + 1);
      printf("%d\t\t\t\t", bt[i]);
      printf("%d\t\t\t", sum - at[i]);
      printf("%d", sum - at[i] - bt[i]);
      wt = wt + sum - at[i] - bt[i];
      tat = tat + sum - at[i];
      count = 0;
    }
    if (i == NOP - 1) {
      i = 0;
    } else if (at[i + 1] <= sum) {
      i++;
    } else {
      i = 0;
    }
  }
  avg_wt = wt * 1.0 / NOP; // represents the average waiting time and Turn Around
                           // time
  avg_tat = tat * 1.0 / NOP; // represents the average Turn Around time
  printf("\n Average Turn Around Time: \t%f", avg_wt);
  printf("\n Average Waiting Time: \t%f", avg_tat);
  getch();
}
