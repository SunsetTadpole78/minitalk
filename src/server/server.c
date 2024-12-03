/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:32:36 by lroussel          #+#    #+#             */
/*   Updated: 2024/12/03 12:16:54 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_type = 0;

void	set_type(int type)
{
	g_type = type;
}

int	get_type(void)
{
	return (g_type);
}

int	main(void)
{
	struct sigaction	action;

	head();
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = &process;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
