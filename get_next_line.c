/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:03:58 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/01/30 22:31:03 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *	ft_update_stock(char ** stockage, int n)
{
	int	len;
	char *	updatestock;

	if (!stockage)
		return (NULL);
	len = ft_strlen(*stockage);
	if (len > n + 1)
	{
		updatestock = ft_substr(*stockage, n + 1, len);
		if (!updatestock)
			return (free(*stockage), *stockage = NULL ,NULL);
	}
	else
		updatestock = NULL;
	return (free(*stockage), *stockage = NULL, updatestock);
}

static char *	ft_extract_line(char * stockage, int n)
{
	char *	line;

	line = ft_substr(stockage, 0, n + 1);
	if (!line)
		return (NULL);
	return (line);
}

static char *	ft_concat(char ** stockage, int n)
{
	char *	line;

	line = ft_extract_line(*stockage, n);
	if (!line)
		return (free(*stockage), *stockage = NULL, NULL);
	*stockage = ft_update_stock(stockage, n);
	return (line);
}

char *	ft_finder(char ** stockage, char * buffer)
{
	int 	i;

	if (!*stockage)
		*stockage = ft_strcopydup(buffer);
	else
		*stockage = ft_strjoin(*stockage, buffer);
	if (!*stockage)
		return (NULL);
	i = 0;
	while ((*stockage)[i] && (*stockage)[i] != '\n')
		i++;
	if ((*stockage)[i] == '\n')
		return (ft_concat(stockage, i));
	return (NULL);
}

char *	get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char *		line;
	static char *	stockage;
	int		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= (long)2147483647 || read(fd, 0, 0) < 0)
		return (free(stockage), stockage = NULL, NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (free(stockage), stockage = NULL, NULL);
	buffer[bytes_read] = '\0';
	while (bytes_read != 0 || ft_strchr(stockage, '\n'))
	{
		line = ft_finder(&stockage, buffer);
		if (line != NULL)
			return line;
		if (!ft_strchr(stockage, '\n'))
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read < 0)
				return (free(stockage), stockage = NULL, NULL);
			buffer[bytes_read] = '\0';
		}
	}
	if (stockage && ft_strlen(stockage) > 0)
		return (line = stockage, stockage = NULL, line);
	return (free(stockage), stockage = NULL, NULL);
}
