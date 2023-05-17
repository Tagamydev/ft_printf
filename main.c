/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:54:20 by samusanc          #+#    #+#             */
/*   Updated: 2023/05/17 19:34:39 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	main()
{
	/*
	char	*s = "ho\nla";
	int	fd;

	fd = open ("get_next_line.c", O_RDONLY);
	s = get_next_line(fd);
	free(s);
	while (s)
	{
		printf("%s", s);
		s = get_next_line(fd);
	}
	*/
	
	int	fd;

	fd = open ("get_next_line.c", O_RDONLY);
	printf("%s", get_next_line(fd));
	
	/*
	char	*db[OPEN_MAX][2];
	char	*s = "hola";
	char	*str = "adeu";
	db[1][0] = s;
	ft_rnw_i("W", db, 1, 4);
	ft_realloc(db, 1, NULL, 0);
	*/
	system("leaks -q aoeu");
}
