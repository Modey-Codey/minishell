#include "minishell.h"

int main()
{
	char	*input;
	t_token	*tokens;
	t_cmd	*cmds;
	t_shell	shell;

	shell.last_exit_status = 0;
	shell.envp = NULL;
	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
		{
			printf("exit\n");
			break ;
		}
		if (*input)
			add_history(input);
		tokens = tokenize(input);
		cmds = parse(tokens, &shell);
		if (cmds && cmds->argv && cmds->argv[0] && ft_strcmp(cmds->argv[0], "exit") == 0)
			builtin_exit(cmds->argv, &shell);
		free(input);
		free_tokens(tokens);
		free_cmds(cmds);
	}
    return (0);
}
