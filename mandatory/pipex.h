/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:28:05 by mcloarec          #+#    #+#             */
/*   Updated: 2022/08/25 18:01:19 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define STDIN 0
# define STDOUT 1
# define ERROR -1

# include<unistd.h>
# include<fcntl.h>
# include<stdlib.h>
# include<stdio.h>
# include<limits.h>
# include<errno.h>
# include<sys/wait.h>
# include<sys/types.h>
# include"../libft/libft.h"

typedef struct s_shell
{
	int		file1;
	int		file2;
	char	**cmd1;
	char	**cmd2;
	char	**path;
	char	*path_cmd1;
	char	*path_cmd2;
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;
}				t_shell;

/* Init */
void	init_pipes(t_shell *pipes, char **argv, char **envp);

/* Trouver les arguments */
void	find_path(t_shell *pipes, char **envp);
char	*get_path(t_shell *pipes, char *path_cmd);
int		check_path_cmd(char *path_cmd);

/* Processus child */
void	create_child1(t_shell pipes, char **envp);
void	create_child2(t_shell pipes, char **envp);
void	child1_exec(t_shell pipes, char **envp);
void	child2_exec(t_shell pipes, char **envp);

/* Utils */
void	exit_error(char *message);
void	free_tab(char **tab);
void	free_path(t_shell *pipes, char *message);
void	free_path_cmd(t_shell *pipes, char *message);
void	free_cmd(t_shell *pipes, char *message);
void	free_pipex(t_shell *pipes);
void	free_close(t_shell *pipes, char *message);

#endif
