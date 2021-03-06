/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 18:47:11 by lubaujar          #+#    #+#             */
/*   Updated: 2015/06/09 17:56:15 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	display_env(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	if (tmp)
	{
		while (tmp)
		{
			ft_putstr(tmp->var);
			write(1, "\n", 1);
			tmp = tmp->next;
		}
	}
	else
		return ;
}

void	get_and_display_pwd(void)
{
	char	*pwd;
	char	*buff;

	buff = NULL;
	pwd = getcwd(buff, 42);
	ft_putstr(pwd);
	write(1, "\n", 1);
}
