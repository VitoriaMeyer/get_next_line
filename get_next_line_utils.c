/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeyer-s <vmeyer-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 02:09:19 by vmeyer-s          #+#    #+#             */
/*   Updated: 2022/11/10 02:30:15 by vmeyer-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr_nl(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
	{
		if (str[i] == '\n')
			return (1);
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}	
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		ptr[j++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		ptr[j++] = s2[i];
		if (s2[i++] == '\n')
			break ;
	}
	ptr[j] = '\0';
	free (s1);
	return (ptr);
}

void	clean(char *buffer)
{
	int	j;
	int	i;
	int	k;

	k = 0;
	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (j)
			buffer[k++] = buffer[i];
		if (buffer[i] == '\n')
			j = 1;
		buffer[i++] = 0;
	}
}
