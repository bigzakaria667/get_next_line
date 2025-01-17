/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:03:58 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/01/17 13:33:41 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *	ft_update_stock(char * stockage, int n)
{
	int	len;
	char *	updatestock;

	len = ft_strlen(stockage);
	if (len > n)
		updatestock = ft_substr(stockage, n + 1, len);
	else
		updatestock = NULL;
	return (updatestock);
}

static char *	ft_extract_line(char * stockage, int n)
{
	char *	line;

	line = ft_substr(stockage, 0, n + 1);
	return (line);
}

static char *	ft_concat(char * buffer, char * stockage)
{
	if (!stockage)
		stockage = ft_strcopydup(buffer, NULL);
	else
		stockage = ft_strjoin(stockage, buffer);
	return (stockage);
}

char *	get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char *		line;
	static char *	stockage;
	ssize_t		bytes_read;
	int		n;
	int		i;

	line = NULL;
	i = 0;
	while (line == NULL && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
			buffer[bytes_read] = '\0';
		stockage = ft_concat(buffer, stockage);
		while (stockage[i] && stockage[i] != '\n')
			i++;
		if (stockage[i] == '\n')
		{
			n = i;
			line = ft_extract_line(stockage, n);
			stockage = ft_update_stock(stockage, n);
		}
	}
	return (line);
}

int	main(void)
{
	int	fd;
	char *	line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Erreur lors de l'ouverture du fichier");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}
