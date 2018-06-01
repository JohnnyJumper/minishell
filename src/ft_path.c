/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:44:49 by jtahirov          #+#    #+#             */
/*   Updated: 2018/06/01 10:52:04 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int 	ft_execute(char *path, char **args, char **env)
{
	pid_t 	child;

	if ((child = fork()) == -1)
	{
		ft_printf("Failed forking child..\n");
		return 1;
	}
	else if (child == 0) 
	{
		if (execve(path, args, env) < 0)
		{
			ft_printf("can't execute\n");
			return (0);
		}
	}
	else
	{
		wait(NULL);
		return (1);
	}
	return (0);
}

static 	char *ft_assembly_path(char *begin, char *comand)
{
	char 	*tmp;
	char 	*result;

	result = ft_strdup(begin);
	tmp = result;
	result = ft_strjoin(result, "/");
	ft_strdel(&tmp);
	tmp = result;
	result = ft_strjoin(result, comand);
	ft_strdel(&tmp);
	return (result);
}

int 	ft_check_in_path(t_all *all)
{
	char 		**words;
	char 		*full_path;
	int 		counter;

	if (!all->env.path)
		return (0);
	words = ft_strsplit(all->env.path, ':');
	counter = 0;
	while (words[counter])
	{
		full_path = ft_assembly_path(words[counter], all->words[0]);
		if (!access(full_path, F_OK) && \
			ft_execute(full_path, all->words, all->env.env))
				return (1);
		counter++;
	}
	return (0);
}
