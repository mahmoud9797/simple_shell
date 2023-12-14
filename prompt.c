#include "unix.h"
/**
 * dis_prompt - function to print $
 *
 */
void dis_prompt(void)
{
	char *prompt = "our_shell$";

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
	}
}
