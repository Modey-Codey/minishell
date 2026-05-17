#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	int		status;

	(void)argc;
	if (init_env(&shell, envp))
	{
		write(2, "init_env failed\n", 16);
		return (1);
	}
	status = builtin_cd(argv, &shell);
	printf("PWD=%s\n", get_env_val(shell.envp, "PWD"));
	printf("OLDPWD=%s\n", get_env_val(shell.envp, "OLDPWD"));
	free_envp(shell.envp);
	return (status);
}
