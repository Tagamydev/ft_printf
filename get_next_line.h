/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:44:16 by samusanc          #+#    #+#             */
/*   Updated: 2023/05/26 18:02:03 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# if !defined (BUFFER_SIZE)
#  define BUFFER_SIZE 4
# endif
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

struct s_data_base {
	char	buffer_line[BUFFER_SIZE + 1];
	char	*saved_line;
	int		saved_line_len;
};

char	*get_next_line(int fd);
# endif
