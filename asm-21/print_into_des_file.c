#include "asm.h"

void	ft_print_byte_code_into_file(t_instr *instr, int fd)
{
	t_instr *iter;

	iter = instr;
	while (iter)
	{
		write(fd, iter->bytes, iter->size);
		iter = iter->next;
	}
}

void	ft_print_magic_number(int fd2)
{
	unsigned char	c;
	int				magic_number;
	int				i;

	i = 3;
	magic_number = COREWAR_EXEC_MAGIC;
	while (i >= 0)
	{
		c = 0;
		c = c | (unsigned char)(magic_number >> (8 * i));
		write(fd2, &c, 1);
		i--;
	}
}

void	ft_print_name_into_file(char *name, int fd)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(name);
	while (i < PROG_NAME_LENGTH)
	{
		if (i < len)
			write(fd, &name[i], 1);
		else
			write(fd, "\0", 1);
		i++;
	}
	write(fd, "\0\0\0\0", 4);
}

void	ft_print_exec_code_size(t_instr *instr, int fd)
{
	t_instr			*iter;
	int				code_size;
	int				i;
	unsigned char	c;

	iter = instr;
	code_size = 0;
	i = 3;
	while (iter)
	{
		code_size = code_size + iter->size;
		iter = iter->next;
	}
	while (i >= 0)
	{
		c = 0;
		c = (unsigned char)(code_size >> (i * 8));
		write(fd, &c, 1);
		i--;
	}
}

void	ft_print_comment_into_file(char *comment, int fd)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(comment);
	while (i < COMMENT_LENGTH)
	{
		if (i < len)
			write(fd, &comment[i], 1);
		else
			write(fd, "\0", 1);
		i++;
	}
	write(fd, "\0\0\0\0", 4);
}
