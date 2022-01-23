#include <minishell.h>

t_environ *get_envs_b(t_tokens **tokens)
{
    t_environ   *envs;
    t_tokens    *temp;

    envs = NULL;
    temp = (*tokens);
    while (temp != NULL)
    {
        if (temp->label == STRING && ft_strchr(temp->token, '=') != NULL)
        {
            to_env_list(&envs, temp->token);
            delete_top_token(tokens);
            temp = (*tokens);
            continue ;
        }
        else
        {
            delete_envs(&envs);
            break ;
        }
        temp = temp->next;
    }
    return (envs);
}

void    init_envs_b(t_environ **envs, t_tokens **tokens)
{
    t_environ *temp;

    temp = get_envs_b(tokens);
    while (temp != NULL)
    {
        if (has_key(*envs, temp->key))
            update_env(*envs, temp->key, temp->value);
        else
            push_env(envs, temp->key, temp->value);
        temp = temp->next;
    }
}

t_environ	*get_envs_a(void)
{
	t_environ	*envs;
	size_t		i;

	envs = NULL;
	i = 0;
	while (__environ[i])
		to_env_list(&envs, __environ[i++]);
	return (envs);
}

t_env_vars	*get_environment_variables(void)
{
	t_env_vars	*vars;
	vars = malloc(sizeof(t_env_vars));
	vars->envs_a = get_envs_a();
	vars->envs_b = NULL;
	return vars;
}