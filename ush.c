#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

void fork_and_execute();
void exec_cmd(char*, char *const []);

static char cmd[1024];

int main()
{
  fscanf(stdin, "%s", &cmd);
  
  fork_and_execute();

  return 0;
}

void fork_and_execute()
{
  int pid = fork();

  if ( pid > 0 )
  {
    wait(0);
  } else if ( pid == 0 )
  {
    char *const argv[] = {cmd, (char *)0};
    exec_cmd(cmd, argv);
  } else
  {
    puts("Fork error!");
    exit(1);
  }
}

void exec_cmd(char *cmd, char *const argv[])
{
  execv(cmd, argv);
  printf("Could not execute %s\n", cmd);
}
