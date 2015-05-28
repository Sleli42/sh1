/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 17:30:01 by lubaujar          #+#    #+#             */
/*   Updated: 2015/05/28 14:50:51 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		get_cmd(t_env *env, char *cmd)
{
	if ((ft_strcmp(cmd, "exit")) == 0)
		exit (1);
	if ((ft_strcmp(cmd, "pwd")) == 0)
	{
		get_and_display_pwd();
		return (1);
	}
	if (ft_strncmp(cmd, "cd", 2) == 0)
	{
	 	goto_directory(cmd);
	 	return (21);
	}
	if (ft_strncmp(cmd, "setenv", 6) == 0)
		change_setenv(&env, cut_cmd(cmd), var_name(cmd));
	if (ft_strncmp(cmd, "unsetenv", 8) == 0)
	 	change_unsetenv(&env, cut_cmd(cmd), var_name(cmd));
	if (ft_strcmp(cmd, "env") == 0)
	{
		write (1, "\n", 1), display_env(env);
		return (1);
	}
	return (0);
}

void	get_and_display_pwd(void)
{
	char	*pwd;
	char	*buff;

	buff = NULL;
	pwd = getcwd(buff, 42);
	ft_putstr(pwd);
	write(1, "\n", 1);
}

void	goto_directory(char *cmd)
{
	char	*tmp;
	int		i;
	int		j;

	i = 3;
	j = 0;
	tmp = (char *)malloc(sizeof(char) * ft_strlen(cmd) - 2);
	while (cmd[i])
		tmp[j++] = cmd[i++];
	tmp[j] = '\0';
	if (access(tmp, F_OK) == 0)
		if (chdir(tmp) == -1)
			printf("error access dir\n");
	ft_strdel(&tmp);
}
