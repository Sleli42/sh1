/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 23:23:55 by lubaujar          #+#    #+#             */
/*   Updated: 2015/06/02 23:38:49 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		search_path_bin(char *cmd, char *s)
{
	printf("cmd: %s\n", cmd);
	printf("%s\n", s);
	return (1);
}

int		exec_syscall(t_all *all, char *cmd)
{
	if (search_path_bin(cmd, all->dup_env[0]) == 1)
		return (1);
	return (0);
}
