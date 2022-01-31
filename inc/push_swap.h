/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:39:11 by crobot            #+#    #+#             */
/*   Updated: 2021/10/05 19:39:14 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../libft/inc/libft.h"

typedef enum s_way
{
	R,
	RR
}	t_way;

typedef struct s_elem
{
	int					num;
	int					indx;
	t_bool				move;
	struct s_elem		*prev;
	struct s_elem		*next;
}						t_elem;

typedef struct s_stack
{
	t_elem				*head;
	int					size;
	int					row;
	t_elem				*mark_head;
}						t_stack;

typedef struct s_step_data
{
	t_elem				*a_elem;
	t_elem				*b_elem;
	int					a_way;
	int					b_way;
	int					size;
	t_bool				is_set;
}						t_step_data;

typedef struct s_op
{
	char				*name;
	struct s_op			*next;
}						t_op;

typedef struct s_ops_que
{
	int					size;
	t_op				*head;
}						t_ops_que;

/*	utils1.c & utils2.c	*/
void				free_op_que(t_ops_que *que);
void				free_stack(t_stack *stack);
void				ft_split_free(char ***split);
void				terminate(char *str);
int					ft_max(int a, int b);

/*		parsing.c		*/
void				dup_check(t_stack *stack);
void				parse_arr(t_stack *stack, int ac, char **av);
void				parse_str(t_stack *stack, char *str);
t_stack				*parse(int ac, char **av);

/*		stack.c		*/
t_elem				*create_elem(int num);
void				add(t_stack *stack, t_elem *elem);
void				push(t_stack *stack, t_elem *elem);
t_elem				*pop(t_stack *stack);

/*		indx.c		*/
int					mark1(t_stack *stack, t_elem *mark_head);
int					mark2(t_stack *stack, t_elem *mark_head);
void				best_mark(t_stack *stack, int (*mark)(t_stack *, t_elem *));
void				indx(t_stack *stack);

/*		ops1.c & ops2.c	*/
void				rx(t_stack *stack, char *name, t_ops_que *que);
void				rr(t_stack *a, t_stack *b, char *name, t_ops_que *que);
void				rrx(t_stack *stack,	char *name, t_ops_que *que);
void				rrr(t_stack *a, t_stack *b, char *name, t_ops_que *que);
void				px(t_stack *out, t_stack *in, char *op, t_ops_que *que);
void				sx(t_stack *stack, char *name, t_ops_que *que);
void				ss(t_stack *a, t_stack *b, char *name, t_ops_que *que);

/*		sort.c		*/
t_ops_que			*sort(t_stack *a, int (*mark)(t_stack *, t_elem *));
void				sort_a(t_stack *a, t_stack *b, int (*mark)(t_stack *,
							t_elem *), t_ops_que *que);
void				sort_b(t_stack *a, t_stack *b, t_ops_que *que);

/*		way.c		*/
void				find_way(t_stack *a, t_stack *b, t_step_data *step_data);

/*		start.c		*/
t_stack				*init_stack(void);
t_ops_que			*init_ops_que(void);

/*		ops_que.c	*/
t_op				*create_op(char *name);
void				add_op(t_ops_que *que, t_op *op);
void				print_que(t_ops_que *que1, t_ops_que *que2);
void				print_ops(t_ops_que *que);

#endif
