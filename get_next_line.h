/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwitrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:19:48 by gwitrand          #+#    #+#             */
/*   Updated: 2017/11/14 11:51:54 by gwitrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

# define BUFF_SIZE (10)

# define NEW_LINE '\n'

struct		s_gnl
{
	int		fd;
	char	*str;
	char	*st_str;
	int		size;
};
int			get_next_line(const int fd, char **line);

#endif
