/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiakhat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:32:32 by mdiakhat          #+#    #+#             */
/*   Updated: 2021/06/28 16:48:44 by mdiakhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *pointer, int value, size_t size)
{
	char		*ptr;
	size_t		i;

	i = 0;
	ptr = pointer;
	while (i < size)
	{
		ptr[i] = value;
		i++;
	}
	return (pointer);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*pt;

	pt = malloc(count * size);
	if (pt == NULL)
		return (NULL);
	ft_memset(pt, '\0', count * size);
	return (pt);
}
void	ft_free_str(char *str)
{
	free(str);
	str = NULL;
}

void	ft_poulet(t_bloc *s, const char *str, va_list ap)
{
	char	*conv;

	set_arg_zero(s);
	conv = ft_copy_conv(str);
	set_arg(conv, s, ap);
	free(conv);
}
