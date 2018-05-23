/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstring_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:42:46 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/21 12:43:28 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dstring.h"

t_dstring        *ft_dstring_init(void)
{
        t_dstring        *fresh;

        fresh = (t_dstring *)malloc(sizeof(t_dstring));
        fresh->length = 0;
        fresh->capacity = 1;
        fresh->content = (char *)malloc(fresh->capacity);
        return (fresh);
}