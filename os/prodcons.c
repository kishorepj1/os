#include <stdio.h>
#include <stdlib.h>
int mutex = 1;
int full = 0;
int empty = 10, x = 0; // Initialize a mutex to 1
                        // Number offull slots as 0
                        // Number of empty slots as size of buffer
void producer() {
  --mutex; // Function to produce an item and add it to the buffer
           // Decrease mutex value by 1
  ++full;  // Increase the number offull slots by 1
  --empty; // Decrease the number of empty slots by 1
  x++;     // Item produced
  printf("\nProducer produces item %d", x);
  ++mutex; // Increase mutex value by 1
}
void consumer() {
  // Function to consume an item and remove it from buffer
  --mutex; // Decrease mutex value by 1
  --full;  // Decrease the number offull slots by 1
  ++empty; // Increase the number of empty slots by 1
  printf("\nConsumer consumes item %d", x);
  x--;
  ++mutex; // Increase mutex value by 1
}
// Driver Code
int main() {
  int n;
  printf("\n press 1 for Producer");
  printf("\n press 2 for Consumer");
  printf("\n press 3 for Exit");
  printf("\nEnter your choice:");
  scanf("%d", &n);
  switch (n) {
  case 1:
    if ((mutex == 1) && (empty != 0)) // If mutex is I and empty is non-zero, then
                                      // it is possible to produce
    {
      producer();
    } else // Otherwise, print buffer is full
    {
      printf("Buffer is full!");
    }
    break;
  case 2:
    // Ifmutex is 1 and full is non-zero, then it is possible to consume
    if ((mutex == 1) && (full != 0)) {
      consumer();
    } else {
      printf("Buffer is empty!"); // Otherwise, print Buffer is empty
    }
    break;
  case 3:
    // Exit Condition
    exit(0);
  }
  return 0; // added return statement
}
