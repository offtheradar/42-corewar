/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:37:46 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/20 16:07:57 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "op.h"
# include "libft/libft.h"

typedef struct 		s_champ
{
	t_header		header;
	int				id;
	unsigned char	*prog;
}					t_champ;

typedef	struct      s_vm
{
	t_champ         champs[MAX_PLAYERS];
	int				curr_champ;
	int    			nbr_cycles;
}					t_vm;

/*
****************************** Create VM struct ********************************
*/

t_vm				create_vm(void);

/*
****************************** Handle Args *************************************
*/

int					iter_args(int ac, char **av, t_vm *vm);

int					parse_args(int *i, int ac, char **av, t_vm *vm);

/*
****************************** Open and Load File ******************************
*/

int					open_file(char *file_name);

int					handle_cor_file(char *file_name);

int					handle_file(char *file_name, t_vm *vm);

int					read_file_header(int fd, t_header *header);

int					read_file_program(int fd, t_champ *champ);

/*
****************************** Setup Player ************************************
*/

#endif