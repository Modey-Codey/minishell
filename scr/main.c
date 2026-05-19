#include "minishell.h"

static char **copy_env_main(char **envp)
{
    int     i;
    char    **env;

    i = 0;
    while (envp[i])
        i++;
    env = malloc(sizeof(char *) * (i + 1));
    if (!env)
        return (NULL);
    i = 0;
    while (envp[i])
    {
        env[i] = ft_strdup(envp[i]);
        i++;
    }
    env[i] = NULL;
    return (env);
}

int main(int argc, char **argv, char **envp)
{
    char    **env;

    (void)argc;
    env = copy_env_main(envp);
    if (!env)
        return (1);
    builtin_export(argv, &env); 
    print_export(env);
    free_arr(env);
    return (0);
}
