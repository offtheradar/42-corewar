/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:35:47 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/20 17:00:25 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_vm	create_vm(void)
{
	t_vm	new_vm;

	new_vm.nbr_cycles = 0;
	new_vm.curr_champ = 0;
	return (new_vm);
}

int		main(int ac, char **av)
{
	t_vm	vm;

	vm = create_vm();
	parse_args(ac, av, &vm);
}
