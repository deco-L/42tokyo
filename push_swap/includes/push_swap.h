/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:12:13 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/25 15:25:35 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../srcs/libft/libft.h"
# include "../srcs/ft_printf/ft_printf.h"

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*prev;
	int				flag;
}				t_node;

/*
eroor
*/
void	ft_malloc_error(void);
void	ft_mallocerror_node(t_node *a_stack, int i);
int		ft_standard_input_error(int argc, char **argv);
void	ft_arg_less(void);
int		ft_one_arg_check(char **argv);
void	ft_args_check(int argc, char **argv);

/*
input
*/

t_node	*ft_input_arg(int argc, char **argv, t_node *a_stack, int flag);
int		*ft_input(int *index_stack, int argc, char **argv);
int		*ft_format_input(int *index_stack, char **argv);
int		*ft_sort_array(int *sort_stack, int *index_stack, int index);
int		*ft_int_cpy(int *dest, const int *src, int n);
int		*ft_cc(int *ccstack, int *sort_stack, int index);
t_node	*ft_make_node(t_node *a_stack, int *ccstack, int index);
t_node	*ft_mkloop_node(t_node **a_stack, t_node *start, int i);
t_node	*ft_new_node(t_node *a_stack, int content);
void	ft_nodeadd_back(t_node **a_stack, t_node *new);

/*
main_sort
*/

void	ft_main_sort(t_node *a_stack, int index);
void	ft_twoarg_sort(t_node *a_stack);
void	ft_twoarg_resort(t_node *stack);
void	ft_threearg_sort(t_node *a_stack);
void	ft_threearg_resort(t_node *stack);
void	ft_small_head_sort(t_node *start, t_node *stack);
void	ft_small_head_resort(t_node *start, t_node *stack);
void	ft_big_head_sort(t_node *start, t_node *stack);
void	ft_big_head_resort(t_node *start, t_node *stack);
void	ft_fewargs_sort(t_node *a_stack, t_node *b_stack, int index);
int		ft_sort_checker(t_node *stack);
void	ft_fewsort_push(t_node *a_stack, t_node *b_stack, int index);
void	ft_args_sort(t_node *a_stack, t_node *b_stack, int index);
void	ft_argsort_push(t_node *a_stack, t_node *b_stack, int pivot, int group);
void	ft_argsort_rtn(t_node *a_stack, t_node *b_stack, int index, int group);
void	ft_surplus_rtn(t_node *a_stack, t_node *b_stack, int index, int group);
void	ft_tail_return(t_node *a_stack, t_node *b_stack, int rtnnbr, int group);
void	ft_head_return(t_node *a_stack, t_node *b_stack, int rtnnbr, int group);

/*
sort_rule
*/

void	ft_sort_rule_sab(t_node *stack, int mode);
void	ft_sort_rule_rab(t_node *stack, int mode);
void	ft_sort_rule_rrab(t_node *stack, int mode);
void	ft_sort_rule_pab(t_node *a_stack, t_node *b_stack, int mode);
void	ft_first_sort_pab(t_node *move_stack, t_node *receive_stack);

/*
node_helper
*/

void	ft_delete_all_node(t_node *a_stack);

/*
else
*/

void	ft_putstr(char *str);

#endif