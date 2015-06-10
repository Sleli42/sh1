/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 16:23:20 by lubaujar          #+#    #+#             */
/*   Updated: 2015/06/10 16:01:05 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH1_H
# define SH1_H

# include "libft.h"
# include <dirent.h>
# include <signal.h>
# include <sys/types.h>
# include "colors.h"

typedef struct		s_env
{
	char			*var;
	char			*varname;
	int				shlvl;
	struct s_env	*next;
	struct s_env	*prev;
}					t_env;

typedef struct		s_all
{
	char			**dup_env;
	t_env			*data;
}					t_all;

void				swap_ptr(t_env **alst, t_env *ptr);

/*
***	exec.c
*/
int					exec_syscall(t_all *all, char *cmd, char *s);
void				exec_bin(t_all *all, char *syscall, char **cmd_array);
/*
***	builtins_cmd.c
*/
void				builtins_cmd(t_all *all, char *cmd);
/*
***	env.c
*/
char				**ft_dupenv(char **env);
void				get_env(t_env **dupenv, char **env);
void				set_env(t_env **env, char *var);
void				unset_env(t_env **env, char *varname);
void				update_env(t_env **env, char *var, char *varname);
/*
***	lst.c
*/
void				list_elem(t_env **list, char *line);
t_env				*lst_create_elem(char *line);
void				lst_add_elem_back(t_env **alst, t_env *new_elem);
void				lst_del_elem(t_env **alst, char *varname);
void				del_lst(t_env *alst);
/*
***	display.c
*/
void				get_and_display_pwd(void);
void				display_env(t_env *env);
/*
***	misc.c
*/
void				goto_directory(char *cmd);
int					check_env(t_env *env, char *name);
char				*dup_var_name(char *cmd);
char				*var_name(char *cmd);
int					good_format(char *s);
/*
***	utils.c
*/
char				*cut_cmd(char *cmd);
char				*create_path(char *path, char *cmd);
int					good_access(char *bin);
int					no_builtins(char *cmd);
void				create_min_env(t_env **dupenv);
/*
***	signal.c
*/
void				ft_catch_sig(void);
void				ft_func(int sig);
/*
***	init.c
*/
char				*replace_syscall_path(char *s);
t_all				*init_all(char **env);
/*
***	error.c
*/
void				put_error(int err, char *s);

#endif
