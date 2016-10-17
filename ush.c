#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

char cmd[1024];

int main()
{
  fscanf(stdin, "%s", &cmd);
  
  int pid = fork();

  if ( pid > 0 )
  {
    wait(0);
  } else if ( pid == 0 )
  {
    char *const argv[] = {""};
    execv("/bin/sh", argv);
  } else
  {
    puts("Fork error!");
    exit(1);
  }

  return 0;
}
