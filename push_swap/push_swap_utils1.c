/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:26:54 by osarsar           #+#    #+#             */
/*   Updated: 2023/04/28 01:53:18 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	longest_increasing_subsequence(t_list *stack_a)
{
	t_list	*head_i;
	t_list	*head_j;

	head_i = stack_a->next;
	while (head_i)
	{
		head_j = stack_a;
		while (head_j != head_i)
		{
			if (head_j->content < head_i->content)
			{
				if (head_j->index + 1 > head_i->index)
					head_i->index = head_j->index + 1;
			}
			head_j = head_j->next;
		}
		head_i = head_i->next;
	}
}

int	max_subsequence(t_list *stack_a)
{
	t_list	*head;
	int		max;

	head = stack_a;
	max = head->index;
	while (head->next)
	{
		if (max < head->next->index)
			max = head->next->index;
		head = head->next;
	}
	return (max);
}

int	ft_list_size(t_list *stack_a)
{
	t_list	*head;
	int		i;

	i = 0;
	head = stack_a;
	while (head)
	{
		if (head->index == -1)
			i++;
		head = head->next;
	}
	return (i);
}

void	add_minus_one(t_list *stack_a, int len)
{
	t_list	*head;
	t_list	*max;
	int		i;

	head = stack_a;
	max = NULL;
	i = len;
	while (head)
	{
		if (head->index == i)
		{
			head->index = -1;
			max = head;
			i--;
			break ;
		}
		head = head->next;
	}
	put_flags(stack_a, len, i, max);
}

void	put_flags(t_list *stack_a, int len, int i, t_list *max)
{
	t_list	*head;

	head = stack_a;
	while (ft_list_size(head) != len)
	{
		while (head)
		{
			if (head->index == i && head->content < max->content)
			{
				head->index = -1;
				max = head;
				i--;
				break ;
			}
			head = head->next;
		}
		head = stack_a;
	}
}
