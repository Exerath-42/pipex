/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exerath <exerath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:53:24 by exerath           #+#    #+#             */
/*   Updated: 2021/10/18 12:57:19 by exerath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	i;
	size_t	b;
	char	*newstr;

	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2);
		newstr = (char *)malloc(sizeof(char) * (size + 1));
		if (!newstr)
			return (NULL);
		i = 0;
		b = -1;
		while (s1[++b])
			newstr[i++] = s1[b];
		b = -1;
		while (s2[++b])
			newstr[i++] = s2[b];
		newstr[i] = '\0';
		return (newstr);
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
