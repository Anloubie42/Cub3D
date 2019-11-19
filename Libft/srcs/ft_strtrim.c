/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:47:00 by anloubie          #+#    #+#             */
/*   Updated: 2019/10/17 10:53:38 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <libc.h>

static int		ft_isin(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		else
			i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*dest;

	i = 0;
	len = ft_strlen(s1);
	j = len - 1;
	while (s1[i] && ft_isin(set, s1[i]))
	{
		i++;
		len--;
	}
	while (j >= 0 && ft_isin(set, s1[j]) && len > 0)
	{
		len--;
		j--;
	}
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = 0;
	while (i <= j)
		dest[len++] = s1[i++];
	dest[len] = '\0';
	return (dest);
}
