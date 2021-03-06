/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 15:48:08 by lubaujar          #+#    #+#             */
/*   Updated: 2015/06/09 23:03:57 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void		builtins_cmd(t_all *all, char *cmd)
{
	if ((ft_strcmp(cmd, "exit")) == 0)
		ft_putstr("exit\n"), exit(21);
	if ((ft_strcmp(cmd, "pwd")) == 0)
		get_and_display_pwd();
	if (ft_strncmp(cmd, "cd", 2) == 0)
		goto_directory(cmd);
	if (ft_strcmp(cmd, "env") == 0)
		display_env(all->data);
	if (ft_strncmp(cmd, "setenv", 6) == 0)
		set_env(&all->data, cut_cmd(cmd));
	if (ft_strncmp(cmd, "unsetenv", 8) == 0)
		unset_env(&all->data, var_name(cmd));
}
