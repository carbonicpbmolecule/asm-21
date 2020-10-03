/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 00:02:37 by jirwin            #+#    #+#             */
/*   Updated: 2020/05/21 21:54:48 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_buffer(char *s, char **line)
{
	if (*s)
	{
		if (ft_strchr(s, '\n'))
		{
			*line = ft_strsub(s, 0, ft_strchr(s, '\n') - s);
			ft_strcpy(s, ft_strchr(s, '\n') + 1);
			return (1);
		}
		*line = ft_strdup(s);
	}
	else
		*line = ft_strdup("");
	return (0);
}

static int		check_line(char *buf, char **line, char *s)
{
	char			*temp1;
	char			*temp2;

	if (ft_strchr(buf, '\n'))
	{
		if (!(temp1 = ft_strsub(buf, 0, ft_strchr(buf, '\n') - buf)))
			return (-1);
		temp2 = *line;
		*line = ft_strjoin(temp2, temp1);
		free(temp1);
		free(temp2);
		ft_strcpy(s, ft_strchr(buf, '\n') + 1);
		return (1);
	}
	else
	{
		temp1 = *line;
		*line = ft_strjoin(temp1, buf);
		free(temp1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char		s[MAX_FD][BUFF_SIZE + 1];
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || fd > MAX_FD || line == 0 || (read(fd, s[fd], 0) < 0))
		return (-1);
	if ((ret = get_buffer(s[fd], line)))
		return (ret);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (check_line(buf, line, s[fd]))
			return (1);
		if (ret < BUFF_SIZE)
			return (1);
	}
	if (ret < 0)
		return (-1);
	if (ft_strcmp(*line, "") != 0)
		return (1);
	return (0);
}
