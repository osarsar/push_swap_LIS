/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:56:49 by osarsar           #+#    #+#             */
/*   Updated: 2023/04/19 08:02:43 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_max(t_list *stack_a)
{
	t_list	*head;
	t_list	*max;

	head = stack_a->next;
	max = stack_a;
	while (head)
	{
		if (max->content < head->content)
			max = head;
		head = head->next;
	}
	return (max);
}

t_list	*find_min(t_list *stack_a)
{
	t_list	*head;
	t_list	*min;

	head = stack_a->next;
	min = stack_a;
	while (head)
	{
		if (min->content > head->content)
			min = head;
		head = head->next;
	}
	return (min);
}

void	flag_stack(t_list *stack_a)
{
	t_list	*head;
	int		len;
	int		nbr;

	nbr = 0;
	len = size_stack(stack_a);
	head = stack_a;
	if ((len % 2) == 0)
	{
		size_div_2(len, head, nbr);
	}
	if ((len % 2) != 0)
	{
		size_no_div_2(len, head, nbr);
	}
}

void	size_div_2(int len, t_list *head, int nbr)
{
	int	i;

	i = 0;
	while (i < (len / 2))
	{
		head->flag = ++nbr;
		head = head->next;
		i++;
	}
	nbr = nbr * -1;
	while (i < len)
	{
		head->flag = nbr++;
		head = head->next;
		i++;
	}
}

void	size_no_div_2(int len, t_list *head, int nbr)
{
	int	i;

	i = 0;
	while (i <= (len / 2))
	{
		head->flag = ++nbr;
		head = head->next;
		i++;
	}
	nbr--;
	nbr = nbr * -1;
	while (i < len)
	{
		head->flag = nbr++;
		head = head->next;
		i++;
	}
}
