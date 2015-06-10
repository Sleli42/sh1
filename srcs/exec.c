/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 23:23:55 by lubaujar          #+#    #+#             */
/*   Updated: 2015/06/10 16:03:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static int	error_1(char *cmd)
{
	if (no_builtins(cmd) == 1)
		put_error(3, cmd);
	return (-1);
}

static int	exec_syscall_extended(t_all *all, char **cmd_parse, char **array)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	while (array[i] != NULL)
	{
		tmp = create_path(array[i], cmd_parse[0]);
		if (good_access(tmp))
			if (tmp && no_builtins(cmd_parse[0]) == 1 && cmd_parse[0][1])
			{
				exec_bin(all, tmp, cmd_parse);
				del_array(&array);
				del_array(&cmd_parse);
				ft_strdel(&tmp);
				return (1);
			}
		ft_strdel(&tmp);
		i++;
	}
	return (0);
}

static char	*check_command(char *cmd)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	s = (char *)malloc(sizeof(char) * 21);
	while (cmd[i])
	{
		if (ft_isspace(cmd[i]))
			i++;
		if (!ft_isspace(cmd[i]) && ft_isspace(cmd[i - 1]))
			s[j++] = ' ';
		if (!ft_isspace(cmd[i]))
			s[j++] = cmd[i];
		i++;
	}
	s[j] = '\0';
	return (s);
}

int			exec_syscall(t_all *all, char *cmd, char *s)
{
	char	**array;
	char	**cmd_parse;
	char	*tmp;

	tmp = check_command(cmd);
	if (!s && cmd[0])
		return (error_1(cmd));
	array = ft_strsplit(s, ':');
	cmd_parse = ft_strsplit(tmp, ' ');
	ft_strdel(&tmp);
	if (cmd_parse[0][0] == '/' || ft_strcmp(cmd_parse[0], "./") == 0)
	{
		if (cmd_parse[0][ft_strlen(cmd_parse[0]) - 1] == '/')
		{
			put_error(1, cmd_parse[0]);
			return (-1);
		}
		else
			cmd_parse[0] = ft_strdup(cmd_parse[0] + 5);
	}
	if (exec_syscall_extended(all, cmd_parse, array) == 1)
		return (1);
	del_array(&array);
	del_array(&cmd_parse);
	return (0);
}

void		exec_bin(t_all *all, char *syscall, char **cmd_array)
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
