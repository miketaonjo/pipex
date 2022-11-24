/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:58:56 by mcloarec          #+#    #+#             */
/*   Updated: 2022/09/03 10:55:23 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	check_argc(int argc, char **argv)
{
	if (argc < 6)
	{
		write(2, "Argument error\n", 15);
		exit(1);
	}
	else if (argc == 6 && ft_strcmp(argv[1], "here_doc") != 0
		&& check_path_cmd(argv[1]) == ERROR)
	{
		write(2, "Here_doc error\n", 15);
		exit(1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	pipes;

	check_argc(argc, argv);
	if (argc == 6 && ft_strcmp(argv[1], "here_doc") == 0)
	{
		init_heredoc(&pipes, argv, envp);
		if (pipe(pipes.pipe_fd) < 0)
			free_pipex(&pipes, "Pipe error");
		create_child1(pipes, envp);
		create_child2(pipes, envp);
	}
	else
	{
		init_mult_pipes(&pipes, argc, argv, envp);
		pipes.tab_pipe = malloc(sizeof(t_pipe) * (pipes.nb_cmd));
		if (!pipes.tab_pipe)
		{
			close_fd(&pipes);
			free_mult_path_cmd(&pipes, "Malloc error");
		}
		create_mult_cmd(&pipes, envp);
	}
	choose_free_pipex(&pipes, "");
	return (0);
}
