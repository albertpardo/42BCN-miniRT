/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:04:35 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/23 15:18:48 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	freenull(char **p)
{
	free(*p);
	*p = NULL;
}

static ssize_t	readfile( int fd, char **posn, char **buf, char *fdbuffer )
{
	char	*aux;
	ssize_t	numbytes;

	numbytes = 1;
	*posn = ft_strchr(*buf, '\n');
	while (*posn == NULL && numbytes > 0)
	{
		numbytes = read(fd, fdbuffer, BUFFER_SIZE);
		if (numbytes > 0)
		{
			fdbuffer[numbytes] = '\0';
			aux = ft_strjoin(*buf, fdbuffer);
			if (aux != NULL)
			{
				free(*buf);
				*buf = aux;
				*posn = ft_strchr(*buf, '\n');
			}
			else
				numbytes = -1;
		}
	}
	return (numbytes);
}

static int	islineinbuffer(int fd, char **buf)
{
	char	*fdbuffer;
	char	*posn;
	ssize_t	numbytes;
	int		answer;

	answer = 0;
	posn = NULL;
	numbytes = -1;
	fdbuffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fdbuffer != NULL)
	{
		numbytes = readfile(fd, &posn, buf, fdbuffer);
		free(fdbuffer);
	}
	if (posn != NULL)
		answer = 1;
	else if (fdbuffer == NULL || numbytes == -1)
		freenull(buf);
	return (answer);
}

static char	*getlinebuf(char *posn, char **buf)
{
	char	*aux;
	char	*line;

	aux = ft_strdup((posn + 1));
	*(posn + 1) = '\0';
	line = ft_strdup(*buf);
	if (aux != NULL && line != NULL)
	{
		freenull(buf);
		*buf = aux;
	}
	else
	{
		free(aux);
		freenull(&line);
		freenull(buf);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*posn;

	line = NULL;
	posn = NULL;
	if (fd > -1 && BUFFER_SIZE > -1)
	{
		if (islineinbuffer(fd, &buffer))
			posn = ft_strchr(buffer, '\n');
		if (posn != NULL && *(posn + 1) != '\0')
			line = getlinebuf(posn, &buffer);
		else if ((posn != NULL && *(posn + 1) == '\0') || buffer != NULL)
		{
			line = buffer;
			buffer = NULL;
		}
	}
	return (line);
}
