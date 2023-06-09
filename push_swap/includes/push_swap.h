/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:12:13 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/08 13:13:37 by csakamot         ###   ########.fr       */
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
void	ft_format_error(char **argv);
void	ft_invalid_arg(void);

/*
input
*/

t_node	*ft_input_arg(int argc, char **argv, t_node *a_stack);
int		*ft_input(int *index_stack, int*sort_stack, int argc, char **argv);
char	**ft_format_input(char *argv, char **relay);
void	ft_samenbr_check(int *ccstack, int *sort_stack, int index);
int		*ft_sort_array(int *sort_stack, int *index_stack, int index);
int		*ft_int_cpy(int *dest, const int *src, int n);
int		*ft_cc(int *ccstack, int *sort_stack, int index);
t_node	*ft_make_node(t_node *a_stack, int *ccstack, int index);
t_node	*ft_mkloop_node(t_node **a_stack, t_node *start, int i);
t_node	*ft_new_node(int content);
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
int		ft_pushcheck_head(int check, int index, int group);
int		ft_pushcheck_tail(int check, int center, int group);
void	ft_argsort_rtn(t_node *a_stack, t_node *b_stack, int index, int pivot);
void	ft_surpls_rtn(t_node *a_stack, t_node *b_stack, int index, int surpls);
void	ft_tail_return(t_node *a_stack, t_node *b_stack, int rtnnbr, int group);
void	ft_head_return(t_node *a_stack, t_node *b_stack, int rtnnbr, int group);
void	ft_rtn_fnbr(t_node *b_stack, int rtnnbr);
int		ft_serch_rab(t_node *b_stack, int rtnnbr);
int		ft_serch_rrab(t_node *b_stack, int rtnnbr);
void	ft_last_rtn(t_node *b_stack, int rab, int rrab);

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

void	ft_array_delete(char **relay);
int		ft_atoi_push(const char *nptr);

#endif