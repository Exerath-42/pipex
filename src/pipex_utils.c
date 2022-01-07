/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exerath <exerath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:29:08 by exerath           #+#    #+#             */
/*   Updated: 2022/01/07 06:11:42 by exerath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_freeall(t_input *input)
{
	int	i;

	i = -1;
	while (input->cmd1[++i])
		free(input->cmd1[i]);
	free(input->cmd1);
	i = -1;
	while (input->cmd2[++i])
		free(input->cmd2[i]);
	free(input->cmd2);
	free(input);
}

void	ft_freepath(char **path)
{
	int	i;

	i = -1;
	while (path[++i])
		free(path[i]);
	free(path);
}

char	*ft_isvalid(char **path, char *cmd)
{
	char	*tmp;
	int		flag;
	int		i;

	flag = 0;
	i = -1;
	while (path[++i] && flag == 0)
	{
		tmp = ft_strjoin(path[i], cmd);
		if ((open(tmp, O_RDONLY, 0)) < 0)
			free(tmp);
		else
			flag = 1;
	}
	return (tmp);
}

void	ft_findpath(char **cmd, char **env)
{
	int		i;
	char	**path;
	char	*tmp;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PATH", 3) == 0)
			path = ft_split(env[i], ':');
	}
	tmp = cmd[0];
	cmd[0] = ft_strjoin("/", tmp);
	free(tmp);
	tmp = 0;
	tmp = ft_isvalid(path, cmd[0]);
	free(cmd[0]);
	cmd[0] = tmp;
	ft_freepath(path);
}
