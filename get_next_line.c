/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:12:09 by samusanc          #+#    #+#             */
/*   Updated: 2023/04/26 17:17:06 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_verify(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\r')
			break ;
		++i;
	}
	if (!str[i])
		return (-1);
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*db[OPEN_MAX];
	char		*r;
	int			v;

	v = 0;
	r = db[fd];
	if (!r)
	{
		r = ft_make_r(r, fd, &v);
		if (!r)
			return (NULL);
		db[fd] = r;
	}
	while (ft_verify(db[fd]) == -1 && v == 0)
	{
		r = ft_make_r(r, fd, &v);
		if (!r)
			return (NULL);
		r = ft_realloc(db, fd, r, 0);
		if (!r)
			return (NULL);
		db[fd] = r;
	}
	r = ft_ch_split(db, fd, 0, 0);
	if (!r)
		return (NULL);
	return (r);
}
/*
int	main()
{
	int	fd = open("hola", 0);
	char *s = "hola";

	while (s)
	{
		s = get_next_line(fd);
		puts(s);
		free(s);
	}
	free(s);
}
*/
