/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:39:46 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/01/16 18:46:30 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/*----------------  get_next_line_utils.c  ---------------*/

char *	ft_substr(char *str, int start, int end);
int	ft_strlen(char *source);
char *	ft_strjoin(const char *s1, const char *s2);
char *	ft_strcopydup(char *source, char *copy);

/*----------------  get_next_line.c  ---------------*/
char *	get_next_line(int fd);

#endif
