/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeyer-s <vmeyer-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 02:09:30 by vmeyer-s          #+#    #+#             */
/*   Updated: 2022/11/10 02:35:24 by vmeyer-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	while (!ft_strchr_nl(line))
	{
		if (!*buffer)
		{
			if (read(fd, buffer, BUFFER_SIZE) <= 0)
				break ;
		}
		line = ft_strjoin(line, buffer);
		clean(buffer);
	}
	return (line);
}
