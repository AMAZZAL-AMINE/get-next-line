/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:00:50 by mamazzal          #+#    #+#             */
/*   Updated: 2022/11/08 13:41:26 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*update_own_mysql(char *sql)
{
	char	*database;
	int		count;
	int		c;

	count = 0;
	while (sql[count] != '\n' && sql[count] != '\0')
		count++;
	if (!sql[count])
	{
		free(sql);
		return (NULL);
	}
	database = malloc((ft_strlen(sql) - count + 1) * sizeof(char));
	if (!database)
		return (NULL);
	c = 0;
	count++;
	while (sql[count] != '\0')
		database[c++] = sql[count++];
	database[c] = '\0';
	free(sql);
	return (database);
}

int	select_true_where_found_newline(char *sql)
{
	int	count;

	count = 0;
	while (1)
	{
		if (sql[count])
		{
			if (sql[count] == '\n')
			{
				return (1);
			}
			count++;
		}
		else
			break ;
	}
	return (0);
}

char	*count_len_tell_newline(char *sql)
{
	char	*dest;
	int		count;
	int		countdest;

	count = 0;
	while (sql[count] != '\n' && sql[count] != '\0')
		count++;
	if (sql[0] == 0)
		return (NULL);
	dest = malloc((count + 2) * sizeof(char));
	if (!dest)
		return (NULL);
	countdest = 0;
	while (sql[countdest] != '\n' && sql[countdest] != '\0')
	{
		dest[countdest] = sql[countdest];
		countdest++;
	}
	if (sql[countdest] == '\n')
	{
		dest[countdest] = '\n';
		countdest++;
	}
	dest[countdest] = '\0';
	return (dest);
}

char	*ft_insert_to_mysql(int fd, char *mysql)
{
	int			bs;
	char		buff[BUFFER_SIZE + 1];

	bs = read(fd, buff, BUFFER_SIZE);
	while (1)
	{
		if (bs != 0)
		{
			if (bs < 0)
			{
				free(mysql);
				mysql = NULL;
				break ;
			}
			buff[bs] = '\0';
			mysql = ft_strjoin(mysql, buff);
			if (select_true_where_found_newline(buff))
				break ;
			bs = read(fd, buff, BUFFER_SIZE);
		}
		else
			break ;
	}
	return (mysql);
}

char	*get_next_line(int fd)
{
	return (server_read_(fd));
}
