/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 23:23:55 by lubaujar          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/06/08 21:55:54 by lubaujar         ###   ########.fr       */
=======
/*   Updated: 2015/06/05 18:48:13 by lubaujar         ###   ########.fr       */
>>>>>>> 2484e274e8c26849b7b1305f04115bea51ba0553
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

<<<<<<< HEAD
int		exec_syscall(t_all *all, char *cmd, char *s)
=======
int		search_path_bin(t_all *all, char *cmd, char *s)
>>>>>>> 2484e274e8c26849b7b1305f04115bea51ba0553
{
	char	**array;
	char	**cmd_parse;
	char	*tmp;
	int		i;

<<<<<<< HEAD
	if (!s)
	{
		if (no_builtins(cmd) == 1)
			printf("sh: %s: No such file or directory\n", cmd);
		return (-1);
	}
=======
>>>>>>> 2484e274e8c26849b7b1305f04115bea51ba0553
	array = ft_strsplit(s, ':');
	cmd_parse = ft_strsplit(cmd, ' ');
	tmp = NULL;
	i = 0;
	while (array[i] != NULL)
	{
		tmp = create_path(array[i], cmd_parse[0]);
		if (good_access(tmp))
<<<<<<< HEAD
			if (tmp && no_builtins(cmd_parse[0]) == 1)
=======
			if (tmp && ft_strcmp(cmd_parse[0], "env") != 0)
>>>>>>> 2484e274e8c26849b7b1305f04115bea51ba0553
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
<<<<<<< HEAD
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
=======
	if (search_path_bin(all, cmd, all->dup_env[0] + 6) == 1)
		return (1);
	else
	{
		ft_putstr("sh: ");
		ft_putstr(cmd);
		ft_putstr(": command not found\n");
		return (1);
	}
	return (0);
>>>>>>> 2484e274e8c26849b7b1305f04115bea51ba0553
}

void	exec_bin(t_all *all, char *syscall, char **cmd_array)
{
	pid_t	pid;
	int		buff;

	pid = fork();
	if (pid == -1)
		ft_putstr("no child process\n");
	if (pid == 0)
	{
		if (execve(syscall, cmd_array, all->dup_env) == -1)
			ft_putstr("error execve\n");
	}
	else if (pid > 0)
		waitpid(pid, &buff, 0);
}
