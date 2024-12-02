/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:15:29 by lroussel          #+#    #+#             */
/*   Updated: 2024/12/02 11:38:36 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	resend(int type)
{
	static int	value = 0;

	if (type == 1)
		value = 1;
	else if (type == 2)
		value = 0;
	return (value);
}

void	sresend(int sig)
{
	if (sig == SIGUSR1)
		resend(1);
}

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);

		i++;
	}
	return (1);
}
