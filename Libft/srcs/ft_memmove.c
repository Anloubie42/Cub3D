/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:52:33 by anloubie          #+#    #+#             */
/*   Updated: 2019/10/21 11:31:22 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*ptrd;
	char	*ptrs;

	ptrd = (char*)dst;
	ptrs = (char*)src;
	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			ptrd[i] = ptrs[i];
			i++;
		}
	}
	else
		while (len--)
		{
			ptrd[len] = ptrs[len];
		}
	return (dst);
}
