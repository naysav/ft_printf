#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	if (new != NULL)
	{
		head = *lst;
		if (head == NULL)
			*lst = new;
		else
		{
			while (head->next != NULL)
				head = head->next;
			head->next = new;
		}
	}
}
