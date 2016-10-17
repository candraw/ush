#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

void parse_and_execute();

int main()
{
  int pid = fork();

  if ( pid > 0 )
  {
    wait(0);
    puts("parent exit");
  } else if ( pid == 0 )
  {
    const char **cmd;

    parse_and_execute();
  } else
  {
    puts("Fork error!");
    exit(1);
  }

  return 0;
}

void parse_and_execute()
{
  char *const argv[] = {""};

  execv("/bin/sh", argv);
}
