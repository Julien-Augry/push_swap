/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:23:53 by juaugry           #+#    #+#             */
/*   Updated: 2022/10/22 18:53:26 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

void	sort_center(t_stack **a, t_stack **b, int size);
void	target_push(t_stack **a, t_stack **b, int move);
void	target_push2(t_stack **a, t_stack **b, t_stack *ptr);
void	moulinette(t_stack **stack);

void	init_sort(t_stack **a, t_stack **b, int size);
void	sort_three(t_stack **a);
void	rush_b(t_stack **a, t_stack **b, int size);

int		best_move(t_stack *b);
void	assign_cost(t_stack **a, t_stack **b);
int		get_cost(t_stack *stack, int pos);

void	update_data(t_stack **a, t_stack **b, int size);
void	assign_target(t_stack **a, t_stack **b, int size);
void	assign_data(t_stack **a, t_stack **b);
void	assign_index(t_stack *stack, int size);
void	assign_pos(t_stack *stack);
int		get_higher(t_stack *stack);
int		get_lower(t_stack *a, int size);
int		get_target(t_stack *a, int index, int size);

void	add_node(t_stack **stack, t_stack *node);
t_stack	*last_node(t_stack *stack);
t_stack	*before_last_node(t_stack *stack);
t_stack	*new_node(int value, int index);
int		stack_size(t_stack *stack);
void	clear_stack(t_stack **stack);

void	swap_a(t_stack *a, int ss);
void	swap_b(t_stack *b, int ss);
void	swap_both(t_stack **a, t_stack **b);
void	push_a(t_stack **b, t_stack **a);
void	push_b(t_stack **a, t_stack **b);
void	rotate_a(t_stack **a, int rr);
void	rotate_b(t_stack **b, int rr);
void	rotate_both(t_stack **a, t_stack **b);
void	reverse_a(t_stack **a, int rrr);
void	reverse_b(t_stack **b, int rrr);
void	reverse_both(t_stack **a, t_stack **b);

int		is_a_sorted(t_stack *a);

char	*join_args(char **args);
int		args_isdigit(char *joined);
int		check_doublon(t_stack *a, int num);
int		cmp_overflow(char *str, int sign);
int		check_int_overflow(char *str);
int		tab_size(char	**tab);
int		parse_stack(t_stack *a);
int		args_to_stack(char **args, int ac, t_stack **stack);
int		main(int ac, char **av);

#endif
