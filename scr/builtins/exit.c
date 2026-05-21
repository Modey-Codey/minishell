#include "minishell.h"

static int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_overflow(char *str)
{
	unsigned long long	num;
	int					sign;
	int					i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		if (sign == 1 && num > LLONG_MAX)
			return (1);
		if (sign == -1 && num > (unsigned long long)LLONG_MAX + 1)
			return (1);
		i++;
	}
	return (0);
}

static long long	ft_atoll_exit(char *str)
{
	long long	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	builtin_exit(char **argv, t_shell *shell)
{
	long long	exit_code;

	printf("exit\n");
	if (!argv[1])
		exit(shell->last_exit_status);
	if (!is_numeric(argv[1]) || check_overflow(argv[1]))
	{
		printf("minishell: exit: %s: numeric argument required\n", argv[1]);
		shell->last_exit_status = 255;
		exit(255);
	}
	if (argv[2])
	{
		printf("minishell: exit: too many arguments\n");
		shell->last_exit_status = 1;
		return (1);
	}
	exit_code = ft_atoll_exit(argv[1]);
	shell->last_exit_status = (unsigned char)exit_code;
	exit((unsigned char)exit_code);
}
