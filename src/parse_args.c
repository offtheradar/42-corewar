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

/*
** Verify whether the argument if the argument is valid, load to appropriate 
** variable if so, return an error code otherwise.
*/

int		parse_args(int *i, int ac, char **av, t_vm *vm)
{
	if (ft_strequ(av[*i], "-dump") == 1)
	{
		(*i)++;
		return (((*i) < ac && (vm->nbr_cycles = ft_atoi(av[*i])) > 0) ? 1 : -1);
	}
	else if (ft_strequ(av[*i], "-n") == 1)
	{
		(*i)++;
		return (((*i) < ac && (vm->curr_champ = ft_atoi(av[*i])) >= 0) ? 1 : -1);
	}
	else if (handle_file(av[*i], vm))
		return (1);
	return (-1);
}

/*
** Iterate throught the list of arguments, call parse args.
*/

int		iter_args(int ac, char **av, t_vm *vm)
{
	int i;

	i = 0;
	while (++i < ac)
	{
		if (parse_args(&i, ac, av, vm) == -1)
			return (ft_puterror(-1, "Parsing Error"));
	}
	return (1);
}