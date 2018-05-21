/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 16:54:54 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/20 16:59:53 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		open_file(char *file_name)
{
	int fd;

	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		ft_putstr_fd("File Error!", 2);
		exit(0);
	}
	return (fd);
}

int		handle_file(char *file_name, t_vm *vm)
{
	int fd;

	fd = open_file(file_name);
	if (handle_cor_file(fd))
		return ();
	read_file_header(fd, vm->header)
}

int		handle_cor_file(int fd)
{
	int	len;

	
	len = ft_strlen(file_name);
	while (*file_name && *(file_name + len) != '.')
		len--;
	return (!ft_strcmp((file_name + len), ".cor"));
}

int		read_file_header(int fd, t_header *header)
{
	unsigned char buff[4];

	if (!(read(fd, header->magic, 4) == 4 &&
		ft_memcmp(header->magic, COREWAR_EXEC_MAGIC, 4) == 0))
		return (-1);
	read(fd, header->prog_name, PROG_NAME_LENGTH);
	header->prog_name[PROG_NAME_LENGTH] = '\0';
	if (!(read(fd, buff, 4) == 4 &&
		ft_memcmp(buff, "\0\0\0\0", 4) == 0))
		return (-1);
	if (!(read(fd, header->prog_size, 4) == 4))
		return (-1);
	if (!(read(fd, header->comment, COMMENT_LENGTH)))
		return (-1);
	header->comment[COMMENT_LENGTH] = '\0';
	if (!(read(fd, buff, 4) == 4 &&
		ft_memcmp(buff, "\0\0\0\0", 4) == 0))
		return (-1);
	return (1);
}

/*
** Read the next prog_size bytes
*/

int		read_file_program(int fd, t_champ *champ)
{
	champ->prog = ft_memalloc(sizeof(unsigned char *) *
					champ->header.prog_size);
	if (read(fd, champ->prog, champ->header.prog_size) !=
				champ->header.prog_size)
		return (-1);
	return (1);
}