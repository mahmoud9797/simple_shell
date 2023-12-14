#include "unix.h"
int main(int argc, char *argv[])
{
    char *input;
    char **args;
    int status;

    if (argc > 1) {
        args = &argv[1];
        status = execute_command(args[0], args);
        if (status == -1) {
            perror("Error executing command");
            return 1;
        }
        return 0;
    }

    while (1) {
        dis_prompt();
        input = takeinput();
        args = split_cmd(input);

        if (args[0] != NULL) {
            status = execute_command(args[0], args);
            if (status == -1) {
                perror("Error executing command");
            }
        }

        free(input);

        if (args != NULL) {
            int i = 0;
            while (args[i] != NULL) {
                free(args[i]);
                i++;
            }
            free(args);
        }
    }

    return 0;
}
