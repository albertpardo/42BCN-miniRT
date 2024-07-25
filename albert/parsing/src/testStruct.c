#include "minirt.h"

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

	printf("No delete: (%f, %f, %f)\n", cont->x, cont->y, cont->z);
}

int	main(void)
{
	t_list		*lst;
	t_list		*newnod;
	t_vector3	uno;
	t_vector3	dos;

	uno.x = 1.0f;
	uno.y = 2.2f;
	uno.z = 3.3f;

	dos.x = 2.0f;
	dos.y = 3.2f;
	dos.z = 4.3f;

	printf("(%f, %f, %f)\n", uno.x, uno.y, uno.z);
	lst = ft_lstnew(&uno);
	newnod = ft_lstnew(&dos);
	ft_lstadd_back(&lst, newnod);	
	putlst(lst);
	printf("\n--- Delete Lista ---\n");
	ft_lstclear(&lst, deletecontent);
	return (0);
}
