/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 18:22:30 by lubaujar          #+#    #+#             */
/*   Updated: 2015/06/08 19:56:46 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**ft_dupenv(char **env)
{
	char	**dup;
	int		i;

	i = -1;
	dup = (char **)malloc(sizeof(char *) * ft_tablen(env) + 1);
	while (++i < (int)ft_tablen(env))
		dup[i] = ft_strdup(env[i]);
	dup[++i] = NULL;
	return (dup);
}

void	get_env(t_env **dupenv, char **env)
{
	int		i;

	i = 0;
	while (env[i])
		list_elem(dupenv, env[i++]);
}

void	set_env(t_env **env, char *var)
{
	if (check_env(*env, dup_var_name(var)) < 0 && good_format(var) == 1)
		lst_add_elem_back(env, lst_create_elem(var));
	else if (check_env(*env, dup_var_name(var)) == 1 && good_format(var) == 1)
		update_env(env, var, dup_var_name(var));
	ft_strdel(&var);
}

void	unset_env(t_env **env, char *varname)
{
	if (check_env(*env, varname) == 1)
		lst_del_elem(env, varname);
	ft_strdel(&varname);
}

void	update_env(t_env **env, char *var, char *name)
{
	t_env 	*tmp;
	int		i;

	tmp = *env;
	i = ft_strlen(name);
	while (tmp)
	{
		if (ft_strncmp(tmp->varname, name, i) == 0)
			tmp->var = ft_strdup(var);
		tmp = tmp->next;
	}
	ft_strdel(&name);
}
