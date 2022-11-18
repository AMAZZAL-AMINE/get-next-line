/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:16:00 by mamazzal          #+#    #+#             */
/*   Updated: 2022/11/18 15:11:45 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		c;
	char	*str;

	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = 0;
	}
	i = 0;
	c = 0;
	if (s1)
	{
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
		while (s2[c] != '\0')
			str[i++] = s2[c++];
		str[i] = '\0';
	}
	free(s1);
	return (str);
}

char	*server_read_(int fd)
{
	static char	*mysql[OPEN_MAX];
	char		*readline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	mysql[fd] = ft_insert_to_mysql(fd, mysql[fd]);
	if (!mysql[fd])
		return (NULL);
	readline = count_len_tell_newline(mysql[fd]);
	mysql[fd] = update_own_mysql(mysql[fd]);
	return (readline);
}
