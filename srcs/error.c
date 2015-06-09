/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 22:51:03 by lubaujar          #+#    #+#             */
/*   Updated: 2015/06/09 23:01:09 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	put_error(int err, char *s)
{
	if (err == 1)	/* not directory */
	{
		ft_putstr("sh: ");
		ft_putstr(s);
		ft_putstr(": Not a directory\n");
	}
	if (err == 2)
	{
		ft_putstr("sh: ");
		ft_putstr(s);
		ft_putstr(": command not found\n");
	}
	if (err == 3)
	{
		ft_putstr("sh: ");
		ft_putstr(s);
		ft_putstr(": No such file or directory\n");
	}
	if (err == 4)
	{
		ft_putstr("sh: cd: ");
		ft_putstr(s);
		ft_putstr(": Not a directory\n");
	}
}
