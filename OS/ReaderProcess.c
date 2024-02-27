// Reader Process
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h> // added header file for sizeof function
#define MAX_BUF 1024
int main1() {
  int fd;
  // A temp FIFO file is not created in reader
  char *myfifo = "/tmp/myfifo";
  char buf[MAX_BUF];
  // open, read, and display the message from the FIFO
  // open the FIFO
  fd = open(myfifo, O_RDONLY);
  if (fd == -1) { // check the return value of open
    perror("open"); // print error message
    return 1;       // exit with non-zero status
  }
  // read from the FIFO
  if (read(fd, buf, MAX_BUF) == -1) { // check the return value of read
    perror("read");                   // print error message
    return 1;                         // exit with non-zero status
  }
  // display the message
  printf("Writer: %s\n", buf);
  // close the FIFO
  if (close(fd) == -1) { // check the return value of close
    perror("close");     // print error message
    return 1;            // exit with non-zero status
  }
  return 0; // added return statement
}
