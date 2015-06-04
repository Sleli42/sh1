/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 23:23:55 by lubaujar          #+#    #+#             */
/*   Updated: 2015/06/04 18:34:18 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		search_path_bin(char *cmd, char *s)
{
	char	**array;
	int		i;

	(void)cmd;
	array = ft_strsplit(s, ':'); /* split .. */
	i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
	return (1);
}

int		exec_syscall(t_all *all, char *cmd)
{
	if (search_path_bin(cmd, all->dup_env[0] + 6) == 1)
		return (2);
	return (0);
}
