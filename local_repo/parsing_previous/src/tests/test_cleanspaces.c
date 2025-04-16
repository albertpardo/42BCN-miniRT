#include "minirt.h"

static void callcleanspaces(char *str)
{
	char	*cleanline;

	cleanline = cleanstringspaces(str);
	ft_printf("--------------------------------------------\n");
	ft_printf("Linea Original  >%s", str);
	ft_printf("Del extra spaces>%s\n", cleanline);
	free(cleanline);
}

int	main(void)
{
	ft_printf("==========  TESTS WITH ONLY ONE SPACE ========\n");
	callcleanspaces("0- -\n");
	callcleanspaces("A A A,A,A\n");
	callcleanspaces("B 1 1,1,1\n");
	callcleanspaces("C -1 -1,-1,+1 +1 =1.0\n");
	callcleanspaces("D a.A A,A,A +a -e.0\n");
	callcleanspaces("E <>\n");
	callcleanspaces("F 0.2 255,255,255\n");
	callcleanspaces("G 0.2 ,, , , ... . \n");
	callcleanspaces("H 0.2 2.,2,2 1,1.0,2 3.a \n");
	ft_printf("\n==========  TESTS WITH SEVERAL SPACES ========\n");
	callcleanspaces("A     A A  ,  A   ,   A    \n");
	callcleanspaces("        c 0 ,2   . 5	, -10  	   0 , 0    , 	   1		65	    \n");
	callcleanspaces("        c 0 ,2   . 5	, -  10  	   0 , 0    , 	   1		65	    \n");
	callcleanspaces(" s 0	 ,2	  . 5	 , 		-10   	  0 ,	 0    ,  	     -1 	+65\n");
	callcleanspaces("	G	 0.2 ,	, , , .	   .   .    . 	* ( )( \n");
	callcleanspaces("		H 0	. 2 2. ,2	,	2 1,1.0,2 3 .	 a, P A \n");
	return (0);
}
