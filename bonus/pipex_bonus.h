/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:28:05 by mcloarec          #+#    #+#             */
/*   Updated: 2022/09/01 18:21:27 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
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

typedef struct s_pipe
{
	int	fd[2];
}				t_pipe;

typedef struct s_cmd
{
	pid_t	pid;
	char	*path_cmd;
	char	**name_cmd;
}				t_cmd;

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
	int		hdoc;
	t_cmd	*cmd;
	int		nb_cmd;
	t_pipe	*tab_pipe;	
}				t_shell;

/* Main bis */
void	check_arg(int argc, char **argv);

/* Init */
void	init_mult_pipes(t_shell *pipes, int argc, char **argv, char **envp);
void	create_cmd(t_shell *pipes, int argc, char **argv);
void	create_heredoc(t_shell *pipes, char **argv);
void	init_heredoc(t_shell *pipes, char **argv, char **envp);

/* Trouver les commandes */
void	find_path(t_shell *pipes, char **envp);
char	*get_path(t_shell *pipes, char *path_cmd);
int		check_path_cmd(char *path_cmd);

/* Processus child mandatory */
void	create_child1(t_shell pipes, char **envp);
void	create_child2(t_shell pipes, char **envp);
void	child1_exec(t_shell pipes, char **envp);
void	child2_exec(t_shell pipes, char **envp);

/* Processus child bonus */
void	create_mult_cmd(t_shell *pipes, char **envp);
void	child_cmd1(t_shell *pipes, char **envp);
void	child_n_cmd(t_shell *pipes, char **envp, int i);
void	child_last_cmd(t_shell *pipes, char **envp, int i);

/* Utils */
void	exit_error(char *message);
int		ft_strcmp(char *s1, char *s2);
char	*join_loop(char const *s1, char const *s2);
void	close_fd(t_shell *pipes);
void	close_pipe_fd(t_shell *pipes);

/* Free */
void	free_tab(char **tab);
void	free_pipex(t_shell *pipes, char *message);
void	free_path_cmd(t_shell *pipes, char *message);
void	free_cmd(t_shell *pipes, char *message);
void	free_cmd_tab(t_shell *pipes, char *message);
void	free_pipex_mult(t_shell *pipes, char *message);
void	free_close_mult(t_shell *pipes, char *message);
void	choose_free_path(t_shell *pipes, char *message);
void	free_mult_path_cmd(t_shell *pipes, char *message);
void	choose_free_pipex(t_shell *pipes, char *message);

#endif
