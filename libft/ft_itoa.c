/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 00:24:38 by mlarra            #+#    #+#             */
/*   Updated: 2021/11/05 14:59:49 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)
{
	int	i;

	i = (n <= 0);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*if_null(char *dest)
{
	dest[0] = '0';
	dest[1] = '\0';
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		minus;
	int		i;

	i = ft_len(n);
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (dest);
	if (n == 0)
		return (if_null(dest));
	minus = 1;
	if (n < 0)
		minus = -1;
	dest[i] = '\0';
	while (n != 0)
	{
		i--;
		dest[i] = (char)((n % 10) * minus + '0');
		n = n / 10;
	}
	if (minus < 0)
		dest[--i] = '-';
	return (dest);
}
