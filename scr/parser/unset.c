#include "minishell.h"

static int	match_env(char *env, char *key)
{
	int	i;

	i = 0;
	while (key[i] && env[i] && key[i] == env[i])
		i++;
	if (key[i] == '\0' && env[i] == '=')
		return (1);
	return (0);
}

static void	remove_env_var(char **envp, int index)
{
	free(envp[index]);
	while (envp[index])
	{
		envp[index] = envp[index + 1];
		index++;
	}
}

static void	unset_one(char *key, t_shell *shell)
{
	int	j;

	j = 0;
	while (shell->envp[j])
	{
		if (match_env(shell->envp[j], key))
		{
			remove_env_var(shell->envp, j);
			break ;
		}
		j++;
	}
}

int	builtin_unset(char **argv, t_shell *shell)
{
	int	i;

	if (!argv[1])
		return (0);
	i = 1;
	while (argv[i])
	{
		if (!is_valid_identifier(argv[i]))
			print_export_error(argv[i]);
		else
			unset_one(argv[i], shell);
		i++;
	}
	return (0);
}
