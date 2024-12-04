/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receiver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:27:34 by lroussel          #+#    #+#             */
/*   Updated: 2024/12/03 16:16:07 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "server.h"

static int	process_char(char c, int len, int pos, siginfo_t *info)
{
	if (!c)
	{
		process_message(len, 0, 0);
		return (1);
	}
	else if (pos > len)
	{
		process_message(0, 0, 1);
		kill(info->si_pid, SIGUSR1);
		return (1);
	}
	process_message(len, c, 0);
	return (0);
}

void	process(int sig, siginfo_t *info, void *context)
{
	static int	readed = 0;
	static int	c = 0;
	static int	len = 0;
	static int	pos = 0;

	if (check_signature(sig, info, &len))
		return ;
	(void)context;
	c |= (sig == SIGUSR2) << (7 - readed);
	readed++;
	if (readed == 8)
	{
		pos++;
		if (process_char(c, len, pos, info))
		{
			set_type(0);
			len = 0;
			pos = 0;
		}
		readed = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR2);
}
