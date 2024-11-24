/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:10:58 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/24 11:58:38 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	ft_printf("\n\n» ");
}

void	process(int sign, siginfo_t *info, void *context)
{
	static int	c = 0;
	static int	readed = 0;

	 (void)context;
	if (sign == SIGUSR2)
		c |= (0x01 << (7 - readed));
	readed++;
	if (readed == 8)
	{
		write(1, &c, 1);
		if (!c)
		{
			write(1, "\n» ", 4);
			kill(info->si_pid, SIGUSR1);
		}
		readed = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	action;

	printheader();
	action.sa_flags = 0;
	action.sa_sigaction = &process;
	sigemptyset(&action.sa_mask);
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause();
	}
	return (0);
}
