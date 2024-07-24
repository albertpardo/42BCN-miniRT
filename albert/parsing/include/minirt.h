#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define	BAD_ARGUMENTS "BAD ARGUMETS. Use : ./minirt NAME.rt"
# define NO_OPEN "open() failed"
# define NO_CLOSE "\nclose() failed" 
# define MALLOC_ERROR "Memory assignament ERROR"

// ------  parsing -------- //

char	*cleanstringspaces(char *str);
void	exiterror(char *msg);
void	exitifcheckfails(int val, char *msg);
void	freeArrStr(char **arr);
int		ft_isspace(const char c);
void	putArrayStr(char ** arrstr);

#endif
