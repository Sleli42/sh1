/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 18:22:25 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/28 15:04:09 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh1.h>

void		list_elem(t_env **list, char *line)
{
	if (!(*list))
		*list = lst_create_elem(line);
	else
		lst_add_elem_back(list, lst_create_elem(line));
}

t_env		*lst_create_elem(char *s)
{
	t_env		*new;

	if (!(new = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	if (s == NULL)
		new->line = NULL;
	else
	{
		new->line = ft_strdup(s);
		if (new->line == NULL)
			return (NULL);
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		lst_add_elem_back(t_env **alst, t_env *new_elem)
{
	t_env 	*curr;

	curr = *alst;
	if (new_elem != NULL)
	{
		if (*alst == NULL)
			*alst = new_elem;
		else
		{
			while (curr->next != NULL)
				curr = curr->next;
			curr->next = new_elem;
			new_elem->prev = curr;
			new_elem->next = NULL;
		}
	}
	else
		return ;
}

void	lst_del_elem(t_env **alst, char *varname, size_t varnamelen)
{
	t_env	*tmp;

	tmp = *alst;
	while (tmp)
	{
		if (ft_strncmp(varname, var_name(tmp->line), varnamelen) == 0)
		{
			printf("var to unsetenv\n");
			printf("%s\n &&\n%s\n", varname, var_name(tmp->line));
		}
		tmp = tmp->next;
	}
}
