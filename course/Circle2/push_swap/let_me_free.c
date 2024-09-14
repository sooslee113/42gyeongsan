/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_me_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:27:24 by sooslee           #+#    #+#             */
/*   Updated: 2024/07/16 23:52:27 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lets_free(t_stack *a)
{
	t_node	*current;

	current = a->head;
	if (current != NULL)
	{
		a->head = current->next;
		free(current);
		lets_free(a);
	}
}

void	double_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i ++;
	}
	free (split);
}
