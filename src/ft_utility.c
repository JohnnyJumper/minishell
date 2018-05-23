/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 14:55:00 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/23 14:52:24 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_print_dir(char *prompt)
{
    char cwd[1024];

    getcwd(cwd, sizeof(cwd));
    ft_printf("Dir: %s\n\033[0;31m%s\033[0m ", cwd, prompt);
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
    ft_dict_free(&(*all)->shell->builtins);
    ft_dict_free(&(*all)->shell->env);
    free((*all)->shell);
    (*all)->shell = NULL;
    ft_words_free((*all)->words);
    (*all)->words = NULL;
    free(*all);
    *all = NULL;
}