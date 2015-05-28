/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 16:19:31 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/26 21:00:30 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh1.h>
#include <stdio.h>

int		main(int ac, char **av, char **env)
{
	char 	*buff;
	t_env	*dup;

	(void)ac;
	(void)av;
	(void)env;
	buff = NULL;
	dup = NULL;
	get_env(&dup, env);
	while (21)
	{
		ft_putstr("PROMPT $> ");
		while (get_next_line(0, &buff) >= 0)
		{
			ft_putstr("PROMPT $> ");
			if (get_cmd(dup, buff) == 1)
				break ;
		}
	}
	return (0);
}
