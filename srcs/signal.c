/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 21:47:47 by lubaujar          #+#    #+#             */
/*   Updated: 2015/06/08 21:49:02 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	ft_func(int sig)
{
	(void)sig;
}

void	ft_catch_sig(void)
{
	int sig;

	sig = 1;
	while (sig <= 31)
	{
		signal(sig++, ft_func);
	}
}
