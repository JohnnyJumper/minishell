/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 13:57:38 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/20 14:17:16 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict.h"

t_dict	*ft_dict_init(int capacity)
{
	t_dict *fresh;

	fresh = (t_dict *)malloc(sizeof(t_dict));
	fresh->capacity = capacity;
	fresh->items = (t_dict_item **)malloc(sizeof(t_dict_item *) * capacity);
	ft_bzero(fresh->items, sizeof(t_dict_item *) * capacity);
	return (fresh);
}
