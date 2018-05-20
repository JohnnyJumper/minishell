/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_create_item.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 13:59:07 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/20 14:24:10 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict.h"

t_dict_item	*ft_dict_create_item(char *key, void *value)
{
	t_dict_item	*fresh;

	if (!(fresh = (t_dict_item *)malloc(sizeof(t_dict_item))))
		return (NULL);
	ft_bzero(fresh, sizeof(t_dict_item));
	fresh->key = key;
	fresh->value = value;
	fresh->next = NULL;
	return (fresh);
}
