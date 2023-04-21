/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:44:16 by samusanc          #+#    #+#             */
/*   Updated: 2023/04/21 20:53:14 by samusanc         ###   ########.fr       */
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

int		ft_verify(char *str);
char	*ft_make_r(char *r, int fd);
char	*ft_2d_null(char *str);
char	*ft_ch_split(char **db, int fd, int i, int y);
char	*ft_realloc(char **db, int fd, char *str, int x);
char	*get_next_line(int fd);
#endif
