#include "unix.h"
int main(void)
{
  char *command, **arguments;
  char *path;

  while (1)
  {
      dis_prompt();
      command = takeinput();
      arguments = split_cmd(command);

      if (arguments[0] != NULL)
      {
          path = get_path(arguments[0]);
          if (path != NULL)
          {
              execute_command(path, arguments);
              free(path);
          }
          else
          {
              printf("Command not found\n");
          }
      }

      free(arguments);
      free(command);
  }

  return 0;
}
