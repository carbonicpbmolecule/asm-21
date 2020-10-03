#include "asm.h"

void	ft_check_args_num(t_line *line, int op_num, char **args, t_asm *assm)
{
	int		i;

	i = 0;
	while (args[i])
		i++;
	if (i != assm->operations[op_num]->arg_num)
	{
		ft_putstr_fd("Invalid parameter count for instruction ", 2);
		ft_putstr_fd(assm->operations[op_num]->name, 2);
		ft_putstr_fd(" at line ", 2);
		ft_putnbr_fd(line->id_line, 2);
		ft_putstr_fd("\n", 2);
		exit(-1);
	}
}

void	ft_check_arg_label_symbols(t_line *line, char *arg_label)
{
	int i;
	int t;

	i = 0;
	t = -1;
	while (line->content[++t])
		if (!ft_strncmp(&(line->content[t]), arg_label, ft_strlen(arg_label)))
			break ;
	while (arg_label[i])
	{
		if (!ft_strchr(LABEL_CHARS, arg_label[i]))
		{
			while (arg_label[i] == ' ' || arg_label[i] == '\t')
				i++;
			ft_print_lexical_error(line->id_line, t + i + 1);
		}
		i++;
	}
}

void	ft_check_arg_digits(t_line *line, char *numeric_arg)
{
	int i;

	i = 0;
	while (numeric_arg[i])
	{
		if ((numeric_arg[i] >= '0' && numeric_arg[i] <= '9')
		|| (numeric_arg[0] == '-'))
		{
			i++;
			continue;
		}
		else
			ft_print_syntax_error(line->id_line,
					(int)((ft_strstr(line->content, numeric_arg)
					- line->content) + 1),
					"ARGUMENT", numeric_arg);
	}
}

void	ft_check_reg_arg_digits(t_line *line, char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	if (arg[1] > '9' || arg[1] < '0'
		|| (arg[2] != '\0' && (arg[2] > '9' || arg[2] < '0'))
		|| (arg[1] == '0' && arg[2] == '0')
		|| (arg[1] == '0' && arg[2] == '\0')
		|| i > 3)
		ft_print_syntax_error(line->id_line,
			(int)(ft_strstr(line->content, arg) - line->content) + 1,
													"ARGUMENT", arg);
}

void	ft_check_arg_value(t_line *line, char *arg, char arg_type)
{
	if (arg_type == 'r')
	{
		ft_check_reg_arg_digits(line, arg);
		free(arg);
	}
	if (arg_type == 'd')
	{
		if (arg[1] == LABEL_CHAR)
			ft_check_arg_label_symbols(line, &arg[2]);
		else
			ft_check_arg_digits(line, &arg[1]);
		free(arg);
	}
	if (arg_type == 'i')
	{
		if (arg[0] == LABEL_CHAR)
			ft_check_arg_label_symbols(line, &arg[1]);
		else
			ft_check_arg_digits(line, &arg[0]);
		free(arg);
	}
}
