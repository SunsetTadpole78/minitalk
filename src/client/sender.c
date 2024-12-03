/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sender.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:27:13 by lroussel          #+#    #+#             */
/*   Updated: 2024/12/03 16:22:15 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_sig(int pid, int sig)
{
	int	fail;

	set_received(0);
	if (kill(pid, sig) == -1)
		wrong_pid();
	fail = 0;
	while (!is_received())
	{
		usleep(5);
		if (fail > 50)
		{
			send_sig(pid, sig);
			break ;
		}
		fail++;
	}
}

void	send_char(int pid, int c)
{
	int	i;

	i = 8;
	while (i-- != 0)
		send_sig(pid, 10 + ((c >> i) & 1) * 2);
}

void	send_signature(int pid, int len, int start)
{
	signal(SIGUSR1, sresend);
	if (len <= 0)
		return ;
	send_signature(pid, len / 10, 0);
	send_char(pid, (len % 10) + '0');
	if (start)
		send_char(pid, 'a');
}

void	send_message(int pid, char *message)
{
	int	i;

	i = 0;
	signal(SIGUSR1, sresend);
	while (i == 0 || message[i - 1])
	{
		if (resend(0))
			return ;
		send_char(pid, message[i]);
		i++;
	}
}

void	send(int pid, char *message)
{
	resend(2);
	send_signature(pid, ft_strlen(message), 1);
	if (resend(0))
	{
		send(pid, message);
		warning("Signal lost, resending message... (warn code 0)");
		return ;
	}
	resend(2);
	send_message(pid, message);
	if (resend(0))
	{
		warning("Signal lost, resending message... (warn code 1)");
		send(pid, message);
		return ;
	}
	if (is_received())
	{
		//write(1, "\033[32mThe message has been received by the server !", 50);
		//write(1, "\033[39m\n", 6);
	}
}
