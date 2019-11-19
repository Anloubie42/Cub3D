/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:08:46 by anloubie          #+#    #+#             */
/*   Updated: 2019/10/23 14:33:07 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = -1;
	if (!s)
		return (NULL);
	while (s[++i])
		if (s[i] == c)
			return ((char*)s + i);
	if (c == '\0')
		return ((char*)s + i);
	return (NULL);
}
