#include "main.h"

void col_commands(char *cli)
{
	char *cmd;
	char *tok = strtok(cli, ";");

	while (tok != NULL)
	{
		cmd = strtok(tok, " \t\n");

		if (cmd != NULL)
		{
			exec_cmd(cmd);
		}
		tok = strtok(NULL, ";");
	}
}

/**
 * main - entry point
 */

