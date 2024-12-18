/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:03:58 by zel-ghab          #+#    #+#             */
/*   Updated: 2024/12/18 17:27:07 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *	get_next_line(int fd)
{
	char *		buffer;
	static char *	stash;
	char *		line;
	int		size;
	ssize_t		rread;
	
	rread = read(fd, buffer, size);
	ft_fill(buffer, stash);
	line = ft_check(stash, line);
	return (line);
}
