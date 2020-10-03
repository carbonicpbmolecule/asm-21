#include "asm.h"

int		ft_get_label_arg(char *label_arg, t_label *label, t_instr *instr)
{
	t_label	*iter_lbl;
	t_instr	*iter_instr;
	int		lbl_instr_id;
	int		numeric_arg;

	iter_lbl = label;
	iter_instr = instr;
	numeric_arg = 0;
	lbl_instr_id = 0;
	while (iter_lbl)
	{
		if (!ft_strcmp(label_arg, iter_lbl->name))
		{
			lbl_instr_id = iter_lbl->id_instr;
			break ;
		}
		iter_lbl = iter_lbl->next;
	}
	if (iter_lbl == NULL)
		ft_print_nonexistent_label_1(iter_instr, label_arg);
	ft_get_numeric_label_value(&numeric_arg, instr, iter_instr, lbl_instr_id);
	return (numeric_arg);
}

void	ft_add_dir_arg_to_byte_code(char *arg, int *pos,
								t_instr *instr, t_asm *assm)
{
	int op_num;
	int arg_numeric;
	int i;
	int j;

	op_num = ft_get_operation_num(instr->cont, assm);
	i = *pos + assm->operations[op_num]->dir_type_size;
	if (arg[0] == ':')
		arg_numeric = ft_get_label_arg(&arg[1], assm->label_h, instr);
	else
		arg_numeric = ft_ovrint(arg, instr);
	j = assm->operations[op_num]->dir_type_size - 1;
	while (*pos < i)
	{
		instr->bytes[*pos] = (unsigned char)(arg_numeric >> 8 * j);
		j--;
		(*pos)++;
	}
}

void	ft_ind_arg_to_byte_code(char *arg, int *pos,
								t_instr *instr, t_label *label)
{
	int arg_numeric;
	int i;
	int j;

	i = *pos + 2;
	if (arg[0] == ':')
		arg_numeric = ft_get_label_arg(&arg[1], label, instr);
	else
		arg_numeric = ft_ovrint(arg, instr);
	j = 1;
	while (*pos < i)
	{
		instr->bytes[*pos] = (unsigned char)(arg_numeric >> 8 * j);
		j--;
		(*pos)++;
	}
}

void	ft_add_args_to_byte_code(t_instr *instr, int op_num, t_asm *assm)
{
	int		pos;
	char	**args;
	int		i;
	char	*temp_str;

	ft_creat_byte_array(instr, op_num, &pos, assm);
	args = ft_strsplit(
	&(instr->cont[ft_strlen(assm->operations[op_num]->name)]), SEPARATOR_CHAR);
	if (assm->operations[op_num]->arg_type_code)
		instr->bytes[pos++] = ft_add_arg_code_to_byte(args);
	i = -1;
	while (args[++i])
	{
		temp_str = ft_strtrim(args[i]);
		free(args[i]);
		args[i] = temp_str;
		if (args[i][0] == 'r')
			instr->bytes[pos++] = (unsigned char)ft_ovrint(&args[i][1], instr);
		else if (args[i][0] == '%')
			ft_add_dir_arg_to_byte_code(&(args[i][1]), &pos, instr, assm);
		else
			ft_ind_arg_to_byte_code(&(args[i][0]), &pos, instr, assm->label_h);
		free(temp_str);
	}
	free(args);
}

void	ft_instr_from_numeric_to_bytes(t_instr *instr, t_asm *assm)
{
	t_instr	*iter;
	int		op_num;

	iter = instr;
	while (iter)
	{
		op_num = ft_get_operation_num(iter->cont, assm);
		ft_add_args_to_byte_code(iter, op_num, assm);
		iter = iter->next;
	}
}
