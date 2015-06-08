/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 18:22:25 by lubaujar          #+#    #+#             */
/*   Updated: 2015/06/08 20:29:15 by lubaujar         ###   ########.fr       */
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
		new->SHLVL = 1;
		if (new->var == NULL)
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

void	lst_del_elem(t_env **alst, char *varname)
{
	t_env	*next;
	t_env 	*tmp;
	int		i;

	tmp = *alst;
	next = NULL;
	i = ft_strlen(varname);
	if (ft_strcmp(varname, "_") == 0)
		return ;
	while (tmp)
	{
		if (ft_strcmp(varname, tmp->varname) == 0)
		{
			next = tmp->next;
			if (next != NULL)
			{
				if (tmp->prev)
					(tmp->prev)->next = next;
				else
					*alst = next;
			}
			else
				(tmp->prev)->next = NULL;
			ft_strdel(&tmp->var);
			ft_strdel(&tmp->varname);
			free(tmp);
			return ;
		}
		tmp = tmp->next;
	}
}

int		list_len(t_env *lst)
{
	int		ret;
	t_env	*tmp;

	ret = 0;
	tmp = lst;
	if (tmp)
	{
		while (tmp)
		{
			ret++;
			tmp = tmp->next;
		}
	}
	return (ret);
}
