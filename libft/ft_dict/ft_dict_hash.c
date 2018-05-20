/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 13:56:22 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/20 14:18:43 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict.h"

size_t	ft_dict_hash(char *input)
{
	unsigned long	hash;
	int				c;

	hash = 5381;
	while ((c = *input++))
		hash = ((hash << 5) + hash) + c;
	return (hash);
}
