#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <time.h>

int main() {

  struct stat finfo;
  if(stat("normal_distribution.c", &finfo) == -1) {
    printf("%s\n", strerror(errno));
  }

  int size = finfo.st_size;
  int permissions = finfo.st_mode;
  time_t time = finfo.st_atime;

  // printf("%d\n", size);

  if(size / 1000000.0 > 1000) {
    printf("Size: %fGB\n", size/1000000000.0);
  } else if(size / 1000000.0 > 1) {
    printf("Size: %fMB\n", size/1000000.0);
  } else if(size / 1000.0 > 1) {
    printf("Size: %fKB\n", size/1000.0);
  } else {
    printf("Size: %dB\n", size);
  }
  printf("Permissions: %o\n", permissions);
  printf("Time Last Accessed: %s\n", ctime(&time));
}
