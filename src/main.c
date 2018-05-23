/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 18:40:07 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/22 21:45:30 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void ft_run_shell(t_all *all, int fd)
{
	char 	command[MAXINPUT];
	int 	ret;

	while (1)
	{
		ft_print_dir(ft_dict_search(all->shell->env, "PS1"));
		ft_bzero(command, MAXINPUT - 1);
		ret = read(fd, command, MAXINPUT - 1);
		command[ret] = '\0';
		ft_parse_command(command, all);
	}
}

int main(int argc, char **argv, char **environ)
{
	t_all 	*all;

	int 	fd;

	if (argc || argv || environ)
		;
		fd = STDINPUT;
	all = (t_all *)ft_memalloc(sizeof(t_all));
	all->shell = ft_init_variables(environ);
	ft_run_shell(all, fd);
	return (0);
}
