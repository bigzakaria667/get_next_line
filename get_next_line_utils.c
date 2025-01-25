/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:40:25 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/01/24 19:23:09 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *	ft_substr(char *str, int start, int end)
{
	int	i;
	char *	substr;
	
	if (!str || start >= ft_strlen(str) || start >= end)
		return(NULL);	
	i = 0;
	substr = malloc (sizeof(char) * (end - start + 1));
	if (!substr)
		return (NULL);	
	while (start < end && str[start])
		substr[i++] = str[start++];
	substr[i] = '\0';
	return (substr);
}	

int	ft_strlen(char *source)
{
	int	i;

	if (!source)
		return (0);
	i = 0;
	while (source[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;
	char	*strjoin;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	strjoin = malloc (sizeof(char) * (s1_len + s2_len + 1));
	if (!strjoin)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (s2[j])
		strjoin[i++] = s2[j++];
	strjoin[i] = '\0';
	return (free(s1), s1 = NULL, strjoin);
}


char	*ft_strcopydup(char *source)
{
	char *	copy;
	int	i;
	int	len;

	if (!source)
		return (NULL);
	len = ft_strlen(source);
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (source[i])
	{
		copy[i] = source[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
