/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:45:06 by anloubie          #+#    #+#             */
/*   Updated: 2019/10/23 15:03:30 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int last;

	i = 0;
	last = 0;
	if ((char)c == '\0')
		return ((char*)s + ft_strlen(s));
	if (s[0] == (char)c)
		return ((char*)s);
	while (s[i])
	{
		if (s[i] == (char)c)
			last = i;
		i++;
	}
	if (last != 0)
		return ((char*)s + last);
	else
		return (NULL);
}
