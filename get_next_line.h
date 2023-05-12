/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:44:16 by samusanc          #+#    #+#             */
/*   Updated: 2023/05/11 20:01:12 by samusanc         ###   ########.fr       */
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

int		ft_verify(char*s);
char	*ft_make_str(char *s, int *ex, int i, int fd);
int		ft_strlen(char *str);
char	*ft_malcpy(char *str);
char	*ft_realloc(char *s1, char *s2, int i, int j);
char	*ft_ch_split(char **db, int fd, int sp);
char	*get_next_line(int fd);

# endif
