/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 18:22:30 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/28 15:03:08 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	get_env(t_env **dupenv, char **env)
{
	int		i;

	i = 0;
	while (env[i])
		list_elem(dupenv, env[i++]);
}

void	change_setenv(t_env **env, char *var, char *varname)
{
	if (check_env(*env, varname) < 0 && good_format(var) == 1)
		lst_add_elem_back(env, lst_create_elem(var));
	else if (good_format(var) == 1)
		change_var(env, var, varname);
}

void	change_unsetenv(t_env **env, char *var, char *varname)
{
	if (check_env(*env, varname) == 1 && good_format(var) == 1)
		lst_del_elem(env, varname, ft_strlen(varname));
}

void	change_var(t_env **env, char *var, char *varname)
{
	t_env 	*tmp;
	int		i;

	tmp = *env;
	i = ft_strlen(varname);
	while (tmp)
	{
		if (ft_strncmp(tmp->line, varname, i) == 0)
			tmp->line = ft_strdup(var);
		tmp = tmp->next;
	}
}

void	test_lst(t_env *lst)
{
	t_env *tmp;

	tmp = lst;
	while (tmp)
	{
		printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
}
