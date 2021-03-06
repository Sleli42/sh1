/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 18:25:45 by lubaujar          #+#    #+#             */
/*   Updated: 2015/06/10 14:58:43 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		good_format(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '=' && s[i + 1] != '\0')
			return (1);
		i++;
	}
	return (-1);
}

int		check_env(t_env *env, char *name)
{
	t_env	*tmp;
	int		i;

	tmp = env;
	i = ft_strlen(name);
	while (tmp)
	{
		if (ft_strncmp(tmp->varname, name, i) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (-1);
}

void	goto_directory(char *cmd)
{
	char	*tmp;
	int		i;
	int		j;

	i = 3;
	j = 0;
	tmp = (char *)malloc(sizeof(char) * ft_strlen(cmd) - 2);
	while (cmd[i])
		tmp[j++] = cmd[i++];
	tmp[j] = '\0';
	if (tmp[0] == '\0')
	{
		ft_strdel(&tmp);
		tmp = ft_strdup("/Volumes/Data/nfs/zfs-student-5/users/2014/lubaujar/");
	}
	if (access(tmp, F_OK) == 0)
	{
		if (chdir(tmp) == -1)
			put_error(4, cmd + 3);
	}
	ft_strdel(&tmp);
}

char	*var_name(char *cmd)
{
	int		i;
	int		j;
	char	*varname;

	i = 0;
	j = 0;
	varname = ft_strnew(21);
	while (cmd[i] && cmd[i] != ' ')
		i++;
	i = i + 1;
	while (cmd[i] && cmd[i] != '=')
		varname[j++] = cmd[i++];
	varname[j] = '\0';
	return (varname);
}

char	*dup_var_name(char *cmd)
{
	int		i;
	int		j;
	char	*varname;

	i = 0;
	j = 0;
	varname = ft_strnew(21);
	while (cmd[i] && cmd[i] != '=')
		varname[j++] = cmd[i++];
	varname[j] = '\0';
	return (varname);
}
