/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 16:19:31 by lubaujar          #+#    #+#             */
/*   Updated: 2015/06/10 14:58:42 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh1.h>

void	swap_ptr(t_env **alst, t_env *tmp)
{
	t_env	*next;

	next = tmp->next;
	if (next != NULL)
	{
		if (tmp->prev)
			(tmp->prev)->next = next;
		else
		{
			*alst = next;
			(*alst)->prev = NULL;
		}
	}
	else
		(tmp->prev)->next = NULL;
}

static int	skip_spaces(char *s)
{
	int		i;

	i = 0;
	while ((s[i] && s[i] == ' ')
		|| (s[i] && s[i] == '\t'))
		i++;
	return (i);
}

static char	*path_or_not_path(t_all *all, char *buff)
{
	if (ft_strncmp(all->data->var, "PATH", 4) == 0)
	{
		if (buff[0] == '/')
			return (all->dup_env[0]);
		return (all->data->var + 6);
	}
	else
	{
		if (buff[0] == '/' && buff[ft_strlen(buff) - 1] != '/')
			return (all->dup_env[0]);
	}
	return (NULL);
}

int			main(int ac, char **av, char **env)
{
	t_all	*all;
	char	*buff;

	all = init_all(env);
	buff = NULL;
	(void)ac;
	(void)av;
	while (1091111096051)
	{
		ft_putstr("\033[35m[PROMPT\033[37mDE\033[0m\033[35mOUF]\033[0m $> ");
		while (get_next_line(0, &buff) > 0)
		{
			if (*buff == ' ' || *buff == '\t')
				buff = ft_strdup(buff + skip_spaces(buff));
			builtins_cmd(all, buff);
			if (exec_syscall(all, buff, path_or_not_path(all, buff)) == 0
				&& no_builtins(buff) == 1 && buff[0])
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
