/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:29:03 by lroussel          #+#    #+#             */
/*   Updated: 2024/12/03 17:42:40 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "server.h"

static void	pl(char *line, const char *text_c, const char *outline_c)
{
	ft_printf("%s ||    %s", outline_c, text_c);
	ft_printf(line);
	ft_printf("\033[0m%s    ||\n\033[0m", outline_c);
}

void	header(void)
{
	int			equals;
	int			pid;
	const char	*tc = "\033[35m\033[1m\033[5m";
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
	ft_printf("{\033[92m \033[4mPID:\033[0m \033[33m%i\033[0m }", pid);
	char_repeat('=', equals / 2 + (equals % 2), 1);
	ft_printf("\n");
}
