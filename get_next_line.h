/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:39:46 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/02/01 20:27:59 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MAXINT 2147483647

/*----------------  get_next_line_utils.c  ---------------*/
char	*ft_substr(char *str, int start, int end);
int		ft_strlen(char *source);
char	*ft_strjoin(char *s1, char *s2, int bytes_read);
char	*ft_strcopydup(char *source, int bytes_read);
int		ft_strchr(char *stockage, char a);
/*----------------  get_next_line.c  ---------------*/
char	*get_next_line(int fd);

#endif
