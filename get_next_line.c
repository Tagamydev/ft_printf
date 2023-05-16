/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:54:20 by samusanc          #+#    #+#             */
/*   Updated: 2023/05/16 16:57:22 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"
// recibe un fd y devuelve la linea leida en forma de string, reservada con malloc
void	*ft_free(char *str)
{
	if (str)
		free(str);
	return (NULL);
}

int	ft_verify(char *db[OPEN_MAX][2], int fd)
{
	int	i;

	i = 0;
	if (!db[fd][0])
		return (0);
	//while (i != (int)db[fd][1])
	while (db[fd][1][i])
	{
		if(db[fd][0][i] == '\n' || db[fd][0][i] == '\r')
		{
			return (1);
		}
		++i;
	}
	return (0);
}

char	*ft_ch_sp(char *db[OPEN_MAX][2], int fd)
{
	char	*result;
	int		i;
	int		j;

	result = NULL;
	i = 0;
	j = 0;
	while (db[fd][0][i] != '\n' && db[fd][0][i] != '\r')
		++i;
	printf("%d", db[fd][0][i]);	
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
	{
		//db[fd][0] = ft_free(db[fd][0]);
		return (0);
	}
	result[i] = '\0';
	while ()
	{
	
	}
	//db[fd][0] = ft_free(db[fd][0]);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*db[OPEN_MAX][2];
	char	s[BUFFER_SIZE + 1];
	char	*result;
	int	i;

	i = 1;
	result = NULL;
	while(i)
	{
		if (ft_verify(db, fd))
		{
			return (ft_ch_sp(db, fd));
		}
		i = read(fd, s, BUFFER_SIZE);
		if (i < 0)
		{
			db[fd][0] = (char *)ft_free(db[fd][0]);
			return (0);
		}
		if (!i)
			break ;
		s[i] = '\0';
		//db[fd][0] = ft_realloc(db, fd, s, i);
	}
	//result = ft_memcpy(db[fd][0], db[fd][1]);
	db[fd][0] = (char *)ft_free(db[fd][0]);
	return (result);
}

