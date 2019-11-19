/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:51:49 by anloubie          #+#    #+#             */
/*   Updated: 2019/10/17 10:53:38 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*dest;

	nb = n;
	len = ft_len(nb);
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dest[len] = '\0';
	len--;
	if (n == 0)
		dest[0] = '0';
	if (n < 0)
	{
		nb *= -1;
		dest[0] = '-';
	}
	while (nb > 0)
	{
		dest[len] = '0' + (nb % 10);
		nb /= 10;
		len--;
	}
	return (dest);
}
