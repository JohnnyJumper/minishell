/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:36:48 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/25 13:37:04 by jtahirov         ###   ########.fr       */
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
	char 	*key;

	key = all->words[1];
	if (!key)
		return ;
	ft_dict_remove(all->shell->env, key);
}

void 	ft_export(t_all *all)
{
	char 	*delim;	

	delim = ft_strchr(all->words[1], '=');
	if (!delim)
		return ;
	*delim = '\0';
	if (ft_dict_search(all->shell->env, all->words[1]))
		ft_dict_replace_value(all->shell->env, all->words[1], delim + 1);
	else
		ft_dict_insert(all->shell->env, all->words[1], delim + 1);
}

void 	ft_exit(t_all *all)
{
	ft_free_all(&all);
	ft_printf("Bye-bye\n");
	exit(0);
}
