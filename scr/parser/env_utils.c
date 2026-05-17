#include "minishell.h"

static int	is_env_char(char c)
{
	return (is_alnum(c) || c == '_');
}

char	*get_env_value(char *str, t_shell *shell, int *i)
{
	char	*name;
	char	*value;
	int		len;

	(*i)++;
	len = 0;
	while (str[*i + len] && is_env_char(str[*i + len]))
		len++;
	name = ft_substr(str, *i, len);
	value = get_env_val(shell->envp, name);
	free(name);
	*i += len;
	if (!value)
		return (ft_strdup(""));
	return (ft_strdup(value));
}

int	init_env(t_shell *shell, char **sys_envp)
{
	int	i;

	i = 0;
	while (sys_envp[i])
		i++;
	shell->envp = malloc(sizeof(char *) *(i + 1));
	if (!shell->envp)
		return (1);
	i = 0;
	while (sys_envp[i])
	{
		shell->envp[i] = ft_strdup(sys_envp[i]);
		if (!shell->envp[i])
			return (1);
		i++;
	}
	shell->envp[i] = NULL;
	return (0);
}
