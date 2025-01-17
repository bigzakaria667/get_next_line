/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:40:25 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/01/17 13:21:59 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *	ft_substr(char *str, int start, int end)
{
	int	i;
	char *	substr;
	
	i = 0;
	substr = malloc (sizeof(char) * (end - start + 1));
	if (!substr)
		return (free(substr), NULL);	
	while (start < end)
		substr[i++] = str[start++];
	substr[i] = '\0';
	return (substr);
}	

int	ft_strlen(char *source)
{
	int	i;

	i = 0;
	while (source[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;
	char	*strjoin;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	strjoin = (char *)malloc(s1_len + s2_len + 1);
	if (!strjoin)
		return (free(strjoin), NULL);
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
	return (strjoin);
}


char	*ft_strcopydup(char *source, char *copy)
{
	int	i;
	int	len;

	if (source == NULL)
		return (NULL);
	len = ft_strlen(source);
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (free(copy), NULL);
	i = 0;
	while (source[i])
	{
		copy[i] = source[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
