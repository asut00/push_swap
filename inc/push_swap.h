/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:23:03 by asuteau           #+#    #+#             */
/*   Updated: 2024/02/24 17:23:10 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//\\//\\//\\//\\//\\//\\//\\// LIBRARIES //\\//\\//\\//\\//\\//\\//\\//

# include <unistd.h>
# include <stdlib.h>

//\\//\\//\\//\\//\\//\\//\\// STRUCTURE //\\//\\//\\//\\//\\//\\//\\//

typedef struct s_stacks
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
	int	original_argc;
	int	original_size_a;
}	t_stacks;

//\\//\\//\\//\\//\\//\\//\\// MACRO //\\//\\//\\//\\//\\//\\//\\//

# define ERROR_DOUBLES 1
# define SORTED 2

//\\//\\//\\//\\//\\//\\//\\// FUNCTIONS //\\//\\//\\//\\//\\//\\//\\//

//	push_swap_00_tools.c
int		ft_isdigit(int c);
void	ft_swap(int *a, int *b);

//	push_swap_00_errors_and_free.c
int		error_return_function(int ret_value);
int		*free_and_return_null(int **m1, int **m2, int **m3, char **m4);
void	free_splitted_words_and_argv(char **argv, int size);

//	push_swap_01_check_args.c
int		check_args_and_fillup(t_stacks *stacks, int *argc, char ***argv);
char	**check_args(int *argc, char **argv);
int		contains_only_space_sign_or_digit(char *str);
int		ft_is_space_sign_or_digit(int c);
char	**check_num_format(int *argc, char **argv);

//	push_swap_02_ft_split.c
int		count_words(char const *str, char charset);
char	**ft_split_spe(char const *str, char c);
char	**attribute_words(char **tab, char const *str, char c);
int		ft_sl_s(char const *str, char charset);
char	**free_tab(char **tab, int x);

//	push_swap_03_fillup.c
void	handle_stack_a_malloc_fail(int argc, char **argv);
void	handle_stack_b_malloc_fail(int argc, char **argv, int *stack_a);
int		*fill_up_arrays(t_stacks *stacks, int argc, char **argv);
long	ft_atol(const char *str);

//	push_swap_04_check_doubles_and_if_sorted.c
int		check_doubles_and_if_sorted(t_stacks *stacks);
int		check_doubles(t_stacks *stacks);
int		is_sorted(int *stack_a, int size_a);

// push_swap_05a_swap.c
void	sa(int *stack_a);
void	sb(int *stack_b);
void	ss(int *stack_a, int *stack_b);

// push_swap_05b_push.c
void	push(int value, int *stack, int index, int *size);
void	pa(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	pb(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	delete_index(int *stack, int index, int *size);

// push_swap_05c_rotate.c
void	rotate(int *stack, int size);
void	ra(int *stack_a, int size_a);
void	rb(int *stack_b, int size_b);
void	rr(int *stack_a, int *stack_b, int size_a, int size_b);

// push_swap_05c_reverse_rotate.c
void	reverse_rotate(int *stack, int size);
void	rra(int *stack_a, int size_a);
void	rrb(int *stack_b, int size_b);
void	rrr(int *stack_a, int *stack_b, int size_a, int size_b);

// push_swap_06_calculate_median.c
int		calculate_median(t_stacks *stacks);
int		calculate_third_quartile(t_stacks *stacks);
int		*copy_tab(int *temp_tab, int *stack, int size);
void	ft_sort_int_tab(int *tab, int size);

// push_swap_07a_algo_and_sort_two_three.c
int		algorythm(t_stacks *stacks);
int		sort_two(int *stack);
int		sort_three_in_a(int *stack, int size);

// push_swap_07b_sort_four.c
int		sort_four(int *stack_a, int *stack_b, int *size_a, int *size_b);
long	find_target_in_stack_a(int *stack_a, int *size_a, int *stack_b, int x);
int		find_min_index(int *stack, int size);
void	put_value_as_first_in_a(int *stack_a, int *size_a, int target);
void	rotate_so_that_min_is_first(int *stack_a, int *size_a);

// push_swap_07c_sort_five_six_seven.c
int		sort_five(int *stack_a, int *stack_b, int *size_a, int *size_b);
int		reverse_sort_three_in_a(int *stack, int size);
int		sort_six(int *stack_a, int *stack_b, int *size_a, int *size_b);
int		sort_seven(int *stack_a, int *stack_b, int *size_a, int *size_b);

// push_swap_07d_sort_eight.c
int		sort_eight(int *stack_a, int *stack_b, int *size_a, int *size_b);
int		get_cost_to_move_in_first(int size, int index);
int		find_best_bnum_indx(int *stk_a, int *stk_b, int *size_a, int *size_b);

// push_swap_07d_sort_big_number.c
void	put_value_as_first_in_b(int *stack_b, int *size_b, int target);
void	pre_sorting(t_stacks *stacks);
int		recursive_pre_sorting(t_stacks *stacks);
int		find_trgt_idx_in_stk_a(int *stack_a, int *size_a, int *stack_b, int x);
int		sort_big_number(t_stacks *stacks);

#endif