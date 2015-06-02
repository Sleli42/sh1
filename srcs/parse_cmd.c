/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 17:30:01 by lubaujar          #+#    #+#             */
/*   Updated: 2015/06/02 18:26:05 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

// int		get_cmd(t_env *env, char *cmd)
// {
// 	if ((ft_strcmp(cmd, "exit")) == 0)
// 		exit (1);
// 	if ((ft_strcmp(cmd, "pwd")) == 0)
// 	{
// 		get_and_display_pwd();
// 		return (1);
// 	}
// 	if (ft_strncmp(cmd, "cd", 2) == 0)
// 	{
// 	 	goto_directory(cmd);
// 	 	return (21);
// 	}
// 	if (ft_strncmp(cmd, "setenv", 6) == 0)
// 		change_setenv(&env, cut_cmd(cmd), var_name(cmd));
// 	if (ft_strncmp(cmd, "unsetenv", 8) == 0)
// 	 	change_unsetenv(&env, var_name(cmd));
// 	if (ft_strcmp(cmd, "env") == 0)
// 	{
// 		write (1, "\n", 1), display_env(env);
// 		return (1);
// 	}
// 	return (0);
// }


// void	test_execve(char *cmd, char **env)
// {
// 	char **split;
// 	int	i;
// 	i = 0;

// (void)env;
// 	split = ft_strsplit(cmd, ' ');
// 	while (split[i])
// 	{
// 		printf("%s\n", split[i]);
// 		i++;
// 	}
// 	//execve("/bin/ls", split, env);
// }
