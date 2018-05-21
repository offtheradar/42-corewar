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

typedef	struct      s_vm
{
    t_champ         champs[MAX_PLAYERS];
    unsigned int	curr_champ;
    unsigned int    nbr_cycles;
}					t_vm;

typedef struct 		s_champ
{
	t_header		header;
	unsigned char	*prog;
}					t_champ;

#endif