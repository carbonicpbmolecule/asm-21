#include "asm.h"

int				ft_get_operation_num(char *content, t_asm *assm)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (!ft_strncmp(content, assm->operations[i]->name,
						ft_strlen(assm->operations[i]->name)))
			return (i);
		i++;
	}
	return (-1);
}

unsigned char	ft_add_arg_code_to_byte(char **args)
{
	unsigned char	byte;
	int				i;
	int				j;

	i = 0;
	byte = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j] == ' ' || args[i][j] == '\t')
			j++;
		if (args[i][j] == 'r')
			byte = byte | ((unsigned char)64 >> (2 * i));
		else if (args[i][j] == '%')
			byte = byte | ((unsigned char)128 >> (2 * i));
		else
			byte = byte | ((unsigned char)192 >> (2 * i));
		i++;
	}
	return (byte);
}

void			ft_print_nonexistent_label_2(char *temp, char *label_arg)
{
	if (*temp == '%')
	{
		ft_putstr_fd(" DIRECT_LABEL \"", 2);
		ft_putchar_fd(*temp, 2);
		ft_putchar_fd(temp[1], 2);
		ft_putstr_fd(label_arg, 2);
		ft_putstr_fd("\"\n", 2);
	}
	else
	{
		ft_putstr_fd(" INDIRECT_LABEL \"", 2);
		ft_putchar_fd(temp[1], 2);
		ft_putstr_fd(label_arg, 2);
		ft_putstr_fd("\"\n", 2);
	}
}

void			ft_print_nonexistent_label_1(t_instr *instr, char *label_arg)
{
	char *temp;

	temp = ft_strstr(instr->line->content, label_arg);
	if (temp[ft_strlen(label_arg)] != '\0' &&
		ft_strchr(LABEL_CHARS, temp[ft_strlen(label_arg)]))
	{
		temp = ft_strstr(&temp[ft_strlen(label_arg)], label_arg);
		if (temp[ft_strlen(label_arg)] != '\0' &&
			ft_strchr(LABEL_CHARS, temp[ft_strlen(label_arg)]))
			temp = ft_strstr(&temp[ft_strlen(label_arg)], label_arg);
	}
	ft_putstr_fd("No such label ", 2);
	ft_putstr_fd(label_arg, 2);
	ft_putstr_fd(" while attempting to dereference token [TOKEN][", 2);
	ft_putnbr_fd(instr->line->id_line, 2);
	ft_putstr_fd(":", 2);
	ft_putnbr_fd(temp - instr->line->content + 1, 2);
	ft_putstr_fd("]", 2);
	temp--;
	temp--;
	ft_print_nonexistent_label_2(temp, label_arg);
	exit(-1);
}

void			ft_get_numeric_label_value(int *numeric_arg, t_instr *instr,
										t_instr *iter_instr, int lbl_instr_id)
{
	if (instr->id < lbl_instr_id)
	{
		while (iter_instr)
		{
			if (iter_instr->id == lbl_instr_id)
				break ;
			*numeric_arg = *numeric_arg + iter_instr->size;
			iter_instr = iter_instr->next;
		}
	}
	else if (instr->id > lbl_instr_id)
	{
		while (iter_instr)
		{
			iter_instr = iter_instr->prev;
			*numeric_arg = *numeric_arg - iter_instr->size;
			if (iter_instr->id == lbl_instr_id)
				break ;
		}
	}
}
