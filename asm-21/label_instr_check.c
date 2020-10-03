#include "asm.h"

int		ft_is_only_label(char *trim_line)
{
	int len;
	int i;

	len = ft_strlen(trim_line);
	if (trim_line[len - 1] == ':')
	{
		i = 0;
		while (trim_line[i] && i < len - 1)
		{
			if (!ft_strchr(LABEL_CHARS, trim_line[i]))
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int		ft_is_only_instr(char *content, t_asm *assm)
{
	int i;
	int instr_len;

	i = 0;
	while (i < 16)
	{
		instr_len = ft_strlen((assm->operations[i])->name);
		if (!ft_strncmp(content, assm->operations[i]->name, instr_len)
			&& content[instr_len] != LABEL_CHAR)
			return (1);
		i++;
	}
	return (0);
}

int		ft_is_label_and_instr(char *trim_content, t_asm *assm)
{
	char	*lch;
	int		i;

	i = 0;
	lch = ft_strchr(trim_content, LABEL_CHAR);
	if (lch)
	{
		while (trim_content[i] != *lch)
		{
			if (!ft_strchr(LABEL_CHARS, trim_content[i]))
				return (0);
			i++;
		}
	}
	else
		return (0);
	while (++lch)
		if (*lch != ' ' && *lch != '\t')
			break ;
	return (ft_is_only_instr(lch, assm));
}

void	ft_check_instr(t_line *line, char *content, t_asm *assm)
{
	int		op_num;
	char	**args;
	int		i;
	int		op_nm_ln;

	i = 0;
	op_num = ft_get_operation_num(content, assm);
	op_nm_ln = ft_strlen(assm->operations[op_num]->name);
	while (content[op_nm_ln + i])
	{
		if ((content[op_nm_ln + i] == ',' && content[op_nm_ln + i + 1] == ',')
		|| (content[op_nm_ln + i] == ',' && content[op_nm_ln + i + 1] == '\0'))
			ft_print_separator_error(line);
		i++;
	}
	args = ft_strsplit(&content[op_nm_ln], SEPARATOR_CHAR);
	ft_check_empty_args_1(line, op_num, args, assm);
	ft_check_args_num(line, op_num, args, assm);
	ft_check_args(line, op_num, args, assm);
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

void	ft_check_label_symbols(t_line *line, char *label)
{
	int i;

	i = 0;
	while (label[i] == ' ' || label[i] == '\t')
		i++;
	while (label[i])
	{
		if (!ft_strchr(LABEL_CHARS, label[i]))
			ft_print_lexical_error(line->id_line, i + 1);
		i++;
	}
}
