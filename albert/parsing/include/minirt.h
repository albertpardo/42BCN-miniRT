#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"


// ------  parsing -------- //

void	exiterror(char *msg);
void	exitifcheckfails(int val, char *msg);
int		ft_isspace(const char c);
char	*cleanStringSpaces(char *str);
void	putArrayStr(char ** arrstr);
void	freeArrStr(char **arr);

#endif
