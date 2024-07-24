#include <stdlib.h>

void	freeArrStr(char **arr)
{
	int i;                                                                  
 	i = 0;   
 	while (arr[i] != NULL)
 		free(arr[i++]);
	free(arr);
}
