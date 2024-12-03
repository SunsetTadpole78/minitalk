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
	process_signature(sig, len);
	if (*len == -1)
	{
		kill(info->si_pid, SIGUSR1);
		*len = 0;
		process_element(0, 0, 1);
	}
	else
		kill(info->si_pid, SIGUSR2);
	return (1);
}

void	print_element(char *word, int len)
{
	write(1, "\033[92m»\033[0m ", 12);
	write(1, word, len);
	write(1, "\n", 1);
}

char	*process_element(int len, char c, int type)
{
	static char	*element = NULL;
	static int	pos = 0;

	if (type != 1)
	{
		if (!element)
		{
			element = malloc(sizeof(char) * (len + 1));
			if (!element)
				fail_malloc();
			ft_bzero(element, len);
		}
		if (c && pos < len)
		{
			element[pos++] = c;
			return (element);
		}
		if (pos <= len)
			print_element(element, len);
	}
	free(element);
	element = NULL;
	pos = 0;
	return (NULL);
}

int	on_receive_char(char c, int len, int pos, siginfo_t *info)
{
	if (!c)
	{
		process_element(len, 0, 0);
		return (1);
	}
	else if (pos > len)
	{
		process_element(0, 0, 1);
		kill(info->si_pid, SIGUSR1);
		return (1);
	}
	process_element(len, c, 0);
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
		if (on_receive_char(c, len, pos, info))
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
