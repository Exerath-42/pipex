/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exerath <exerath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:49:19 by exerath           #+#    #+#             */
/*   Updated: 2021/10/18 13:07:00 by exerath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_fork1(t_input *input, int *fd, char **env)
{
	dup2(fd[1], 1);
	dup2(input->fd1, 0);
	close(input->fd1);
	close(input->fd2);
	close(fd[0]);
	close(fd[1]);
	execve(input->cmd1[0], input->cmd1, env);
	exit(0);
}

void	ft_fork2(t_input *input, int *fd, char **env)
{
	dup2(fd[0], 0);
	dup2(input->fd2, 1);
	close(input->fd2);
	close(input->fd1);
	close(fd[0]);
	close(fd[1]);
	execve(input->cmd2[0], input->cmd2, env);
	exit(0);
}

int	ft_pipe(t_input *input, char **env)
{
	int	pid1;
	int	pid2;
	int	fd[2];

	if (pipe(fd) == -1)
		return (0);
	pid1 = fork();
	if (pid1 < 0)
		return (0);
	if (pid1 == 0)
		ft_fork1(input, fd, env);
	pid2 = fork();
	if (pid2 < 0)
		return (0);
	if (pid2 == 0)
		ft_fork2(input, fd, env);
	close(input->fd2);
	close(input->fd1);
	close(fd[0]);
	close(fd[1]);
	wait(0);
	wait(0);
	return (0);
}

void	ft_error(int num)
{
	if (num == 0)
	{
		write(1, "wrong argument numder\n", 22);
		exit(0);
	}
	if (num == 1)
	{
		write(1, "failed to open\n", 15);
		exit(0);
	}
	if (num == 2)
	{
		write(1, "command not found\n", 18);
		exit(0);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_input	*input;

	input = (t_input *)malloc(sizeof(t_input));
	if (argc != 5)
		ft_error(0);
	input->fd1 = open(argv[1], O_RDONLY, 0);
	input->fd2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (input->fd1 < 0 || input->fd2 < 0)
		ft_error(1);
	input->cmd1 = ft_split(argv[2], ' ');
	input->cmd2 = ft_split(argv[3], ' ');
	ft_findpath(input->cmd1, env);
	ft_findpath(input->cmd2, env);
	if ((open(input->cmd1[0], O_RDONLY, 0)) < 0)
		ft_error(2);
	else if ((open(input->cmd2[0], O_RDONLY, 0)) < 0)
		ft_error(2);
	ft_pipe(input, env);
	ft_freeall(input);
	return (0);
}
