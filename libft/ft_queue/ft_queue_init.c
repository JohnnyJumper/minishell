/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 13:30:49 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/20 14:36:52 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

t_queue		*ft_queue_init(void)
{
	t_queue	*fresh;

	fresh = (t_queue *)malloc(sizeof(fresh));
	fresh->first = NULL;
	fresh->last = NULL;
	return (fresh);
}
