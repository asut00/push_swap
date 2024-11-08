/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:23:03 by asuteau           #+#    #+#             */
/*   Updated: 2024/02/24 17:23:10 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

//\\//\\//\\//\\//\\//\\//\\// ENUM //\\//\\//\\//\\//\\//\\//\\//

typedef enum e_act
{
	e_null_op,
	e_pa,
	e_pb,
	e_ra,
	e_rb,
	e_rr,
	e_rra,
	e_rrb,
	e_rrr,
	e_sa,
	e_sb,
	e_ss
}	t_e_act;

# define ERROR_DOUBLES 1
# define SORTED 2

//\\//\\//\\//\\//\\//\\//\\// FUNCTIONS //\\//\\//\\//\\//\\//\\//\\//

//	push_swap_00_tools.c
int		ft_isdigit(int c);
void	ft_swap(int *a, int *b);
void	ft_putstr_fd(char *s, int fd);

//	push_swap_00_errors_and_free.c
int		error_exit_function(int ret_value);
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
int		count_words_spe(char const *str, char charset);
char	**ft_split_spe(char const *str, char c);
char	**attribute_words_spe(char **tab, char const *str, char c);
int		ft_sl_s_spe(char const *str, char charset);
char	**free_tab_spe(char **tab, int x);

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

//\\//\\//\\//\\//\\//\\//\\// BONUS //\\//\\//\\//\\//\\//\\//\\//

// checker_01_read_actions.c
int		ft_strlen(char *s);
char	*ft_add_char(char *s, char c);
char	*read_actions(void);

// checker_02_ft_split.c
int		count_words(char const *str, char charset);
int		ft_sl_s(char const *str, char charset);
char	**free_tab(char **tab, int x);
char	**attribute_words(char **tab, char const *str, char c);
char	**ft_split(char const *s, char c);

// checker_03_execute_actions.c
int		ft_strcmp(const char *s1, const char *s2);
void	free_splitted(char **splitted);
t_e_act	str_to_act(const char *str);
void	exec_act(t_stacks *s, t_e_act act, char **splitted_actions);
void	execute_actions(t_stacks *stk, char **spl_actions);

// checker_04_exec_utils.c
int		ft_strcmp(const char *s1, const char *s2);
void	free_splitted(char **splitted);
void	handle_action_error(t_stacks *s, char **splitted_actions);

#endif