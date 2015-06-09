/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:54:40 by lubaujar          #+#    #+#             */
/*   Updated: 2015/06/09 17:55:42 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	*cut_cmd(char *cmd)
{
	int		i;
	int		j;
	char	*var;

	i = 0;
	j = 0;
	var = (char *)malloc(sizeof(char) * ft_strlen(cmd) - 6);
	while (cmd[i] && cmd[i] != ' ')
		i++;
	i = i + 1;
	while (cmd[i])
		var[j++] = cmd[i++];
	var[j] = '\0';
	return (var);
}

char	*create_path(char *path, char *cmd)
{
	char	*tmp;
	char	*real_path;

	tmp = NULL;
	if (path)
		tmp = ft_strjoin(path, "/");
	real_path = ft_strjoin(tmp, cmd);
	if (tmp)
		ft_strdel(&tmp);
	return (real_path);
}

int		good_access(char *bin)
{
	if (access(bin, F_OK) == 0)
		if (access(bin, X_OK) == 0)
			return (1);
	return (0);
}

int		no_builtins(char *cmd)
{
	if (ft_strcmp(cmd, "env") != 0
		&& ft_strncmp(cmd, "cd", 2) != 0
		&& ft_strcmp(cmd, "pwd") != 0
		&& ft_strncmp(cmd, "setenv", 6) != 0
		&& ft_strncmp(cmd, "unsetenv", 8) != 0
		&& ft_strcmp(cmd, "exit") != 0)
		return (1);
	return (0);
}

void	create_min_env(t_env **dupenv)
{
	char	*data;
	char	*tmp;

	data = NULL;
	tmp = NULL;
	tmp = ft_strdup("PATH=~/.brew/bin/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin:/usr/texbin:/nfs/zfs-student-5/users/2014/lubaujar/.brew/bin");
	list_elem(dupenv, tmp);
	ft_strdel(&tmp);
	data = getcwd(tmp, 42);
	tmp = ft_strjoin("PWD=", data);
	list_elem(dupenv, tmp);
	ft_strdel(&tmp);
	data = ft_strjoin("SHLVL=", ft_itoa((*dupenv)->SHLVL));
	list_elem(dupenv, data);
	ft_strdel(&data);
	data = ft_strdup("_=/usr/bin/env");
	list_elem(dupenv, data);
	ft_strdel(&data);
}
