/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:56:59 by osarsar           #+#    #+#             */
/*   Updated: 2023/04/28 23:21:10 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	while (!check_index(*stack_a))
	{
		flag_stack(*stack_a);
		// t_list *head1 = *stack_a;
		// while (head1)
		// {
		// 	printf("a = %d\n",head1->flag);
		// 	head1 = head1->next;
		// }
		tmp = *stack_a;
		while (tmp->index == -1)
			tmp = tmp->next;
		//printf("tmp = %d\n", tmp->content);
		while ((*stack_a)->index == -1)
		{
			if (tmp->flag > 0)
			{
				ra(stack_a);
				write(1, "ra\n", 3);
			}
			else if (tmp->flag < 0)
			{
				rra(stack_a);
				write(1, "rra\n", 4);
			}
		}
			pb(stack_b, stack_a);
			write(1, "pb\n", 3);
	}
}

t_list	*tri_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*tab[4];
	int		i;
	int		size_b;
	int old;
	// int	temp;
	t_list *tmp;
	t_list *min;
	t_list *max;
	i = 0;
	size_b = size_stack(*stack_b);
	while (i < size_b)
	{
		// t_list *head1 = *stack_a;
		// while (head1)
		// 	{
		// 		printf("a = %d\n",head1->content);
		// 		head1 = head1->next;
		// 	}
		tab[2] = *stack_a;
		tab[3] = *stack_b;
		tab[3]->min = 2147483647;
		old = tab[3]->min;
		while (tab[3])
		{
			flag_stack(*stack_a);
			flag_stack(*stack_b);
			tab[0] = find_min(*stack_a);
			tab[1] = find_max(*stack_a);
			if (tab[3]->content > tab[1]->content)
			{
				tmp = tab[0];
			}
			else if (tab[3]->content < tab[1]->content)
			{
				tab[0] = tab[1];
				tab[2] = put_flags_to_stack(&tab[2], &tab[0], &tab[3], stack_a);
				tmp = tab[0];
			}
			if (tab[3]->flag < 0)
				tab[3]->min = abs(tab[3]->flag) + abs(tmp->flag) - 1;
			else
				tab[3]->min = abs(tab[3]->flag) + abs(tmp->flag) - 2;
			if (tab[3]->min < old)
			{
				old = tab[3]->min;
				min = tab[3];
				max = tmp;
			}
			tab[3] = tab[3]->next;
				//printf("temp = %d\n",min->content);
		}
		tab[3] = min;
		if (tab[3]->flag > 0)
		{
			while (tab[3]->flag > 1)
			{
				rb(stack_b);
				write(1, "rb\n", 3);
				tab[3]->flag--;
			}
		}
		if (tab[3]->flag < 0)
		{
			tab[3]->flag = tab[3]->flag * -1;
			while (tab[3]->flag >= 1)
			{
				rrb(stack_b);
				write(1, "rrb\n", 4);
				tab[3]->flag--;
			}
		}
		// t_list *head1 = *stack_b;
		// while (head1)
		// 	{
		// 		printf("b = %d\n",head1->content);
		// 		head1 = head1->next;
		// 	}
		flag_stack(*stack_a);
		tab[0] = find_min(*stack_a);
		tab[1] = find_max(*stack_a);
		tab[2] = *stack_a;
		tab[3] = *stack_b;
		if (tab[3]->content > tab[1]->content)
			{
				tmp = tab[0];
			}
			else if (tab[3]->content < tab[1]->content)
			{
				tab[0] = tab[1];
				put_flags_to_stack(&tab[2], &tab[0], &tab[3], stack_a);
				tmp = tab[0];
			}
		//t_list *head1 = *stack_a;
		// while (head1)
		// {
		// 	printf("a = %d\n",head1->content);
		// 	head1 = head1->next;
		// }
		// head1 = *stack_b;
		// while (head1)
		// {
		// 	printf("b = %d\n",head1->content);
		// 	head1 = head1->next;
		// }
		ft_temp(tmp->flag, stack_a, stack_b);
		i++;
	}
	return(*stack_a);
}

void	ag(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] == ' ')
		j++;
		if (str[i][j] == '\0')
			message_error();
		i++;
	}
}
