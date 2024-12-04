/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resend_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:35:43 by lroussel          #+#    #+#             */
/*   Updated: 2024/12/03 18:35:44 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "client.h"

void	handle_resend(int sig)
{
	if (sig == SIGUSR1)
		resend(1);
}

int	resend(int type)
{
	static int	value = 0;

	if (type == 1)
		value = 1;
	else if (type == 2)
		value = 0;
	return (value);
}
