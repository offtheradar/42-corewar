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

/*
** Safely open the file. 
*/

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

/*
** Open the file and check whether the extension is a .cor
*/

int		handle_file(char *file_name, t_vm *vm)
{
	int fd;

	fd = open_file(file_name);
	if (get_next_player(vm))
		return (1);
	if (handle_cor_file(file_name))
		return (1);
	if (read_file_header(fd, &(vm->champs[vm->curr_champ].header)))
		return (1);
	if (read_file_program(fd, &(vm->champs[vm->curr_champ])))
		return (1);
	return (-1);
}

/*
** Check if extension is .cor
*/

int		handle_cor_file(char *file_name)
{
	int len;

	len = ft_strlen(file_name);
	while (*file_name && *(file_name + len) != '.')
		len--;
	return (!ft_strequ((file_name + len), ".cor"));
}

/*
** Read the file header.
** 1) 4 bytes for the .cor magic number
** 2) PROG_NAME_LENGTH bytes for the program name
** 3) 4 bytes for 0 buffer
** 4) 4 bytes for program size
** 5) COMMENT_LENGTH bytes for the comment
** 6) 4 bytes for 0 buffer
*/

int		read_file_header(int fd, t_header *header)
{
	unsigned char buff[4];

	if (!(read(fd, buff, 4) == 4 &&
		ft_memcmp(buff, COREWAR_EXEC_MAGIC, 4) == 0))
		return (ft_puterror(-1, "Invalid Magic Number."));
	read(fd, header->prog_name, PROG_NAME_LENGTH);
	header->prog_name[PROG_NAME_LENGTH] = '\0';
	if (!(read(fd, buff, 4) == 4 &&
		ft_memcmp(buff, "\0\0\0\0", 4) == 0))
		return (ft_puterror(-1, "Incorrect buffer"));
	if (!(read(fd, buff, 4) == 4))
		return (ft_puterror(-1, "Incorrect program size."));
	header->prog_size = (unsigned int)buff;
	if (!(read(fd, header->comment, COMMENT_LENGTH)))
		return (ft_puterror(-1, "Invalid comment."));
	header->comment[COMMENT_LENGTH] = '\0';
	if (!(read(fd, buff, 4) == 4 &&
		ft_memcmp(buff, "\0\0\0\0", 4) == 0))
		return (ft_puterror(-1, "Invalid buffer between comment and program."));
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
		return (ft_puterror(-1, "Invalid program."));
	return (1);
}