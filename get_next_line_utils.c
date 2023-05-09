/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:12:09 by samusanc          #+#    #+#             */
/*   Updated: 2023/04/26 17:15:15 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_make_r(char *r, int fd, int *v)
{
	r = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!r)
		return (NULL);
	r[BUFFER_SIZE] = '\0';
	if (read(fd, r, BUFFER_SIZE) < 1)
	{
		free(r);
		r = NULL;
		return (NULL);
	}
	*v = 0;
	return (r);
}

char	*ft_2d_null(char *str)
{
	char	*r;
	int		i;

	i = 0;
	if (str[i])
	{
		while (str[i])
			++i;
		r = malloc(sizeof(char) * (i + 1));
	}
	else
		r = malloc(sizeof(char) * 1);
	if (!r)
		return (NULL);
	r[i] = '\0';
	i = 0;
	while (str[i])
	{
		r[i] = str[i];
		++i;
	}
	return (r);
}

char	*ft_ch_split(char **db, int fd, int i, int y)
{
	char	*h;
	char	*t;

	i = ft_verify(db[fd]);
	t = ft_2d_null(db[fd] + (i + 1));
	h = malloc(sizeof(char) * (i + 2));
	if (!h)
		return (NULL);
	h[i + 1] = '\0';
	h[i] = '\n';
	while (y != i)
	{
		h[y] = db[fd][y];
		++y;
	}
	free(db[fd]);
	db[fd] = NULL;
	if (t[0])
		db[fd] = t;
	else
	{
		free(t);
		db[fd] = NULL;
	}
	return (h);
}

static void	ft_free_naruto(char **db, int fd, char **str)
{
	free(db[fd]);
	db[fd] = NULL;
	free(*str);
	*str = NULL;
}

char	*ft_realloc(char **db, int fd, char *str, int x)
{
	char	*r;
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (db[fd][i])
		++i;
	while (str[y])
		++y;
	r = malloc(sizeof(char) * (i + y + 1));
	if (!r)
		return (NULL);
	r[i + y] = '\0';
	while (db[fd][x])
	{
		r[x] = db[fd][x];
		++x;
	}
	i = 0;
	while (i < y)
		r[x++] = str[i++];
	ft_free_naruto(db, fd, &str);
	return (r);
}
