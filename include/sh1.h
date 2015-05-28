/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 16:23:20 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/28 15:00:54 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH1_H
# define SH1_H

# include "libft.h"
#include <stdio.h>
# include <dirent.h>

typedef struct	s_env
{
	char			*line;
	struct s_env	*next;
	struct s_env	*prev;
}				t_env;

void	test_lst(t_env *lst);

/*
***	parse_cmd.c
*/
int			get_cmd(t_env *env, char *cmd);
void		get_and_display_pwd(void);
void		goto_directory(char *cmd);
/*
***	env.c
*/
void		get_env(t_env **dupenv, char **env);
void		change_setenv(t_env **env, char *var, char *varname);
void		change_unsetenv(t_env **env, char *var, char *varname);
void		change_var(t_env **env, char *var, char *varname);
/*
***	lst.c
*/
void		list_elem(t_env **list, char *line);
t_env		*lst_create_elem(char *line);
void		lst_add_elem_back(t_env **alst, t_env *new_elem);
void		lst_del_elem(t_env **alst, char *var, size_t varlen);
/*
***	display.c
*/
void		display_env(t_env *env);
/*
***	misc.c
*/
int			check_env(t_env *env, char *name);
char		*var_name(char *cmd);
char		*cut_cmd(char *cmd);
int			good_format(char *s);

#endif
