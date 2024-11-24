/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:13:04 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/15 21:27:06 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_log(int long nb, int len)
{
	if (nb < 0)
		nb = -nb;
	if (nb < len)
		return (1);
	return (1 + ft_log(nb / len, len));
}

int	ft_hexalen(unsigned long nbr)
{
	int	count;

	count = 0;
	while (nbr >= 16 || nbr % 16 != 0)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}

int	ft_pointerlen(void *p)
{
	if (!p)
		return (5);
	return (ft_hexalen((unsigned long)p) + 2);
}
