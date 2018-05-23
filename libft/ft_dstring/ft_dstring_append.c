/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstring_append.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:40:00 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/21 12:46:21 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dstring.h"

int     ft_dstring_append(t_dstring *dstr, char *add)
{
        int len;
        char *tmp;

        if (!add)
                return (0);
        len = ft_strlen(add);
        if (dstr->capacity < len + dstr->length)
        {
                tmp = dstr->content;
                while (dstr->capacity <= (len + dstr->length))
                        dstr->capacity *= 2;
                dstr->content = (char *)malloc(dstr->capacity);
                if (!dstr->content)
                        return (0);
                if (*tmp)
                        ft_strcpy(dstr->content, tmp);
                ft_strcpy(dstr->content + dstr->length, add);
                dstr->length += len;
                if (tmp)
                        free(tmp);
                tmp = NULL;
        }
        else
        {
                ft_strcpy(dstr->content + dstr->length, add);
                dstr->length += len;
        }
        return (1);
}
