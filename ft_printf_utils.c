/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiakhat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:45:54 by mdiakhat          #+#    #+#             */
/*   Updated: 2021/06/20 21:33:13 by mdiakhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(char *str)
{
	int	neg;
	int	i;
	int	num;

	i = 0;
	neg = 1;
	num = 0;
	if (!str)
		return (0);
	if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	*count = *count + 1;
}

void	ft_putstr(char *str, int *count)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			ft_putchar(str[i], count);
			i++;
		}
	}
}

void	ft_putnbr(int nb, int *count)
{
	long	x;

	x = nb;
	if (x < 0)
	{
		x = x * -1;
		ft_putchar('-', count);
	}
	if (x > 9)
	{
		ft_putnbr(x / 10, count);
		ft_putnbr(x % 10, count);
	}
	else
	{
		ft_putchar(x + '0', count);
	}
}
