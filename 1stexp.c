#include<stdio.h>
#include<unistd.h>
int main(){
  int pid = fork();
  if(pid<0){
    printf("Error");
    return -1;
  }
  else if(pid==0){
    printf("This block is executed by the child process\n");
  }
  else if(pid>1){
    printf("this block is executed by the parent process\n");
  }
  printf("%d\n", pid);
  int ppid = fork();
  if(ppid<0){
    printf("Error");
    return -1;
  }
  else if(ppid==0){
    printf("This block is executed by the child process of ppid\n");
  }
  else if(ppid>1){
    printf("this block is executed by the parent process of ppid\n");
  }
  printf("%d\n", ppid);
  return 0;
  
}






















