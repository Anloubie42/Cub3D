/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:17:03 by anloubie          #+#    #+#             */
/*   Updated: 2019/10/17 10:53:38 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_test(const char *haystack, const char *needle, size_t len,
				size_t count)
{
	while (*needle)
	{
		if (*haystack == *needle)
		{
			haystack++;
			needle++;
			count++;
		}
		else
			return (0);
	}
	if (count <= len)
		return (1);
	else
		return (0);
}

char			*ft_strnstr(const char *haystack, const char *needle,
				size_t len)
{
	size_t	count;

	count = 0;
	if (!*needle)
		return (char *)(haystack);
	while (*haystack && *needle && count < len)
	{
		while (*haystack && *needle && *haystack != *needle && count < len)
		{
			haystack++;
			count++;
		}
		if (*haystack == *needle)
		{
			if (ft_test(haystack, needle, len, count) && (count < len))
				return ((char *)haystack);
			else
			{
				haystack++;
				count++;
			}
		}
	}
	return (NULL);
}
