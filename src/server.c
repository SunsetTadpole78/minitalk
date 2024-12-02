/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:32:36 by lroussel          #+#    #+#             */
/*   Updated: 2024/12/02 14:23:43 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	type = 0;

void	fail_malloc(void)
{
	ft_printf("Fail malloc");//TODO
	exit(EXIT_FAILURE);
}

void	char_repeat(char c, int times, int linebreak)
{
	int	i;

	i = 0;
	while (i < times)
	{
		ft_printf("%c", c);
		i++;
	}
	if (linebreak)
		ft_printf("\n");
}

void	printheader(void)
{
	int	equals;
	int	pid;

	char_repeat('=', 73, 1);
	ft_printf("|  ___  __ _       _ _        _ _    ");
	ft_printf("  _____                            |\n");
	ft_printf("|  |  \\/  (_)     (_) |      | | |  ");
	ft_printf("  /  ___|                           |\n");
	ft_printf("|  | .  . |_ _ __  _| |_ __ _| | | __ ");
	ft_printf("\\ `--.  ___ _ ____   _____ _ __   |\n");
	ft_printf("|  | |\\/| | | '_ \\| | __/ _` | | |/ ");
	ft_printf("/  `--. \\/ _ \\ '__\\ \\ / / _ \\ '__|  |\n");
	ft_printf("|  | |  | | | | | | | || (_| | |   <  ");
	ft_printf("/\\__/ /  __/ |   \\ V /  __/ |     |\n");
	ft_printf("|  \\_|  |_/_|_| |_|_|\\__\\__,_|_|_|\\");
	ft_printf("_\\ \\____/ \\___|_|    \\_/ \\___|_|     |\n");
	ft_printf("|");
	char_repeat(' ', 71, 0);
	ft_printf("|\n");
	pid = getpid();
	equals = 73 - ft_log(pid, 10) - 7;
	char_repeat('=', equals / 2, 0);
	ft_printf(" PID: %i ", pid);
	char_repeat('=', equals / 2 + (equals % 2), 1);
	ft_printf("\n");
}

void	process_signature(int sig, int *len)
{
	static int	readed = 0;
	static int	c = 0;
	
	c |= (sig == SIGUSR2) << (7 - readed);
	readed++;
	if (readed == 8)
	{
		if (c >= '0' && c <= '9')
			*len = (*len) * 10 + (c - '0');
		else if (c == 'a')
			type = 1;
		else
			*len = -1;
		c = 0;
		readed = 0;
	}
}

void	process(int sig, siginfo_t *info, void *context)
{
	static int	readed = 0;
	static int	c = 0;
	static int	len = 0;
	static int	added = 0;
	static char	*word = NULL;

	if (type == 0)
	{
		process_signature(sig, &len);
		if (len == -1)
		{
			kill(info->si_pid, SIGUSR1);
			len = 0;
		}
		else
			kill(info->si_pid, SIGUSR2);
		return ;
	}

	(void)context;
	c |= (sig == SIGUSR2) << (7 - readed);
	readed++;
	if (readed == 8)
	{
		if (!word)
		{
			word = malloc(sizeof(char) * (len + 1));
			if (!word)
				fail_malloc();
		}

		added++;
		if (!c)
		{
			write(1, "» ", 4);
			word[len] = '\0';
			write(1, word, len);
			free(word);
			word = NULL;
			write(1, "\n", 1);
			type = 0;
			len = 0;
			added = 0;
		}
		else if (added > len)
		{
			kill(info->si_pid, SIGUSR1);
			type = 0;
			len = 0;
			added = 0;
		}
		else
			word[added - 1] = c;
		readed = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{	
	struct sigaction	action;

	printheader();
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = &process;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
