/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 16:54:57 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/20 16:55:18 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		parse_args(int *i, int ac, char **av, t_vm *vm)
{
		if (ft_strequ(av[*i], "-dump") == 0)
		{
			i++;
			return (i < ac && vm->nbr_cycles = ft_atoi(av[i]));
		}
		if (ft_strequ(av[*i], "-n") == 0)
		{
			i++;
			return (i < ac && vm->curr_champ = ft_atoi(av[i]));
		}
		if (handle_file(av[*i], vm))
		{
			ft_putstr_fd("File Error!, Enter a .cor file.", 2);
			exit(0);
		}
}

int		iter_args(int ac, char **av, t_vm *vm)
{
	int i;

	i = 0;
	while (++i < ac)
	{
		if (parse_args(&i, ac, av, vm) == -1)
			return (-1);
	}
}