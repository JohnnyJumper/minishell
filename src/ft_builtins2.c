/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:36:48 by jtahirov          #+#    #+#             */
/*   Updated: 2018/06/01 12:54:35 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_echo(t_all *all)
{
	int 	counter;
	char 	**words;

	words = all->words + 1;
	counter = 0;

	while(words[counter])
	{
		if (words[counter + 1])
			ft_printf("%s ", words[counter++]);
		else
			ft_printf("%s\n", words[counter++]);
	}
}

void 	ft_unsetenv(t_all *all)
{
	int 	counter;
	bool 	flag;

	if (!all->words[1])
		return ;
	counter = 0;
	flag = false;
	while (all->env.env[counter])
	{
		if (!(ft_strcmp(all->words[1], all->env.env[counter])))
			flag = true;
		if (flag)
		{
			free(all->env.env[counter]);
			if (all->env.env[counter + 1])
				all->env.env[counter] = ft_strdup(all->env.env[counter + 1]);
		}
		counter++;
	}
}

void 	ft_export(t_all *all)
{
	int 	counter;
	int 	length;

	if (!all->words[1])
		return ;
	length = ft_strclen(all->words[1], '=');
	counter = 0;
	while (all->env.env[counter])
	{
		if (!ft_strncmp(all->words[1],all->env.env[counter], length))
		{
			free(all->env.env[counter]);
			all->env.env[counter] = ft_strdup(all->words[1]);
			return ;
		}
		counter++;
	}
	ft_env_add(all, all->words[1]);
}

void 	ft_exit(t_all *all)
{
	ft_free_all(&all);
	ft_printf("Bye-bye\n");
	exit(0);
}
