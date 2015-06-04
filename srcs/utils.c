/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:54:40 by lubaujar          #+#    #+#             */
/*   Updated: 2015/06/04 18:33:47 by lubaujar         ###   ########.fr       */
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
