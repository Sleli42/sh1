/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 23:23:55 by lubaujar          #+#    #+#             */
/*   Updated: 2015/06/08 21:55:54 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		exec_syscall(t_all *all, char *cmd, char *s)
{
	char	**array;
	char	**cmd_parse;
	char	*tmp;
	int		i;

	if (!s)
	{
		if (no_builtins(cmd) == 1)
			printf("sh: %s: No such file or directory\n", cmd);
		return (-1);
	}
	array = ft_strsplit(s, ':');
	cmd_parse = ft_strsplit(cmd, ' ');
	tmp = NULL;
	i = 0;
	while (array[i] != NULL)
	{
		tmp = create_path(array[i], cmd_parse[0]);
		if (good_access(tmp))
			if (tmp && no_builtins(cmd_parse[0]) == 1)
			{
				exec_bin(all, tmp, cmd_parse);
				return (1);
			}
		ft_strdel(&tmp);
		i++;
	}
	del_array(&array);
	del_array(&cmd_parse);
	return (0);
}

void	exec_bin(t_all *all, char *syscall, char **cmd_array)
{
	pid_t	pid;
	int		buff;

	pid = fork();
	ft_catch_sig();
	if (pid == -1)
		ft_putstr("no child process\n");
	if (pid == 0)
	{
		if (execve(syscall, cmd_array, all->dup_env) == -1)
			return ;
	}
	else if (pid > 0)
		waitpid(pid, &buff, 0);
}
