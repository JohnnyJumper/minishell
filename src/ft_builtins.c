/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 20:58:32 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/25 13:40:46 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void 	ft_pwd(t_all *all)
{
	ft_printf("%s\n",ft_dict_search(all->shell->env,"PWD"));
}

void 	ft_env(t_all *all)
{
	t_dict_item  **array;
	int 		 counter;
	t_dict_item  *iter;

	array = all->shell->env->items;
	counter = 0;
	while (counter < all->shell->env->capacity)
	{
		iter = array[counter++];
		if (!iter)
			continue;
		while (iter)
		{
			ft_printf("%s=%s\n", iter->key, iter->value);
			iter = iter->next;
		}
	}
}

void 	ft_cd(t_all *all)
{
	char 	*path;
	char	*tmp;

	path = all->words[1];
	if (*path == '~') {
		tmp = path;
		path = ft_strjoin(ft_dict_search(all->shell->env, "HOME"), path + 1);
		ft_strdel(&tmp);
	}
	ft_printf("path = |%s|\n", path);
	chdir(path);
}

void 	ft_help(t_all *all)
{
	if (all)
		;

	ft_printf("Builtins commands are:\n\tpwd\n\tcd\n\techo\n\tenv\n\texport\n");
	ft_printf("\tunsetenv\n\texit\n");
}