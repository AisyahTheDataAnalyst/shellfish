/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:43:30 by aimokhta          #+#    #+#             */
/*   Updated: 2025/04/25 13:09:46 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

//static variable = maintain the value from last call
//	- if not initialized, auto to value of 0
//call -> value
//line -> the return
// no need to do below: 
// because if call is already NULL, its as if: free(NULL)
// nothing is needed to be freed
// even though call uses malloc initially
	// if (!line)
	// {
	// 	free(call);
	// 	return (NULL);
	// }
// instead, do like in the function., 
// only free call if call is not null
// to avoid memory leak/undefined behaviour
char	*get_next_line(int fd)
{
	char		*line;
	static char	*call;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	call = ft_reading(fd, call);
	if (!call)
		return (NULL);
	line = ft_extract(call);
	call = ft_storage(call);
	return (line);
}

// ssize_t for edge cases & can be used as counter
// ssize_t has 64/32(depends on system) while int always 32-bits
// behaviour of read -> buffer can be used over&over again 
//  - only need to malloc b4 using read
//  - until you want to do another action, only then free buffer
char	*ft_reading(int fd, char *call)
{
	char	*buffer;
	ssize_t	readline;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	readline = 1;
	while (ft_strchr(call, '\n') == NULL && readline != 0)
	{
		readline = read(fd, buffer, BUFFER_SIZE);
		if (readline == -1)
		{
			free (buffer);
			return (NULL);
		}
		if (readline == 0)
			break ;
		buffer[readline] = '\0';
		call = ft_joining(call, buffer);
	}
	free (buffer);
	return (call);
}

// better practice to not overwrite the call for strjoin
// so, put into temp first, free both s1 & s2, then
// assign back temp to call
// "free both"
// - s1=call , freed in this function as it been used already
// - s2=buffer , already gonna be freed after this in ft_reading fn
// - beware to free only once for each cases, else - undefined behaviour
char	*ft_joining(char *call, char *buffer)
{
	char	*temp;

	temp = ft_strjoin_gnl(call, buffer);
	if (!temp)
	{
		free (call);
		free (buffer);
		return (NULL);
	}
	free (call);
	call = temp;
	return (call);
}

// !call (same) call == NULL
// !*call (same) call[0] == '\0'
// if (!call || !*call)
//
// call[0] == '\0'  ->  even after complete joining all the characters,
//		there will always be '\0' left
// 		'\0' means theres no more printable data
//		'\0' considered as the value ZERO in COMPUTER LANGUAGE
// so that why we need to specifically mention the index, [0]
// therefore,
// if (call[0] == '\0') , return (NULL); 
//
//if (call == NULL) -> NULL means
// - not a valid memory
// - not owner of the location its pointing
// i + 1 => + 1 to include the '\n' too 
char	*ft_extract(char *call)
{
	char	*line;
	int		i;

	if (call == NULL || call[0] == '\0')
		return (NULL);
	i = 0;
	while (call[i] != '\n' && call[i])
		i++;
	if (call[i] == '\n')
		line = ft_substr(call, 0, i + 1);
	else
		line = ft_substr(call, 0, i);
	return (line);
}

char	*ft_storage(char *call)
{
	char	*leftover;
	int		i;

	if (!call || call[0] == '\0')
	{
		free(call);
		return (NULL);
	}
	i = 0;
	while (call[i] && call[i] != '\n')
		i++;
	if (call[i] == '\n')
		leftover = ft_strdup(&call[i + 1]);
	else
		leftover = NULL;
	free (call);
	return (leftover);
}

// return non-zero indicates 
// 		(TRUE / opposite: false) or (ERROR/ opposite: succeed). 
// perror uses errno value (auto) to generate appropiate error message
// perror("Error opening file") = perror("anything you want to put in here")
// errno auto set by open() : "No such file or directory"
// result of perror and read(errno) = 
// 		Error opening file : No such file or directory

// int open(const char *pathname, int flags);
// int close(int fd);
// open, close, printf & perror

// # include <fcntl.h>
// # include <unistd.h>
// # include <stdio.h>
// int	main()
// {
// 	int		fd;
// 	char	*line;

// 	// printf("Opening file\n");
// 	fd = open("test1.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		// printf("[%s]", line);
// 		free (line);
// 		line = get_next_line(fd);
// 	}
// 	// // printf("%s\n", line);
// 	close(fd);
// 	// printf("File closed\n");
// 	return (0);
// }
