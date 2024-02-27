// Writer Process
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h> // added header file for sizeof function
#include <stdlib.h> // added header file for exit function
int main() {
  int fd;
  char buff[1024];
  char *myfifo = "/tmp/myfifo";
  // create the FIFO (named pipe)
  if (mkfifo(myfifo, 0666) == -1) { // check the return value of mkfifo
    perror("mkfifo");               // print error message
    return 1;                       // exit with non-zero status
  }
  printf("Run Reader process to read the FIFO File\n");
  // open the FIFO
  fd = open(myfifo, O_WRONLY);
  if (fd == -1) { // check the return value of open
    perror("open"); // print error message
    return 1;       // exit with non-zero status
  }
  // write "Hi" to the FIFO
  if (write(fd, "Hi", sizeof("Hi")) == -1) { // check the return value of write
    perror("write");                         // print error message
    return 1;                                // exit with non-zero status
  }
  // close the FIFO
  if (close(fd) == -1) { // check the return value of close
    perror("close");     // print error message
    return 1;            // exit with non-zero status
  }
  // remove the FIFO
  if (unlink(myfifo) == -1) { // check the return value of unlink
    perror("unlink");         // print error message
    return 1;                 // exit with non-zero status
  }
  return 0;
}