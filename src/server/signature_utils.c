/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signature_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:48:34 by lroussel          #+#    #+#             */
/*   Updated: 2024/12/04 09:48:35 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "server.h"

static void	process_signature(int sig, int *len, int type)
{
	static int	readed = 0;
	static int	c = 0;

	if (type == 1)
	{
		readed = 0;
		c = 0;
		return ;
	}
	c |= (sig == SIGUSR2) << (7 - readed);
	readed++;
	if (readed == 8)
	{
		if (c >= '0' && c <= '9')
			*len = (*len) * 10 + (c - '0');
		else if (c == 'a')
			set_type(1);
		else
			*len = -1;
		c = 0;
		readed = 0;
	}
}

int	check_signature(int sig, siginfo_t *info, int *len)
{
	if (get_type() == 1)
		return (0);
	process_signature(sig, len, 0);
	if (*len == -1)
	{
		*len = 0;
		process_message(0, 0, 1);
		process_signature(0, 0, 1);
		kill(info->si_pid, SIGUSR1);
	}
	else
		kill(info->si_pid, SIGUSR2);
	return (1);
}
