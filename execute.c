#include "unix.h"

int execute_command(char *path, char **args)
{
  pid_t pid;
  int status;

  pid = fork();
  if (pid == -1)
  {
      perror("Fork failed");
      return -1;
  }
  else if (pid == 0)
  {
      if (execve(path, args, environ) == -1)
      {
          perror("Execve failed");
          return -1;
      }
  }
  else
  {
      do
      {
          waitpid(pid, &status, WUNTRACED);
      } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 0;
}
