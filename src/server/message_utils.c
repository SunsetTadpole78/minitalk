/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:48:26 by lroussel          #+#    #+#             */
/*   Updated: 2024/12/04 09:48:29 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "server.h"

void	print_message(char *word, int len)
{
	write(1, "\033[92m»\033[0m ", 12);
	write(1, word, len);
	write(1, "\n", 1);
}

char	*process_message(int len, char c, int type)
{
	static char	*message = NULL;
	static int	pos = 0;

	if (type != 1)
	{
		if (!message)
		{
			message = malloc(sizeof(char) * (len + 1));
			if (!message)
				fail_malloc();
			ft_bzero(message, len);
		}
		if (c && pos < len)
		{
			message[pos++] = c;
			return (message);
		}
		if (pos <= len)
			print_message(message, len);
	}
	free(message);
	message = NULL;
	pos = 0;
	return (NULL);
}
