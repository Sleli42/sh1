/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 16:19:31 by lubaujar          #+#    #+#             */
/*   Updated: 2015/06/08 23:20:46 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh1.h>

static int	skip_spaces(char *s)
{
	int		i;

	i = 0;
	while ((s[i] && s[i] == ' ')
		|| (s[i] && s[i] == '\t'))
		i++;
	return (i);
}

// void	put_prompt(void)
// {
// 	ft_putstr("\e[35mPROMPT 8===D\033[0m");
// }

int		main(int ac, char **av, char **env)
{
	t_all	*all;
	char	*buff;

	all = (t_all *)malloc(sizeof(t_all));
	all->data = NULL;
	if (!env || !*env)
	{
		all->dup_env = NULL;
		create_min_env(&all->data);
	}
	else
	{
		all->dup_env = ft_dupenv(env);
		get_env(&all->data, env);
	}
	buff = NULL;
	(void)ac;
	(void)av;
	while (1091111096051)
	{
		ft_putstr("\e[35m[PROMPT\e[37mDE\033[0m\e[35mOUF]\033[0m $> ");
		while (get_next_line(0, &buff) > 0)
		{
			if (*buff == ' ' || *buff == '\t')
				buff = buff + skip_spaces(buff);
			builtins_cmd(all, buff);
			if (exec_syscall(all, buff,
				(ft_strncmp(all->data->var, "PATH", 4) == 0)
				? all->data->var + 6 : NULL) == 0
				&& no_builtins(buff) == 1)
				printf("sh: %s: command not found\n", buff);
			break ;
		}
	}
	ft_strdel(&buff);
	return (0);
}
