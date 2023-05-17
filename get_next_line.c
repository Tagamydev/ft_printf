/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:54:20 by samusanc          #+#    #+#             */
/*   Updated: 2023/05/17 19:34:34 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"

void	*ft_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

int	ft_rnw_i(char *s, char *db[OPEN_MAX][2], int fd, int i)
{
	if (*s == 'R')
	{
		if (!db[fd][1])
			return (0);
		return ((int)db[fd][1][0]);
	}
	if (*s == 'W')
	{
		if (!db[fd][1])
			db[fd][1] = malloc(sizeof(char) * 1);
		db[fd][1][0] = (char)i;
	}
	return (0);
}

int	ft_verify(char *db[OPEN_MAX][2], int fd)
{
	int	i;

	i = 0;
	if (!db[fd][0])
		return (0);
	while (i != ft_rnw_i("R", db, fd, 0))
	{
		if (db[fd][0][i] == '\n' || db[fd][0][i] == '\r')
			return (1);
		++i;
	}
	return (0);
}

char	*ft_realloc(char *db[OPEN_MAX][2], int fd, char *s, int i)
{
	char	*result;
	int		j;
	int		x;
	int		y;

	x = 0;
	y = 0;
	result = NULL;
	j = ft_rnw_i("R", db, fd, 0);
	result = malloc(sizeof(char) * (i + j + 1));
	if (!result)
		return ((char *)ft_free(&db[fd][0]));
	result[j + i] = '\0';
	while (x != j)
		result[x++] = db[fd][0][y++];
	y = 0;
	while (x != (i + j))
		result[x++] = s[y++];
	ft_free(&db[fd][0]);
	db[fd][0] = result;
	ft_rnw_i("W", db, fd, (j + i));
	return (result);
}

char	*ft_naruto_ch(char *db[OPEN_MAX][2], int fd, int *i, int x)
{
	char	*result;
	char	*strsave;

	if (!x)
	{
		while (db[fd][0][*i] != '\n' && db[fd][0][*i] != '\r')
			*i = *i + 1;
		result = malloc(sizeof(char) * (*i + 1));
		if (!result)
			return ((char *)ft_free(&db[fd][0]));
		return (result);
	}
	else
	{
		strsave = malloc(sizeof(char) * (*i + 1));
		if (!strsave)
			return ((char *)ft_free(&db[fd][0]));
		return (strsave);
	}
}

char	*ft_ch_sp(char *db[OPEN_MAX][2], int fd, int i, int j)
{
	char	*result;
	char	*strsave;
	int		k;

	result = ft_naruto_ch(db, fd, &i, 0);
	if (!result)
		return (0);
	result[i] = '\0';
	while (j <= i)
		result[j++] = db[fd][0][k++];
	i = 0;
	while (k++ != ft_rnw_i("R", db, fd, 0))
		++i;
	strsave = ft_naruto_ch(db, fd, &i, 1);
	if (!strsave)
		return (0);
	strsave[i] = '\0';
	k = 0;
	while (k != i)
		strsave[k++] = db[fd][0][j++];
	ft_rnw_i("W", db, fd, k);
	db[fd][0] = ft_free(&db[fd][0]);
	db[fd][0] = strsave;
	return (result);
}
char	*get_next_line(int fd)
{
	static char	*db[OPEN_MAX][2];
	char		s[BUFFER_SIZE + 1];
	char		*result;
	int			i;

	i = 1;
	result = NULL;
	while(i)
	{
		if (ft_verify(db, fd))
		{
			break ;
		}
		//	return (ft_ch_sp(db, fd, 0, 0));
		i = read(fd, s, BUFFER_SIZE);
		if (i < 0)
			return ((char *)ft_free(&db[fd][0]));
		if (!i)
			break ;
		s[i] = '\0';
		if (!ft_realloc(db, fd, s, i))
			return (0);
	}
	//ft_ch_sp(db, fd, 0, 0);
	printf("%s", db[fd][0]);
	//result = ft_memcpy(db[fd][0], db[fd][1]);
	db[fd][0] = (char *)ft_free(&db[fd][0]);
	return (result);
}

