/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:14:43 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/21 14:15:34 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

static int		lineset(const int fd, char **line)
{
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;

	if ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		tmp = *line;
		*line = ft_strjoin(tmp, buffer);
		ft_strdel(&tmp);
	}
	return (ret);
}

static t_gnl	*determine_file(const int fd, t_gnl **master_list)
{
	t_gnl *ptr;

	ptr = *master_list;
	while (ptr && ptr->fd != fd)
		ptr = ptr->next;
	if (!ptr)
	{
		ptr = (t_gnl *)ft_memalloc(sizeof(t_gnl));
		ptr->fd = fd;
		if (!(ptr->line = ft_strnew(0)))
			return (NULL);
		ptr->next = *master_list;
		*master_list = ptr;
	}
	return (ptr);
}

int				ft_get_next_line(const int fd, char **line)
{
	static t_gnl	*master_list;
	t_gnl			*f;
	char			*tmp;

	if (fd < 0 || !line)
		return (-1);
	f = determine_file(fd, &master_list);
	LINCHK(f->line);
	while (!(ft_strchr(f->line, '\n')))
	{
		if (lineset(f->fd, &f->line) < 0)
			return (-1);
		if (!(lineset(f->fd, &f->line)) && (!(ft_strchr(f->line, '\n'))))
		{
			LINCHK(f->line[0]);
			*line = f->line;
			f->line = NULL;
			return (1);
		}
	}
	*line = ft_strsub(f->line, 0, (ft_strchr(f->line, '\n') - f->line));
	tmp = f->line;
	f->line = ft_strdup(ft_strchr(f->line, '\n') + 1);
	ft_strdel(&tmp);
	return (1);
}