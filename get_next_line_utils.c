/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:40:25 by zel-ghab          #+#    #+#             */
/*   Updated: 2024/12/18 17:26:53 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_fill(char *buffer, char *stash)
{
	int	i;

	i = 0;
	while (b[i])
		stash[i] == buffer[i++];
}

char *	ft_check(char *stash, char *line)
{
	int	i;
	int	backslash;

	i = 0;
	while (stash[i] != ´\n´ || stash[i])
		i++;
	if (stash[i] == ´\n´)
	{
		i = 0;
		while (i < backslash)
			line[i] == stash[i++];
	}
	return (line);
}
