/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 18:22:25 by lubaujar          #+#    #+#             */
/*   Updated: 2015/06/10 14:58:50 by lubaujar         ###   ########.fr       */
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
		new->var = NULL;
	else
	{
		new->var = ft_strdup(s);
		new->varname = dup_var_name(s);
		new->shlvl = 1;
		if (new->var == NULL)
			return (NULL);
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		lst_add_elem_back(t_env **alst, t_env *new_elem)
{
	t_env	*curr;

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

void		lst_del_elem(t_env **alst, char *varname)
{
	t_env	*next;
	t_env	*tmp;

	tmp = *alst;
	next = NULL;
	while (tmp)
	{
		if (ft_strcmp(varname, tmp->varname) == 0)
		{
			swap_ptr(alst, tmp);
			ft_strdel(&tmp->var);
			ft_strdel(&tmp->varname);
			free(tmp);
			return ;
		}
		tmp = tmp->next;
	}
}

void		del_lst(t_env *alst)
{
	t_env	*next_list;
	t_env	*tmp;

	tmp = alst;
	next_list = NULL;
	if (tmp)
	{
		while (tmp)
		{
			next_list = tmp->next;
			if (tmp->var)
				free(tmp->var);
			if (tmp->varname)
				free(tmp->varname);
			if (tmp)
				free(tmp);
			tmp = next_list;
		}
	}
}
