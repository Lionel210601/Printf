/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwirth <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:11:53 by lwirth            #+#    #+#             */
/*   Updated: 2021/11/22 17:02:08 by lwirth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	*ft_strcpy2(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i++])
		dest[i] = src[i];
	return (dest);
}

size_t	ft_nb_len(int n)
{
	size_t	count;

	count = 0;
	if (n == -2147483648)
		return (count = 11);
	while (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_glitchnormi(int nb, char *str, size_t size)
{
	int	i;

	i = size;
	if (nb == -2147483648)
		ft_strcpy2(str, "-2147483648");
	if (!nb)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		str[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	str[size + 1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;
	int		nb;

	if (n > 2147483647 || n < -2147483648)
		return (NULL);
	size = ft_nb_len(n);
	nb = n;
	str = malloc((sizeof(char) * size) + 1);
	if (!str)
		return (NULL);
	return (ft_glitchnormi(nb, str, size));
}
