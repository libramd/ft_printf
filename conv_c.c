/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiakhat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:58:35 by mdiakhat          #+#    #+#             */
/*   Updated: 2021/06/28 16:53:50 by mdiakhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_aligned_left(char c, int largeur, int *count)
{
	int	i;

	i = 0;
	ft_putchar(c, count);
	while (i++ < (largeur - 1))
		ft_putchar(' ', count);
}

static void	ft_zero_len(char c, int largeur, int *count)
{
	int	i;

	i = 0;
	while (i++ < (largeur - 1))
		ft_putchar('0', count);
	ft_putchar(c, count);
}

static void	ft_aligned_right(char c, int largeur, int *count)
{
	int	i;

	i = 0;
	while (i++ < (largeur - 1))
		ft_putchar(' ', count);
	ft_putchar(c, count);
}

void	ft_conv_c(const char *str, va_list ap, int *count)
{
	char	*conv;
	t_bloc	s;
	char	c;

	set_arg_zero(&s);
	conv = ft_copy_conv(str);
	set_arg(conv, &s, ap);
	free(conv);
	c = va_arg(ap, int);
	if (s.moins == 1)
		ft_aligned_left(c, s.largeur, count);
	else if (s.zero == 1)
		ft_zero_len(c, s.largeur, count);
	else if (s.zero == 0 && s.moins == 0)
		ft_aligned_right(c, s.largeur, count);
}
