/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 20:58:32 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/23 14:54:45 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void 	*ft_pwd(t_all *all)
{
	return (ft_dict_search(all->shell->env,"PWD"));
}

void 	*ft_cd(t_all *all)
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
	return (NULL);
}

void	*ft_echo(t_all *all)
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
	return (NULL);
}

void 	*ft_exit(t_all *all)
{
	ft_free_all(&all);
	ft_printf("Bye-bye\n");
	exit(0);
}