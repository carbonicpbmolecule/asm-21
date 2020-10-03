#include "asm.h"

void	ft_check_empty_args_2(t_line *line, char **args, int start_pos)
{
	int j;
	int k;
	int args_len;

	j = -1;
	args_len = 0;
	while (args[++j])
	{
		if (j > 0)
			args_len = args_len + ft_strlen(args[j - 1]) + 1;
		k = -1;
		while (args[j][++k])
		{
			if (args[j][k] == ' ' || args[j][k] == '\t' || args[j][k] == 'r'
				|| args[j][k] == '%' || args[j][k] == '-' || args[j][k] == ':')
				continue;
			else
				break ;
		}
		if (args[j][k] == '\0')
		{
			ft_print_lexical_error(line->id_line, start_pos + args_len + k);
		}
	}
}

void	ft_check_empty_args_1(t_line *line, int op_num,
									char **args, t_asm *assm)
{
	int i;
	int op_len;

	i = -1;
	op_len = ft_strlen(assm->operations[op_num]->name);
	while (line->content[++i])
		if (!ft_strncmp(&line->content[i], assm->operations[op_num]->name,
				op_len) && line->content[i + op_len] != ':')
			break ;
	i = i + op_len + 1;
	ft_check_empty_args_2(line, args, i);
}

void	ft_check_arg(t_line *line, char *arg, char *arg_type, char *oper_name)
{
	char	*trim_arg;
	int		i;

	i = -1;
	trim_arg = ft_strtrim(arg);
	while (++i < 3 && arg_type[i])
	{
		if (arg_type[i] == 'r' && *trim_arg == 'r')
			break ;
		if (arg_type[i] == 'd' && *trim_arg == '%')
			break ;
		if (arg_type[i] == 'i' &&
		(*trim_arg == '-' || *trim_arg == ':'
		|| (*trim_arg >= '0' && *trim_arg <= '9')))
			break ;
	}
	if (i == 3 || arg_type[i] == '\0')
	{
		ft_putstr_fd("Invalid parameter type for instruction ", 2);
		ft_putstr_fd(oper_name, 2);
		ft_putstr_fd(" at line ", 2);
		ft_putnbr_fd(line->id_line, 2);
		ft_error_message(2, " ARGUMENT \"", trim_arg, "\"\n");
	}
	ft_check_arg_value(line, trim_arg, arg_type[i]);
}

void	ft_check_args(t_line *line, int op_num, char **args, t_asm *assm)
{
	char *opnm;

	opnm = assm->operations[op_num]->name;
	if (assm->operations[op_num]->arg_num == 1)
		ft_check_arg(line, args[0], assm->operations[op_num]->arg1_type, opnm);
	if (assm->operations[op_num]->arg_num == 2)
	{
		ft_check_arg(line, args[0], assm->operations[op_num]->arg1_type, opnm);
		ft_check_arg(line, args[1], assm->operations[op_num]->arg2_type, opnm);
	}
	if (assm->operations[op_num]->arg_num == 3)
	{
		ft_check_arg(line, args[0], assm->operations[op_num]->arg1_type, opnm);
		ft_check_arg(line, args[1], assm->operations[op_num]->arg2_type, opnm);
		ft_check_arg(line, args[2], assm->operations[op_num]->arg3_type, opnm);
	}
}
