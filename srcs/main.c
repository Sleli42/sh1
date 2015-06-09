/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 16:19:31 by lubaujar          #+#    #+#             */
/*   Updated: 2015/06/09 22:56:55 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh1.h>

int		skip_spaces(char *s)
{
	int		i;

	i = 0;
	while ((s[i] && s[i] == ' ')
		|| (s[i] && s[i] == '\t'))
		i++;
	return (i);
}

int		main(int ac, char **av, char **env)
{
	t_all	*all;
	char	*buff;

	all = init_all(env);
	buff = NULL;
	(void)ac;
	(void)av;
	while (1091111096051)
	{
		ft_putstr("\e[35m[PROMPT\e[37mDE\033[0m\e[35mOUF]\033[0m $> ");
		while (get_next_line(0, &buff) > 0)
		{
			if (*buff == ' ' || *buff == '\t')
				buff = ft_strdup(buff + skip_spaces(buff));
			builtins_cmd(all, buff);
			if (exec_syscall(all, buff,
				(ft_strncmp(all->data->var, "PATH", 4) == 0)
				? all->data->var + 6 : NULL) == 0
				&& no_builtins(buff) == 1
				&& buff[0])
				put_error(2, buff);
			ft_strdel(&buff);
			break ;
		}
	}
	del_lst(all->data);
	del_array(&all->dup_env);
	free(all);
	return (0);
}
