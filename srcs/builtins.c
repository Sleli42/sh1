/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 15:48:08 by lubaujar          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/06/08 19:57:24 by lubaujar         ###   ########.fr       */
=======
/*   Updated: 2015/06/05 18:52:39 by lubaujar         ###   ########.fr       */
>>>>>>> 2484e274e8c26849b7b1305f04115bea51ba0553
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void		builtins_cmd(t_all *all, char *cmd)
{
	if ((ft_strcmp(cmd, "exit")) == 0)
		ft_putstr("exit\n"), exit (1);
	if ((ft_strcmp(cmd, "pwd")) == 0)
	{
		get_and_display_pwd();
		return (1);
	}
	if (ft_strncmp(cmd, "cd", 2) == 0)
	{
	 	goto_directory(cmd);
	 	return (1);
	}
	if (ft_strcmp(cmd, "env") == 0)
	{
		display_env(all->data);
		return (1);
	}
	if (ft_strncmp(cmd, "setenv", 6) == 0)
	{
		set_env(&all->data, cut_cmd(cmd));
		return (1);
	}
	if (ft_strncmp(cmd, "unsetenv", 8) == 0)
	{
		unset_env(&all->data, var_name(cmd));
<<<<<<< HEAD
=======
		return (1);
	}
	return (0);
>>>>>>> 2484e274e8c26849b7b1305f04115bea51ba0553
}
