#include <stdio.h>
#include <sys/stat.h>

int main() {

  struct stat * finfo;
  stat("normal_distribution.c", finfo);

  int size = finfo->st_size;

  printf("%d\n", size);

  if(size / 1000000.0 > 1000) {
    printf("Size: %fGB\n", size/1000000000.0);
  } else if(size / 1000000.0 > 1) {
    printf("Size: %fMB\n", size/1000000.0);
  } else {
    printf("Size: %dB\n", size);
  }
}
