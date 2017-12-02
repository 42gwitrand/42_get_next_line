/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwitrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:56:43 by gwitrand          #+#    #+#             */
/*   Updated: 2017/11/14 11:56:45 by gwitrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		vrf(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == NEW_LINE)
			return (i);
		++i;
	}
	return (-1);
}

int		s(char *st_str, int ret, char *str, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	++ret;
	tmp = ft_strjoin(str, st_str);
	tmp[vrf(tmp)] = '\0';
	while (st_str[ret] != '\0')
		st_str[i++] = st_str[ret++];
	st_str[i] = '\0';
	if ((*line = ft_strdup(tmp)) == NULL)
		return (-1);
	free(str);
	free(tmp);
	return (1);
}

char	*erase_leaks(char *str, char *st_str)
{
	char *tmp;

	tmp = ft_strjoin(str, st_str);
	free(str);
	str = ft_strdup(tmp);
	free(tmp);
	tmp = NULL;
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	static struct s_gnl gnl[5000];

	if (BUFF_SIZE < 1 || fd > 5000 || fd < 0 || !line)
		return (-1);
	if (gnl[fd].st_str == NULL)
		gnl[fd].st_str = ft_strnew(BUFF_SIZE);
	gnl[fd].str = ft_strdup(gnl[fd].st_str);
	if (vrf(gnl[fd].str) != -1)
		return (s(gnl[fd].st_str, vrf(gnl[fd].st_str), gnl[fd].str, line));
	while ((gnl[fd].size = read(fd, gnl[fd].st_str, BUFF_SIZE)) > 0)
	{
		gnl[fd].st_str[gnl[fd].size] = '\0';
		if (vrf(gnl[fd].st_str) != -1)
			return (s(gnl[fd].st_str, vrf(gnl[fd].st_str), gnl[fd].str, line));
		gnl[fd].str = erase_leaks(gnl[fd].str, gnl[fd].st_str);
	}
	if (gnl[fd].size == -1)
		return (-1);
	if (gnl[fd].size == 0 && (ft_strlen(gnl[fd].st_str) == 0))
		return (0);
	gnl[fd].st_str = ft_strnew(1);
	if (!(*line = ft_strdup(gnl[fd].str)))
		return (-1);
	return (1);
}
