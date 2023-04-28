/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:07:08 by osarsar           #+#    #+#             */
/*   Updated: 2023/04/27 19:59:39 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_valid_stack(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			i++;
			if (str[i] <= '0' || str[i] >= '9')
				message_error();
		}
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] != ' ' && str[i])
			message_error();
		i++;
	}
	return (1);
}

void	check_same_number(t_list	*stack_a)
{
	t_list	*head;
	t_list	*head_1;

	head = stack_a;
	head_1 = stack_a->next;
	while (head->next)
	{
		head_1 = head->next;
		while (head_1)
		{
			if (head->content == head_1->content)
			{
				ft_putstr_fd("Error4", 2);
				exit(1);
			}
			head_1 = head_1->next;
		}
		head = head->next;
	}
}

int	size_stack(t_list *stack_a)
{
	t_list	*head;
	int		i;

	i = 0;
	head = stack_a;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

void	final_tri_stack(t_list **stack_a)
{
	t_list	*min;
	int		temp;

	min = find_min(*stack_a);
	flag_stack(*stack_a);
	temp = min->flag;
	if (temp > 0)
	{
		while (temp > 1)
		{
			ra(stack_a);
			write(1, "ra\n", 3);
			temp--;
		}
	}
	if (temp < 0)
	{
		temp = temp * -1;
		while (temp >= 1)
		{
			rra(stack_a);
			write(1, "rra\n", 4);
			temp--;
		}
	}
}

void	check_sort(t_list *stack_a)
{
	t_list	*head;
	int		i;

	i = 0;
	head = stack_a;
	size_stack(stack_a);
	head = stack_a;
	while (head->next)
	{
		if (head->content < head->next->content)
			i++;
		head = head->next;
	}
	if (i == size_stack(stack_a) - 1)
		exit(0);
}
