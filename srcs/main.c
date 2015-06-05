/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 16:19:31 by lubaujar          #+#    #+#             */
/*   Updated: 2015/06/05 18:44:20 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh1.h>

int		main(int ac, char **av, char **env)
{
	t_all	*all;
	char	*buff;

	all = (t_all *)malloc(sizeof(t_all));
	all->dup_env = ft_dupenv(env);
	all->data = NULL;
	buff = NULL;
	get_env(&all->data, env);
	(void)ac;
	(void)av;
	while (1091111096051)
	{
		ft_putstr("ZGUEGG[8=====D] $> ");
		while (get_next_line(0, &buff) >= 0)
		{
			if (builtins_cmd(all, buff) == 1
				|| exec_syscall(all, buff) == 1)
				break ;
		}
		ft_strdel(&buff);
	}
	return (0);
}
