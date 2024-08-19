#include "minirt.h"

/*
 *	Se usan  '*uno' y '*dos' del type 't_vector3' . Se ha de reservar memoria. 
 *	Se insertan como 'content'  en una 't_list'
 *
 */

void putlst(t_list *lst)
{
	t_vector3	*cont;

	printf("\n--- Lista ---\n");
	while (lst != NULL)
	{
		cont = (t_vector3 *) lst->content;
		printf("(%f, %f, %f)\n", cont->x, cont->y, cont->z);
		lst = lst->next;
	}	
}

void deletecontent(void *content)
{
	t_vector3 *cont;

	cont = (t_vector3 *) content;

	printf("To delete: (%f, %f, %f)\n", cont->x, cont->y, cont->z);
	if(cont)
		free(cont);
}

int	main(void)
{
	t_list		*lst;
	t_list		*newnod;
	t_vector3	*uno;
	t_vector3	*dos;

	uno = (t_vector3 *) ft_calloc(1, sizeof(t_vector3));
	dos = (t_vector3 *) ft_calloc(1, sizeof(t_vector3));
	if (uno && dos)
	{
		printf("uno(%f, %f, %f)\n", uno->x, uno->y, uno->z);
		printf("dos(%f, %f, %f)\n", dos->x, dos->y, dos->z);
		uno->x = 1.0f;
		uno->y = 2.2f;
		uno->z = 3.3f;
		dos->x = 2.0f;
		dos->y = 3.2f;
		dos->z = 4.3f;
		printf("\nuno(%f, %f, %f)\n", uno->x, uno->y, uno->z);
		printf("dos(%f, %f, %f)\n", dos->x, dos->y, dos->z);

		lst = ft_lstnew(uno);		// No manage if lst == NULL;
		newnod = ft_lstnew(dos);	// No manage if newnod == NULL;
		ft_lstadd_back(&lst, newnod);	
		putlst(lst);
		printf("\n--- Delete Lista ---\n");
		ft_lstclear(&lst, deletecontent);
	}
	else
		printf("Calloc ERROR!!!!\n");
	return (0);
}
