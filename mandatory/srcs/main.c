/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:37:03 by mcloarec          #+#    #+#             */
/*   Updated: 2022/08/23 15:39:01 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_shell	pipes;

	if (argc != 5)
	{
		write(2, "Argument error\n", 15);
		exit(1);
	}
	else
	{
		init_pipes(&pipes, argv, envp);
		if (pipe(pipes.pipe_fd) < 0)
			free_close(&pipes, "Pipe error");
		create_child1(pipes, envp);
		create_child2(pipes, envp);
	}
	free_pipex(&pipes);
}
