/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exerath <exerath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:10:03 by exerath           #+#    #+#             */
/*   Updated: 2022/01/07 06:11:34 by exerath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	parts_count(char const *s, char c)
{
	int		i;
	int		part;

	part = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			part++;
		i++;
	}
	return (part);
}

static int	check_lenght(char const *s, char c)
{
	int		len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
	{
		len++;
	}
	return (len);
}

static void	*ft_free_str(char **splitted, int part)
{
	int	i;

	i = 0;
	while (i < part)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return (NULL);
}

static char	**fill(char const *s, int part, char c, char **splitted)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	while (++i < part)
	{
		while (*s == c)
			s++;
		len = check_lenght(s, c);
		splitted[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!splitted[i])
			return (ft_free_str(splitted, i));
		j = 0;
		while (j < len)
			splitted[i][j++] = *s++;
		splitted[i][j] = '\0';
	}
	splitted[i] = NULL;
	return (splitted);
}

char	**ft_split(char	const *s, char c)
{
	char	**splitted;
	int		part;

	if (!s)
		return (NULL);
	part = parts_count(s, c);
	splitted = (char **)malloc(sizeof(char *) * (part + 1));
	if (!splitted)
		return (NULL);
	splitted = fill(s, part, c, splitted);
	return (splitted);
}
