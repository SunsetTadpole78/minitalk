/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_formatter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:16:21 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/16 18:26:53 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_char(t_data data, char c)
{
	int	printed;

	printed = 0;
	if (!data.minus)
		printed += ft_print_char(' ', data.padding - 1);
	printed += ft_print_char(c, 1);
	if (data.minus)
		printed += ft_print_char(' ', data.padding - 1);
	return (printed);
}

int	format_str(t_data data, char *str)
{
	int	printed;
	int	len;

	if (!str)
	{
		str = "";
		if (!data.dot || data.elsize >= 6)
			str = "(null)";
	}
	len = ft_strlen(str);
	if (data.dot && data.elsize < len)
		len = data.elsize;
	printed = 0;
	if (!data.minus)
		printed += ft_print_char(' ', data.padding - len);
	printed += ft_print_str(str, len);
	if (data.minus)
		printed += ft_print_char(' ', data.padding - len);
	return (printed);
}

int	format_int(t_data data, long int nbr)
{
	int	printed;
	int	len;

	printed = 0;
	len = ft_log(nbr, 10);
	if (data.dot && ((data.elsize > len) || (data.elsize == 0 && nbr == 0)))
		len = data.elsize;
	data.zero &= !(data.dot || data.minus);
	data.space &= !data.plus;
	printed += ft_print_char(' ', nbr >= 0 && data.space);
	if (!data.minus && data.padding > 0 && !data.zero)
		printed += ft_print_char(' ', data.padding - (len + printed
					+ (nbr < 0 || data.plus || data.space)));
	printed += ft_print_char('-', nbr < 0);
	printed += ft_print_char('+', nbr >= 0 && data.plus);
	if (data.zero && data.padding - printed > len)
		len = data.padding - printed;
	printed += ft_print_char('0', len - ft_log(nbr, 10));
	if (len != 0)
		printed += ft_print_unsigned_int(ft_abs(nbr));
	if (data.minus && data.padding > printed)
		printed += ft_print_char(' ', data.padding - printed);
	return (printed);
}

int	format_unsigned_int(t_data data, unsigned int nbr)
{
	int	printed;
	int	len;

	printed = 0;
	len = ft_log(nbr, 10);
	if (data.dot && ((data.elsize > len) || (data.elsize == 0 && nbr == 0)))
		len = data.elsize;
	data.zero &= !(data.dot || data.minus);
	if (!data.minus && data.padding > (len + printed) && !data.zero)
		printed += ft_print_char(' ', data.padding - (len + printed));
	if (data.zero && data.padding > printed + len)
		len = data.padding - printed;
	printed += ft_print_char('0', len - ft_log(nbr, 10));
	if (len != 0)
		printed += ft_print_unsigned_int(nbr);
	if (data.minus && data.padding > printed)
		printed += ft_print_char(' ', data.padding - printed);
	return (printed);
}
