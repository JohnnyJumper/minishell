/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 14:01:16 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/20 14:23:47 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict.h"

int	ft_dict_insert(t_dict *dict, char *key, void *value)
{
	unsigned long	index;
	t_dict_item		*iter;

	index = ft_dict_hash(key) % dict->capacity;
	if (dict->items[index])
	{
		iter = dict->items[index];
		while (iter->next)
			iter = iter->next;
		iter->next = ft_dict_create_item(key, value);
		if (!iter->next)
			return (0);
	}
	else if (!(dict->items[index] = ft_dict_create_item(key, value)))
		return (0);
	return (1);
}
