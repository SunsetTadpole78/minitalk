/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sender.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:27:13 by lroussel          #+#    #+#             */
/*   Updated: 2024/12/04 10:31:27 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "client.h"

static void	send_sig(int pid, int sig)
{
	int	try;

	set_received(0);
	if (kill(pid, sig) == -1)
		wrong_pid();
	try = 0;
	usleep(1);
	while (!is_received())
	{
		try++;
		if (try >= 500)
			return ;
		usleep(1);
	}
}

static void	send_char(int pid, int c)
{
	int	i;

	i = 8;
	while (i-- != 0)
		send_sig(pid, 10 + ((c >> i) & 1) * 2);
}

static void	send_message(int pid, char *message)
{
	int	i;

	i = 0;
	signal(SIGUSR1, handle_resend);
	while (i == 0 || message[i - 1])
	{
		if (resend(0))
			return ;
		send_char(pid, message[i]);
		i++;
	}
}

static void	send_signature(int pid, int len, int start)
{
	signal(SIGUSR1, handle_resend);
	if (len <= 0)
		return ;
	send_signature(pid, len / 10, 0);
	send_char(pid, (len % 10) + '0');
	if (start)
		send_char(pid, 'a');
}

void	send(int pid, char *message)
{
	resend(2);
	send_signature(pid, ft_strlen(message), 1);
	if (resend(0))
	{
		warning("Signal lost, resending message... (warn code 0)");
		send(pid, message);
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
		write(1, "\033[32mThe message has been received by the server !", 50);
		write(1, "\033[39m\n", 6);
	}
}
