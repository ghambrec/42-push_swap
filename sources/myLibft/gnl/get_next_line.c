/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:04:19 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/18 14:57:23 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// create new buffer joining both buffer and read_buffer,
// after that free the old buffer
static char	*join_new_buffer(char *buffer, char *read_buffer)
{
	char	*new_buffer;

	if (!buffer)
	{
		return (ft_strdup_gnl(read_buffer));
	}
	new_buffer = ft_strjoin_gnl(buffer, read_buffer);
	free(buffer);
	return (new_buffer);
}

// return line and renew the buffer
static char	*return_line(char **buffer)
{
	char	*returnline;
	char	*new_buf;
	size_t	len;

	if (ft_strchr_gnl(*buffer, '\n'))
		len = (ft_strchr_gnl(*buffer, '\n') - *buffer) + 1;
	else
		len = ft_strlen_gnl(*buffer);
	returnline = (char *)malloc((len + 1) * sizeof(char));
	if (!returnline)
		return (free(*buffer), *buffer = NULL, NULL);
	ft_strlcpy_gnl(returnline, *buffer, len + 1);
	new_buf = (char *)malloc((ft_strlen_gnl(*buffer) - len + 1) * sizeof(char));
	if (!new_buf)
	{
		free(returnline);
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	ft_strlcpy_gnl(new_buf, *buffer + len, ft_strlen_gnl(*buffer) - len + 1);
	free(*buffer);
	*buffer = new_buf;
	return (returnline);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		read_buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	bytes_read = read(fd, read_buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		read_buffer[bytes_read] = '\0';
		buffer = join_new_buffer(buffer, read_buffer);
		if (!buffer)
			return (NULL);
		if (ft_strchr_gnl(buffer, '\n'))
			return (return_line(&buffer));
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
	}
	if (bytes_read < 0 || !buffer || !*buffer)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	return (return_line(&buffer));
}
