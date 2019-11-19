/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:48:03 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/19 14:32:38 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int	ft_next_line(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\n')
		i++;
	return (i);
}

char		*ft_line(char *line, char **hold)
{
	char *tmp;

	if (ft_strchr(*hold, '\n'))
	{
		if (!(line = ft_substr(*hold, 0, ft_next_line(*hold))))
			return (NULL);
		tmp = *hold;
		if (!(*hold = ft_substr(tmp, ft_next_line(tmp) + 1, ft_strlen(tmp))))
			return (NULL);
		free(tmp);
	}
	else
	{
		if (!(line = ft_strdup(*hold)))
			return (NULL);
		free(*hold);
		*hold = NULL;
	}
	return (line);
}

int			get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	static char	*hold = NULL;
	char		*tmp;

	if (fd == -1 || !line || BUFFER_SIZE <= 0)
		return (-1);
	ret = 0;
	while (!(ft_strchr(hold, '\n')) && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = hold;
		hold = ft_strjoin(tmp, buf);
		free(tmp);
	}
	if ((ret == -1) || (!(*line = ft_line(*line, &hold))))
		return (-1);
	if (!(hold))
		return (0);
	return (1);
}
