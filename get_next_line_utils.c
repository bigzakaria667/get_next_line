/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:40:25 by zel-ghab          #+#    #+#             */
/*   Updated: 2024/12/23 17:53:36 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

void	ft_fill(char *buffer, static char *stash)
{
	int		i;
	static int	j;

	i = 0;
	while (b[i])
		stash[j++] == buffer[i++];
	stash[j] = ´\0´;
}

char *	ft_check(static char *stash, char *line)
{
	int	i;
	int	backslash;

	i = 0;
	while (stash[i] != ´\n´ || stash[i])
		i++;
	if (stash[i] == ´\n´)
	{
		backslash = i;
		i = 0;
		while (i < backslash)
			line[i] == stash[i++];
	}
	return (line);
}
