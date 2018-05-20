/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 18:40:07 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/20 14:13:43 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void printDir()
{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    ft_printf("\nDir: %s\033[0;31m>>>\033[0m ", cwd);
}

int 	ft_get_input(char **input)
{
	int 	ret;

	printDir();
	printf("\nbefore getnextline\n");
	ret = ft_get_next_line(STDINPUT, input);
	printf("After getnextline\n");
	if (ret == -1)
		ft_printf("Error reading stdinput\n");
	ft_printf("ret = %d\n", ret);	
	return (ret);
}

int		main(int argc, char **argv, char **environ)
{
	char 	*input;

	if (argc && argv && environ)
		;
	input = ft_strnew(MAXINPUT);
	while(1)
	{
		ft_bzero(input, MAXINPUT);
		if (!ft_get_input(&input))
			continue;
		if (input)
			ft_printf("%s", input);
	}

	return (0);
}
