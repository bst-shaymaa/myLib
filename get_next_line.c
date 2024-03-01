/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbousset <cbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:30:16 by cbousset          #+#    #+#             */
/*   Updated: 2024/03/01 17:34:46 by cbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

char	*new_line(char *s)
{
	char	*line;
	char	*str;
	int		len;

	str = ft_strchr(s, '\n');
	len = (str - s) + 1;
	line = ft_substr(s, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_read(int fd, char *s)
{
	int		i;
	char	*buffer;

	i = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&s));
	buffer[0] = '\0';
	while (i > 0 && !ft_strchr(buffer, '\n'))
	{
		i = read (fd, buffer, BUFFER_SIZE);
		if (i > 0)
		{
			buffer[i] = '\0';
			s = ft_strjoin(s, buffer);
		}
	}
	free(buffer);
	if (i == -1)
		return (ft_free(&s));
	return (s);
}

char	*ft_clean(char *s)
{
	char	*new_str;
	char	*str;
	size_t	len;

	str = ft_strchr(s, '\n');
	if (!str)
	{
		new_str = NULL;
		return (ft_free(&s));
	}
	else
		len = (str - s) + 1;
	if (!s[len])
		return (ft_free(&s));
	new_str = ft_substr(s, len, ft_strlen(s) - len);
	ft_free(&s);
	if (!new_str)
		return (NULL);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	*content;
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((content && !ft_strchr(content, '\n')) || !content)
		content = ft_read (fd, content);
	if (!content)
		return (NULL);
	line = new_line(content);
	if (!line)
		return (ft_free(&content));
	content = ft_clean(content);
	return (line);
}
