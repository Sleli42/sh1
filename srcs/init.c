/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 16:00:27 by lubaujar          #+#    #+#             */
/*   Updated: 2015/06/10 14:50:29 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static char	**ft_dup_min_env(t_env *lst)
{
	char	**array;
	int		i;
	t_env	*tmp;

	array = NULL;
	tmp = lst;
	i = 0;
	if (tmp)
	{
		array = (char **)malloc(sizeof(char *) * 4 + 1);
		while (tmp)
		{
			array[i] = ft_strdup(tmp->var);
			i++;
			tmp = tmp->next;
		}
		array[i] = NULL;
	}
	return (array);
}

t_all		*init_all(char **env)
{
	t_all	*all;

	all = (t_all *)malloc(sizeof(t_all));
	all->data = NULL;
	if (!env || !*env)
	{
		create_min_env(&all->data);
		all->dup_env = ft_dup_min_env(all->data);
	}
	else
	{
		all->dup_env = ft_dupenv(env);
		get_env(&all->data, env);
	}
	return (all);
}
