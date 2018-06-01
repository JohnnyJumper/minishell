/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 20:58:32 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/27 12:17:28 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void 	ft_pwd(t_all *all)
{
	ft_printf("%s\n", all->env.pwd);
}

void 	ft_env(t_all *all)
{
	int 	counter;

	counter = 0;
	while (all->env.env[counter])
		ft_printf("%s\n", all->env.env[counter++]);
}

void 	ft_cd(t_all *all)
{
	char 	*path;
	char	*tmp;

	path = all->words[1];
	if (*path == '~') {
		tmp = path;
		path = ft_strjoin(all->env.home, path + 1);
		ft_strdel(&tmp);
	}
	chdir(path);
	ft_strdel(&path);
}

void 	ft_help(t_all *all)
{
	if (all)
		;
	ft_printf("Builtins commands are:\n\tpwd\n\tcd\n\techo\n\tenv\n\texport\n");
	ft_printf("\tunsetenv\n\texit\n");
}