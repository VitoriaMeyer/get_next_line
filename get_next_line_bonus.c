/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeyer-s <vmeyer-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:07:44 by vmeyer-s          #+#    #+#             */
/*   Updated: 2022/11/10 02:51:06 by vmeyer-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	while (!ft_strchr_nl(line))
	{
		if (!*buffer[fd])
		{
			if (read(fd, buffer[fd], BUFFER_SIZE) <= 0)
				break ;
		}
		line = ft_strjoin(line, buffer[fd]);
		clean(buffer[fd]);
	}
	return (line);
}
