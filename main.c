#include "get_next_line.h"

char	*ft_free(char **str)
{
	if (*str)
	{
		//free(*str);
		*str = NULL;
	}
	return (NULL);
}

char	*ft_error(struct s_data_base *file)
{
	file->saved_line_len = 0;
	ft_free(&file->saved_line);
	return (NULL);
}

int	ft_verify_new_line(struct s_data_base *file)
{
	int	i;

	i = 0;
	if (!file->saved_line)
		return (0);
	while (i != file->saved_line_len)
	{
		if (file->saved_line[i] == '\n' || \
		file->saved_line[i] == '\r')
			return (1);
		++i;
	}
	return (0);
}

char	*ft_mem_cpy(char *str, int len)
{
	char	*result;
	int	i;

	i = 0;
	result = NULL;
	result = malloc(sizeof(char) * ((int)len + 1));
	if (!result || !str || len <= 0)
		return (NULL);
	while (i <= len)
		result[i++] = '\0';
	i = 0;
	while (i != len)
		result[i++] = *str++;
	return (result);
}

char	*ft_realloc(char *str1, char *str2, int str1_len, int str2_len)
{
	char	*result;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str1 || !str2)
	{
		if (str1)
			return (ft_mem_cpy(str1, str1_len));
		if (str2)
			return (ft_mem_cpy(str2, str2_len));
		return (NULL);
	}
	result = malloc(sizeof(char) * ((int)(str1_len + str2_len + 1)));
	if (!result)
		return (NULL);
	result[(str1_len + str2_len)] = '\0';
	while (i != str1_len)
		result[i++] = *str1++;
	while (j != str2_len)
		result[i++] = str2[j++];
	return (result);
}

char	*ft_read_line(struct s_data_base *file, int *read_number, int fd)
{
	char	*str_for_realloc;

	str_for_realloc = NULL;
	*read_number = read(fd, file->buffer_line, BUFFER_SIZE);
	if (*read_number < 0)
		return (ft_error(file));
	str_for_realloc = ft_realloc(file->saved_line, file->buffer_line, file->saved_line_len, *read_number);	
	file->saved_line_len = file->saved_line_len + *read_number;
	ft_free(&file->saved_line);
	file->saved_line = str_for_realloc;
	return (file->saved_line);
}

char	*ft_split_lines(struct s_data_base *file)
{
	int	i;
	char	*string_for_db;
	char	*string_result;

	i = 0;
	while (file->saved_line[i] != '\n' && file->saved_line[i] != '\r')
		++i;
	string_result = ft_mem_cpy(file->saved_line, i + 1);
	string_for_db = ft_mem_cpy((file->saved_line + (i + 1)), (file->saved_line_len - (i + 1)));
	file->saved_line_len = file->saved_line_len - (i + 1);
	ft_free(&file->saved_line);
	file->saved_line = string_for_db;
	return (string_result);
}

char	*get_next_line(int fd)
{
	static struct s_data_base	file[OPEN_MAX];
	int							read_number;
	char						*result;

	read_number = 1;
	if (read(fd, 0, 0) < 0 || fd < 0 \
	|| BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (0);
	while (read_number)
	{
		if (ft_verify_new_line(&file[fd]))
			return (ft_split_lines(&file[fd]));
		if (!ft_read_line(&file[fd], &read_number, fd))
			return (0);
	}
	result = ft_mem_cpy(file[fd].saved_line, file[fd].saved_line_len);
	ft_error(&file[fd]);
	return (result);
}
/*
int	main(int argc, char **argv)
{
	char	*file;
	char	*str;
	int		fd;

	file = argv[1];
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	write(1, str, 100);
	str = get_next_line(fd);
	write(1, str, 100);
	//system("leaks -q aoeu");
	return (0);
}
*/
