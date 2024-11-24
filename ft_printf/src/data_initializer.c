/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initializer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:10:08 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/16 16:10:54 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	init_data(const char *format, va_list args)
{
	const char	types[] = "cipdsxXu%";
	int			i;
	t_data		data;

	i = 0;
	init_flags(&data);
	while (!ft_strchr(types, format[i]))
	{
		update_flags(format + i, &data, args);
		i++;
	}
	data.type = format[i];
	data.size = i;
	return (data);
}

void	init_flags(t_data *data)
{
	data->plus = 0;
	data->space = 0;
	data->hashtag = 0;
	data->minus = 0;
	data->zero = 0;
	data->dot = 0;
	data->padding = 0;
	data->elsize = 0;
}

void	update_flags(const char *c, t_data *data, va_list args)
{
	if (*c == '-')
		data->minus = 1;
	else if (*c == '0' && !data->dot && data->padding == 0)
		data->zero = 1;
	else if (*c == '.')
		data->dot = 1;
	else if (*c == '#')
		data->hashtag = 1;
	else if (*c == ' ')
		data->space = 1;
	else if (*c == '+')
		data->plus = 1;
	else if (*c == '*' && !data->dot && data->padding == 0)
		data->padding = va_arg(args, int);
	else if (*c >= '0' && *c <= '9' && !data->dot && data->padding == 0)
		data->padding = ft_abs(ft_mini_atoi((char *)c));
	else if (*c >= '0' && *c <= '9' && data->dot && data->elsize == 0)
		data->elsize = ft_abs(ft_mini_atoi((char *)c));
	else if (*c == '*' && data->dot && data->elsize == 0)
		data->elsize = va_arg(args, int);
	update_values(data);
}

void	update_values(t_data *data)
{
	if (data->padding < 0)
		data->minus = 1;
	if (data->padding < 0)
		data->padding *= -1;
	if (data->elsize < 0)
		data->dot = 0;
}
