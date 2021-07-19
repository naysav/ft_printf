#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temporare;

	if (lst && del)
	{
		while (*lst)
		{
			temporare = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = temporare;
		}
	}
}
