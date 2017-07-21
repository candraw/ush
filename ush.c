#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>

#define BUFFER_SIZE 4096

#define PROMPT "> "

void fork_and_execute();
void exec_cmd(char*, char *const []);

static char cmd[BUFFER_SIZE];
char *argbuf[BUFFER_SIZE];

int main()
{
  while ( 1 )
  {
    printf(PROMPT);
    fgets(cmd, BUFFER_SIZE, stdin);

    cmd[strcspn(cmd, "\n")] = 0; // strip newline
  
    fork_and_execute();
  }

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
    int i = 0;
    char *token = strtok(cmd, " ");
    while ( token != NULL )
    {
      argbuf[i++] = token;
      token = strtok(NULL, " ");
    }
    argbuf[i] = (char *)0;

    char *const argv[] =  {};
    exec_cmd(cmd, argbuf);
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
