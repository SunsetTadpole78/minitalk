/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_printers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:59:28 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/15 20:57:28 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c, int times)
{
	int	i;

	i = 0;
	while (i < times)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int	ft_print_str(char *str, int size)
{
	int	i;

	if (!str)
		return (ft_print_str("(null)", size));
	i = 0;
	while (str[i] && (size < 0 || i < size))
		i += ft_print_char(str[i], 1);
	return (i);
}

int	ft_print_unsigned_int(unsigned int nbr)
{
	int	res;

	res = 0;
	if (nbr > 9)
		res += ft_print_unsigned_int(nbr / 10);
	ft_print_char((nbr % 10) + '0', 1);
	return (res + 1);
}

int	ft_print_hexa(unsigned long value, char type)
{
	int		printed;
	char	*base;

	base = "0123456789abcdef";
	if (type == 'X')
		base = "0123456789ABCDEF";
	printed = 0;
	if (ft_strlen(base) != 16)
		return (0);
	if (value >= 16)
		printed += ft_print_hexa(value / 16, type);
	return (printed + ft_print_char(base[value % 16], 1));
}

int	ft_print_pointer(void *p)
{
	int	printed;

	if (!p)
		return (ft_print_str("(nil)", 5));
	printed = ft_print_str("0x", 2);
	printed += ft_print_hexa((unsigned long)p, 'x');
	return (printed);
}
