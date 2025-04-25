/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <ssinanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:15:30 by ssinanis          #+#    #+#             */
/*   Updated: 2025/04/03 14:56:07 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	b;

	i = ft_strlen(s1);
	b = ft_strlen(s2);
	while (n > 0)
	{
		if (i == 0 || b == 0)
		{
			ft_compare_end(i, b, s1, s2);
		}
		if (s1[i - 1] != s2[b - 1])
			return ((unsigned char)s1[i - 1] - (unsigned char)s2[b - 1]);
		i--;
		b--;
		n--;
	}
	return (0);
}

int	ft_compare_end(size_t i, size_t b, const char *s1, const char *s2)
{
	if (i == 0 && b == 0)
		return (0);
	if (i == 0)
		return (-(unsigned char)s2[b - 1]);
	return ((unsigned char)s1[i - 1]);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_trim_spaces(char *str)
{
	int		i;
	int		j;
	char	*result;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	j = ft_strlen(str) - 1;
	while (j > 0 && (str[j] == ' ' || str[j] == '\t' || str[j] == '\n'))
		j--;
	result = ft_substr(str, i, j + 1);
	return (result);
}
