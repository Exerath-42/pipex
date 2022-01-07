/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exerath <exerath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:09:49 by exerath           #+#    #+#             */
/*   Updated: 2021/10/18 13:09:53 by exerath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_input
{
	int		fd1;
	int		fd2;
	char	**cmd1;
	char	**cmd2;
}				t_input;

char	**ft_split(char	const *s, char c);
void	ft_findpath(char **cmd, char **env);
void	ft_freeall(t_input *input);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

#endif