#include <stdio.h>
#include <unistd.h>
int main(){
  int a = fork();
  printf("%d", a);
  return 0;
}