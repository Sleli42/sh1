/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:54:40 by lubaujar          #+#    #+#             */
/*   Updated: 2015/06/05 16:58:55 by lubaujar         ###   ########.fr       */
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
