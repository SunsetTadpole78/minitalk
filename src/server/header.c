/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:29:03 by lroussel          #+#    #+#             */
/*   Updated: 2024/12/03 14:33:38 by lroussel         ###   ########.fr       */
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

void	pl(char *line, const char *text_c, const char *outline_c)
{
	ft_printf("%s ||    %s", outline_c, text_c);
	ft_printf(line);
	ft_printf("%s    ||\n%s", outline_c, "\033[0m");
}

void	head(void)
{
	int			equals;
	int			pid;
	const char	*tc = "\033[35m";
	const char	*oc = "\033[90m";

	ft_printf(" ");
	char_repeat('=', 70, 1);
	pl(" _____ _     _ _       _ _      _____                     ", tc, oc);
	pl("|     |_|___|_| |_ ___| | |_   |   __|___ ___ _ _ ___ ___ ", tc, oc);
	pl("| | | | |   | |  _| .'| | '_|  |__   | -_|  _| | | -_|  _|", tc, oc);
	pl("|_|_|_|_|_|_|_|_| |__,|_|_,_|  |_____|___|_|  \\_/|___|_|  ", tc, oc);
	pl("                                                          ", tc, oc);
	ft_printf(" ");
	pid = getpid();
	equals = 68 - ft_log(pid, 10) - 7;
	char_repeat('=', equals / 2, 0);
	ft_printf("{\033[92m PID: \033[33m%i \033[0m}", pid);
	char_repeat('=', equals / 2 + (equals % 2), 1);
	ft_printf("\n");
}
