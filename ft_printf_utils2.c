/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiakhat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:20:58 by mdiakhat          #+#    #+#             */
/*   Updated: 2021/06/16 15:31:28 by mdiakhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(char c)
{
	if ((48 <= c) && (c <= 57))
		return (1);
	return (0);
}

int	ft_is_letter(char c)
{
	if (((65 <= c) && (c <= 90)) || ((97 <= c) && (c <= 122)))
		return (1);
	return (0);
}

int	ft_strchr(char *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

int	ft_isconv(char c)
{
	return (ft_strchr("cspdiuxX%", c));
}

int	ft_len_digit(char *str)
{
	int	res;

	res = 0;
	while (ft_isdigit(*str) == 1)
	{
		str++;
		res++;
	}
	return (res);
}
