/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:59:36 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/16 16:11:50 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed;

	va_start(args, format);
	i = 0;
	printed = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i += (format_switcher(format + i + 1, args, &printed).size + 1);
		else
			printed += ft_print_char(format[i], 1);
		i++;
	}
	va_end(args);
	return (printed);
}

t_data	format_switcher(const char *format, va_list args, int *printed)
{
	t_data	data;

	data = init_data(format, args);
	if (data.type == 'c')
		*printed += (format_char(data, va_arg(args, int)));
	else if (data.type == 's')
		*printed += (format_str(data, va_arg(args, char *)));
	else if (ft_strchr("id", data.type))
		*printed += (format_int(data, va_arg(args, int)));
	else if (data.type == 'u')
		*printed += (format_unsigned_int(data, va_arg(args, unsigned int)));
	else if (data.type == 'p')
		*printed += (format_pointer(data, va_arg(args, void *)));
	else if (ft_strchr("xX", data.type))
		*printed += (format_hexa(data, va_arg(args, unsigned int)));
	else if (data.type == '%')
		*printed += (ft_print_char('%', 1));
	return (data);
}
