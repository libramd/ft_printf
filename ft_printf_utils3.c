/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiakhat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:07:01 by mdiakhat          #+#    #+#             */
/*   Updated: 2021/06/21 12:09:24 by mdiakhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_conv(const char *str)
{
	int	i;

	i = 0;
	while (ft_isconv(*str) != 1)
	{
		str++;
		i++;
	}
	i++;
	return (i);
}

char	*ft_copy_conv(const char *str)
{
	char		*res;
	const char	*tmp;
	int			i;

	i = 0;
	tmp = str;
	res = malloc(sizeof(char) * ft_len_conv(str) + 1);
	if (!res)
		return (NULL);
	while (ft_isconv(*str) == 0)
	{
		res[i] = *str;
		i++;
		str++;
	}
	res[i] = *str;
	i++;
	res[i] = '\0';
	return (res);
}

char	ft_defconv(const char *str)
{
	while (*str)
	{
		if (ft_isconv(*str) == 1)
			return (*str);
		str++;
	}
	return ('\0');
}

void	ft_carrefour(const char *str, va_list ap, int *count)
{
	char	c;

	c = ft_defconv(str);
	if (c == 'c')
		ft_conv_c(str, ap, count);
	else if (c == 's')
		ft_conv_s(str, ap, count);
	else if (c == 'p')
		ft_conv_p(str, ap, count);
	else if (c == 'd')
		ft_conv_d(str, ap, count);
	else if (c == 'i')
		ft_conv_d(str, ap, count);
	else if (c == 'u')
		ft_conv_u(str, ap, count);
	else if (c == 'x')
		ft_conv_x(str, ap, count);
	else if (c == 'X')
		ft_conv_xup(str, ap, count);
}
