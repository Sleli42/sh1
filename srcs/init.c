/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 16:00:27 by lubaujar          #+#    #+#             */
/*   Updated: 2015/06/09 22:46:59 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

t_all	*init_all(char **env)
{
	t_all	*all;

	all = (t_all *)malloc(sizeof(t_all));
	all->data = NULL;
	if (!env || !*env)
	{
		all->dup_env = NULL;
		create_min_env(&all->data);
	}
	else
	{
		all->dup_env = ft_dupenv(env);
		get_env(&all->data, env);
	}
	return (all);
}
