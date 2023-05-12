/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:54:20 by samusanc          #+#    #+#             */
/*   Updated: 2023/05/11 21:30:46 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"

int	ft_verify(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n' || s[i] == '\r')
			return (i);
		++i;
	}
	return (-1);
}

char *ft_make_str(char *s, int	*ex, int i, int fd)
{
	s = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!s)
		return (NULL);
	s[BUFFER_SIZE] = '\0';
	if (read (fd, s, BUFFER_SIZE) <= 0)
	{
		free (s);
		return (NULL);
	}
	while (s[i])
		++i;
	if (i < BUFFER_SIZE)
		*ex = 1;
	return (s);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_malcpy(char *str)
{
	char	*s;
	int		i;

	i = 0;
	s = NULL;
	while (str[i])
		++i;
	s = malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	i = 0;
	while (str[i])
	{
		s[i] = str[i];
		++i;
	}
	return (s);
}

char *ft_realloc(char	*s1, char *s2, int i, int j)
{
	char	*s;
	int		x;

	x = 0;
	s = NULL;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	s = malloc (sizeof(char) * (i + j + 1));
	if (!s)
	{
		free (s1);
		free (s2);
		return (NULL);
	}
	s[i + j] = '\0';
	while (x != i)
	{
		s[x] = s1[x];
		++x;
	}
	i = 0;
	while (i != j)
	{
		s[x] = s2[i];
		++i;
		++x;
	}
	free(s1);
	s1 = NULL;
	free(s2);
	s2 = NULL;
	return (s);
}

char	*ft_ch_split(char **db, int fd, int sp)
{
	char	*s;
	char	*r;
	int		i;

	s = NULL;
	i = 0;
	if (sp == -1)
		return (db[fd]);
	s = malloc(sizeof(char) * (sp + 2));
	if (!s)
		return (NULL);
	s[sp + 1] = '\0';
	s[sp] = '\n';
	while (i != sp)
	{
		s[i] = db[fd][i];
		++i;
	}
	r = ft_malcpy((db[fd] + (sp + 1)));
	free(db[fd]);
	if (!r)
		return (NULL);
	db[fd] = NULL;
	if (!*r)
	{
		free(r);
		r = NULL;
	}
	db[fd] = r;
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*db[OPEN_MAX];
	char		*s;
	int			ex;

	ex = 0;
	s = NULL;
	if (fd == -1)
		return (0);
	if (!db[fd])
	{
		db[fd] = ft_make_str(db[fd], &ex, 0, fd);
		if (!db[fd])
			return (0);
	}
	if (!ex)
	{
		while (ft_verify(db[fd]) == -1)
		{
			s = ft_make_str(s, &ex, 0, fd);
			db[fd] = ft_realloc(db[fd], s, \
			ft_strlen(db[fd]), ft_strlen(s));
			if (!db[fd])
				return (NULL);
			if (ex)
				break ;
		}
	}
	return (ft_ch_split(db, fd, ft_verify(db[fd])));
}


int	main()
{
	char	*s = "hola";
	int	fd;

	fd = open ("ain.c", O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		free (s);
		s = get_next_line(fd);
		printf("%s", s);
	}
}
