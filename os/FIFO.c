#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
  int fd;
  char buff[1024];
  char *myfifo = "/tmp/myfifo";
  mkfifo(myfifo, 0666); // create the FIFO (named pipe)
  printf("Run Reader process to read the FIFO File\n");
  fd = open(myfifo, O_WRONLY); // open the FIFO
  write(fd, "Hi", sizeof("Hi")); // write "Hi" to the FIFO
  close(fd);                    // close the FIFO
  unlink(myfifo);               // remove the FIFO
  return 0;
}
