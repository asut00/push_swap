/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_03_execute_actions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:23:03 by asuteau           #+#    #+#             */
/*   Updated: 2024/02/24 17:23:10 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_e_act	str_to_act(const char *str)
{
	if (!ft_strcmp(str, "pa"))
		return (e_pa);
	else if (!ft_strcmp(str, "pb"))
		return (e_pb);
	else if (!ft_strcmp(str, "rra"))
		return (e_rra);
	else if (!ft_strcmp(str, "rrb"))
		return (e_rrb);
	else if (!ft_strcmp(str, "rrr"))
		return (e_rrr);
	else if (!ft_strcmp(str, "ra"))
		return (e_ra);
	else if (!ft_strcmp(str, "rb"))
		return (e_rb);
	else if (!ft_strcmp(str, "rr"))
		return (e_rr);
	else if (!ft_strcmp(str, "sa"))
		return (e_sa);
	else if (!ft_strcmp(str, "sb"))
		return (e_sb);
	else if (!ft_strcmp(str, "ss"))
		return (e_ss);
	else
		return (e_null_op);
}

void	exec_act(t_stacks *s, t_e_act act, char **splitted_actions)
{
	if (act == e_pa)
		pa(s->stack_a, s->stack_b, &(s->size_a), &(s->size_b));
	else if (act == e_pb)
		pb(s->stack_a, s->stack_b, &(s->size_a), &(s->size_b));
	else if (act == e_rra)
		rra(s->stack_a, s->size_a);
	else if (act == e_rrb)
		rrb(s->stack_b, s->size_b);
	else if (act == e_rrr)
		rrr(s->stack_a, s->stack_b, s->size_a, s->size_b);
	else if (act == e_ra)
		ra(s->stack_a, s->size_a);
	else if (act == e_rb)
		rb(s->stack_b, s->size_b);
	else if (act == e_rr)
		rr(s->stack_a, s->stack_b, s->size_a, s->size_b);
	else if (act == e_sa)
		sa(s->stack_a);
	else if (act == e_sb)
		sb(s->stack_b);
	else if (act == e_ss)
		ss(s->stack_a, s->stack_b);
	else
		handle_action_error(s, splitted_actions);
}

void	execute_actions(t_stacks *stk, char **spl_actions)
{
	int		i;
	t_e_act	act;

	i = 0;
	while (spl_actions[i] && spl_actions[i][0])
	{
		act = str_to_act(spl_actions[i]);
		exec_act(stk, act, spl_actions);
		i++;
	}
}
