/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 15:28:59 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/21 14:15:33 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include "../libft.h"

# define GNLBUFF 128
# define LINCHK(x) if (!x) return (0);

typedef struct			s_gnl
{
	int					fd;
	char				*line;
	struct s_gnl		*next;
}						t_gnl;

int 			ft_get_next_line(int fd, char **line);

#endif
