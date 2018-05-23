/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 14:55:00 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/22 20:26:25 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_print_dir(char *prompt)
{
    char cwd[1024];

    getcwd(cwd, sizeof(cwd));
    ft_printf("Dir: %s\n\033[0;31m%s\033[0m ", cwd, prompt);
}
