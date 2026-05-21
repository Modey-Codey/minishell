#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_shell shell;
	int		i;
	int		status;

	(void)argc;
	shell.envp = copy_env(envp);
	printf("Befor unset:\n");
	i = 0;
	while (shell.envp[i])
	{
		printf("%s\n", shell.envp[i]);
		i++;
	}
	status = builtin_unset(argv, &shell);
	printf("\nAfter unset:\n");
	i = 0;
	while (shell.envp[i])
	{
		printf("%s\n", shell.envp[i]);
		i++;
	}
	printf("\nExit Status: %d\n", status);
	free_envp(shell.envp);
    return (0);
}
