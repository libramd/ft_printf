/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiakhat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:05:41 by mdiakhat          #+#    #+#             */
/*   Updated: 2021/06/16 15:32:12 by mdiakhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	size_t	i2;
	char	*res;

	len = 0;
	i2 = 0;
	while (src[len])
	{
		len++;
	}
	res = malloc((sizeof(char) * len) + 1);
	if (res == NULL)
		return (NULL);
	while (src[i2] != '\0')
	{
		res[i2] = src[i2];
		i2++;
	}
	res[i2] = '\0';
	return (res);
}

int	ft_intlen(int nb)
{
	size_t	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

void	bouba(int *nb, size_t *taille_nb)
{
	if (*nb < 0)
		*taille_nb = *taille_nb + 1;
}

size_t	ft_is_neg(int nb)
{
	if (nb < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int nb)
{
	char	*res;
	size_t	taille_nb;
	size_t	i;

	taille_nb = ft_intlen(nb);
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	bouba(&nb, &taille_nb);
	res = malloc(sizeof(char) * taille_nb + 1);
	if (!res)
		return (NULL);
	i = ft_is_neg(nb);
	if (nb < 0)
	{
		res[0] = '-';
		nb = nb * -1;
	}
	res[taille_nb] = '\0';
	while (i < taille_nb--)
	{
		res[taille_nb] = 48 + (nb % 10);
		nb = nb / 10;
	}
	return (res);
}
