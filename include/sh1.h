/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 16:23:20 by lubaujar          #+#    #+#             */
/*   Updated: 2015/06/05 18:38:59 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH1_H
# define SH1_H

# include "libft.h"
#include <stdio.h>
# include <dirent.h>

typedef struct		s_env
{
	char			*var;
	char			*varname;
	struct s_env	*next;
	struct s_env	*prev;
}					t_env;

typedef struct		s_all
{
	char			**dup_env;
	t_env			*data;
}					t_all;

// void	test_dup(char **test);
// void	test_lst(t_env *test);
// void	test_lst(t_env *lst);
// void	test_execve(char *cmd, char **env);

/*
***	exec.c
*/
int			exec_syscall(t_all *all, char *cmd);
int			search_path_bin(t_all *all, char *cmd, char *s);
void		exec_bin(t_all *all, char *syscall, char **cmd_array);
/*
***	builtins_cmd.c
*/
int			builtins_cmd(t_all *all, char *cmd);
/*
***	env.c
*/
char		**ft_dupenv(char **env);
void		get_env(t_env **dupenv, char **env);
void		set_env(t_env **env, char *var);
void		unset_env(t_env **env, char *varname);
void		update_env(t_env **env, char *var, char *varname);
/*
***	lst.c
*/
void		list_elem(t_env **list, char *line);
t_env		*lst_create_elem(char *line);
void		lst_add_elem_back(t_env **alst, t_env *new_elem);
void		lst_del_elem(t_env **alst, char *varname);
/*
***	display.c
*/
void		get_and_display_pwd(void);
void		display_env(t_env *env);
/*
***	misc.c
*/
void		goto_directory(char *cmd);
int			check_env(t_env *env, char *name);
char		*dup_var_name(char *cmd);
char		*var_name(char *cmd);
int			good_format(char *s);
/*
***	utils.c
*/
char		*cut_cmd(char *cmd);
char		*create_path(char *path, char *cmd);
int			good_access(char *bin);
#endif
