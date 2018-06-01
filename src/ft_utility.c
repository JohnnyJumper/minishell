/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 14:55:00 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/27 16:54:13 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_print_prompt(char *prompt)
{
    ft_printf("\033[0;31m%s\033[0m ", prompt);
}

void    ft_words_free(char **words)
{
    int     counter;

    counter = 0;
    while (words[counter])
        free(words[counter++]);
}

void    ft_free_all(t_all **all)
{
    ft_words_free((*all)->words);
    free((*all)->words);
    ft_words_free((*all)->env.env);
    free((*all)->env.env);
    free(&(*all)->env);
    ft_dict_free(&(*all)->builtins);
    ft_memdel((void **)all);
}

void ft_env_add(t_all *all, char *toadd)
{
	char 	**fresh;
	int 	counter;

	fresh = (char **)ft_memalloc(sizeof(char *) * all->env.length + 2);
	counter = -1;
	while (all->env.env[++counter])
	{
		fresh[counter] = ft_strdup(all->env.env[counter]);
		free(all->env.env[counter]);
	}
	fresh[counter] = ft_strdup(toadd);
	free(all->env.env);
	all->env.env = fresh;
}
