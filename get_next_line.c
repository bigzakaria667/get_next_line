/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:03:58 by zel-ghab          #+#    #+#             */
/*   Updated: 2024/12/23 17:58:52 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

char *	get_next_line(int fd)
{
	char *		buffer[5];
	static char *	stash;
	char *		line;
	int		size;
	ssize_t		rread;
	
	rread = read(fd, buffer, size);
	stash = malloc(sizeof(char) * 5 + 1);
	ft_fill(buffer, stash);
	line = ft_check(stash, line);
	free(stash);
	return (line);
}
