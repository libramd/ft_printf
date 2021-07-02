/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiakhat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 14:19:32 by mdiakhat          #+#    #+#             */
/*   Updated: 2021/07/02 15:38:17 by mdiakhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

void	set_arg_zero(t_bloc *s)
{
	s->moins = 0;
	s->zero = 0;
	s->largeur = 0;
	s->precision = -1;
}

void	set_larg_prec(va_list ap, char *str, t_bloc *s)
{

	if (ft_isdigit(*str) == 1)
	{
		if (s->precision == -1)
			s->largeur = s->largeur * 10 + *str - '0';
		else
			s->precision = s->precision * 10 + *str - '0';
	}
	else if (*str == '*')
	{
		if (s->precision == -1)
		{
			s->largeur = va_arg(ap, int);
			if (s->largeur < 0)
			{
				s->moins = 1;
				s->largeur *= -1;
			}
		}
		else
			s->precision = va_arg(ap, int);
	}
}

void	set_arg(char *str, t_bloc *s, va_list ap)
{
	while (ft_is_letter(*str) == 0)
	{
		if (*str == '-')
			s->moins = 1;
		else if ((*str == '0') && s->largeur == 0 && s->precision == -1)
			s->zero = 1;
		else if (*str == '.')
			s->precision = 0;
		else if (ft_isdigit(*str) == 1 || *str == '*')
			set_larg_prec(ap, str, s);
		str++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;
	int		test;

	va_start(ap, str);
	test = 0;
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
				ft_putchar(*str, &test);
			else
				ft_carrefour(str, ap, &test);
			str = str + ft_len_conv(str);
		}
		else
			ft_putchar(*str++, &test);
	}
	va_end(ap);
	return (test);
}
/*
int	main(int j, ...)
{
	va_list ap;
	t_bloc	s;
	char	*test = ".4s";
	int	g = 40;
	int i;
	int	i2;

	va_start(ap, j);
	set_arg_zero(&s);
	set_arg(ft_copy_conv(test), &s, ap);
	printf("Zero : %d\nMoins : %d\nLargeur : %d\nPrecision : %d\n\n", s.zero, s.moins, s.largeur, s.precision);

	i = printf("P-> J'ai%*.4s %.4sans\n", 10, "123", "4567");
	i2 = ft_printf("M-> J'ai%*.4s %.4sans\n", 10, "123", "4567");
	printf("%d\n", i);
	printf("%d\n", i2);
	va_end(ap);
}*/
