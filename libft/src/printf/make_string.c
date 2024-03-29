/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:34:10 by dromansk          #+#    #+#             */
/*   Updated: 2019/11/05 04:15:26 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "enums.h"

char	*str_to_arg(char *format)
{
	size_t	i;

	i = 0;
	while (format[i] && format[i] != '%' && format[i] != '{')
		i++;
	return (ft_strndup(format, i));
}

int		get_data(va_list *args, char *format, char **buf)
{
	t_flag	*flags;
	int		b;
	char	*fail;

	if (*format == '{')
		return (get_colour(format, buf));
	if (!(flags = (t_flag *)malloc(sizeof(t_flag))) ||
			!initflags(&flags) || !set_flags(&flags, ++format, args))
		return (error_handle(buf));
	if (!check_flag(format))
	{
		format += flag_skip(format);
		fail = ft_strndup(format, 1);
		b = format_string(fail, flags, buf, flags->type);
		free(fail);
	}
	else
		b = parse_arg(flags, args, buf);
	flag_del(&flags);
	return (b);
}

int		putnstr_fd(char **ret, char *str, int fd, size_t len)
{
	if (!ret)
	{
		write(fd, str, len);
		free(str);
	}
	else if (*ret)
	{
		ft_memcpy(*ret, str, ft_strlen(str));
		free(str);
	}
	else
		*ret = str;
	return (len);
}

int		make_string(char **ret, const char *restrict format, va_list *args, int fd)
{
	char	*string;
	char	*buf;
	int		len;
	int		skip;

	string = ft_strnew(0);
	len = 0;
	skip = 0;
	while (*format)
	{
		buf = str_to_arg((char *)format);
		skip = ft_strlen(buf);
		format += skip;
		string = joining(&string, &buf, len, skip);
		len += skip;
		if (!(*format))
			break ;
		skip = get_data(args, (char *)format, &buf);
		string = joining(&string, &buf, len, skip);
		len += skip;
		format++;
		format += flag_skip((char *)format) + 1;
	}
	return (putnstr_fd(ret, string, fd, len));
}
