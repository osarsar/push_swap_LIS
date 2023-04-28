/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:58:45 by osarsar           #+#    #+#             */
/*   Updated: 2023/04/28 23:21:41 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int abs(int x)
{
	if (x < 0)
		return(-x);
	return(x);
}

void	ft_temp(int temp, t_list **stack_a, t_list **stack_b)
{
	// t_list *tmp;
	// int min;
	flag_stack(*stack_b);
	// tmp = *stack_b;
	// while (tmp)
	// {
	// 	min = abs(tmp->flag) + abs(tab->flag);
	// 	printf("min = %d\n", min);
	// 	tmp = tmp->next;
	// }
	// if((*stack_b)->content == 727)
	// printf("temp = %d\n", temp);
	if (temp > 0)
	{
		while (temp > 1)
		{
			ra(stack_a);
			write(1, "ra\n", 3);
			temp--;
		}
		pa(stack_a, stack_b);
		write(1, "pa\n", 3);
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
		pa(stack_a, stack_b);
		write(1, "pa\n", 3);
	}
}

t_list	*put_flags_to_stack(t_list **head, t_list **max, t_list **b, t_list **a)
{
	while (*head)
	{
		flag_stack(*a);
		if ((*head)->content > (*b)->content
			&& (*head)->content < (*max)->content)
			*max = *head;
		*head = (*head)->next;
	}
	return (*a);
}

// void	tri_stack_b(t_list **stack_a, t_list **stack_b, int j)
// {
// 	t_list	*tab[4];
// 	int		i;
// 	int		temp;
// 	t_list	*tmp;

// 	i = 0;

// 	push_b(stack_a, stack_b);
// 	push_b(stack_a, stack_b);
// 	while (i < j - 2)
// 	{
// 		flag_stack(*stack_b);
// 		tmp = *stack_a;
// 		while (tmp->index == -1)
// 		tmp = tmp->next;
// 		while ((*stack_a)->index == -1)
// 		{
// 			if (tmp->flag > 0)
// 			{
// 				ra(stack_a);
// 				write(1, "ra\n", 3);
// 			}
// 			else if (tmp->flag < 0)
// 			{
// 				rra(stack_a);
// 				write(1, "rra\n", 4);
// 			}
// 		}
// 		tab[0] = find_min(*stack_b);
// 		tab[1] = find_max(*stack_b);
// 		tab[2] = *stack_b;
// 		tab[3] = *stack_a;
// 		flag_stack(*stack_b);
// 		if (tab[3]->content > tab[1]->content)
// 			temp = tab[0]->flag;
// 		else if (tab[3]->content < tab[1]->content)
// 		{
// 			tab[0] = tab[1];
// 			tab[2] = put_flags_to_stack(&tab[2], &tab[0], stack_b, stack_a);
// 			temp = tab[0]->flag;
// 		}
// 		ft_temp(temp, stack_b, stack_a);
// 		i++;
// 	}
// }

int	number_no_flaged(t_list *stack_a)
{
	t_list	*head;
	int		i;

	i = 0;
	head = stack_a;
	while (head)
	{
		if (head->index != -1)
			i++;
		head = head->next;
	}
	return(i);
}

char	**split_stack(char **av)
{
	int		i;
	char	*string;
	char	**split;

	string = ft_strdup("");
	i = 1;
	while (av[i])
	{
		string = ft_strjoin1(string, av[i]);
		string = ft_strjoin1(string, " ");
		i++;
	}
	i = 0;
	split = ft_split(string, ' ');
	check_valid_stack(string);
	free(string);
	return (split);
}

int	creat_stack(t_list	*stack_a, char **split)
{
	t_list	*tab;
	int		i;

	i = 0;
	while (split[i])
	{
		tab = ft_lstnew(ft_atoi(split[i]));
		ft_lstadd_back(&stack_a, tab);
		free(split[i]);
		i++;
	}
	return (i);
}

int	check_index(t_list *stack_a)
{
	int		i;
	t_list	*head;

	i = 0;
	head = stack_a;
	while (head)
	{
		if (head->index != -1)
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_norm(t_list *head, t_list **stack_a, t_list **stack_b)
{
	int		len;
	// t_list *head2;

	len = max_subsequence(head);
	add_minus_one(head, len);
	push_b(stack_a, stack_b);
	tri_stack(stack_a, stack_b);
	final_tri_stack(stack_a);
	//tri_stack_b(stack_a, stack_b, number_no_flaged(*stack_a));
	//final_tri_stack(stack_a);
}

int	main(int ac, char **av)
{
	t_list	*stack_b;
	t_list	*stack_a;
	t_list	*tmp;
	char	**split;

	stack_b = NULL;
	if (ac >= 2)
	{
		ag(av);
		stack_a = ft_lstnew(42);
		split = split_stack(av);
		creat_stack(stack_a, split);
		free(split);
		check_same_number(stack_a);
		tmp = stack_a;
		stack_a = stack_a->next;
		free(tmp);
		check_sort(stack_a);
		// flag_stack(stack_a);
		// t_list *min = find_min(stack_a);
		// if (min->flag > 0)
		// {
		// 	while (min->flag > 1)
		// 	{
		// 		ra(&stack_a);
		// 		write(1, "ra\n", 3);
		// 		min->flag--;
		// 	}
		// }
		// if (min->flag < 0)
		// {
		// 	min->flag = min->flag * -1;
		// 	while (min->flag >= 1)
		// 	{
		// 		rra(&stack_a);
		// 		write(1, "rra\n", 4);
		// 		min->flag--;
		// 	}
		// }
		//sa(&stack_a);
		longest_increasing_subsequence(stack_a);	
		ft_norm(stack_a, &stack_a, &stack_b);
		// t_list *head = stack_a;
		// while (head)
		// 	{
		// 		printf("a = %d\n",head->content);
		// 		head = head->next;
		// 	}
		//free_memory(stack_a, stack_b);
	}
}
