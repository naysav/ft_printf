#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temporare_node;
	t_list	*result_list;

	result_list = NULL;
	while (lst != NULL && f != NULL)
	{
		temporare_node = ft_lstnew(f(lst->content));
		if (temporare_node == NULL)
		{
			ft_lstclear(&result_list, del);
			break ;
		}
		ft_lstadd_back(&result_list, temporare_node);
		lst = lst->next;
	}
	return (result_list);
}
