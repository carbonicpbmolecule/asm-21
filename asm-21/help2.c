#include "asm.h"

long long int	ft_atoi_long(const char *str)
{
	int				n;
	long long int	sum;

	n = 0;
	sum = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		n = 1;
	}
	while (*str - '0' >= 0 && *str - '0' <= 9)
	{
		if ((sum = sum * 10 + (*str - '0')) < 0 && n == 0)
			return (-1);
		if (sum < 0 && n == 1)
			return (0);
		str++;
	}
	if (n == 1)
		sum = -sum;
	return (sum);
}

char			*ft_str_num_no_lead_zeros(char *str_num)
{
	int		i;
	char	*num;
	char	*sign_char;
	char	*temp;

	i = 0;
	sign_char = "";
	if (str_num[i] == '-')
	{
		sign_char = "-";
		i++;
	}
	while (str_num[i] == '0')
		i++;
	temp = ft_strdup(&(str_num[i]));
	num = ft_strjoin(sign_char, temp);
	free(temp);
	return (num);
}

void			ft_arg_error(t_instr *instr, char *str_num)
{
	ft_putstr_fd("Argument out of bounds of integer type ", 2);
	ft_putstr_fd("at line ", 2);
	ft_putnbr_fd(instr->line->id_line, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str_num, 2);
	ft_putstr_fd("\n", 2);
	exit(-1);
}

int				ft_ovrint(char *str, t_instr *instr)
{
	int		i;
	char	*num;
	long	num_l;

	num = ft_str_num_no_lead_zeros(str);
	i = 0;
	while (num[i])
		i++;
	if (i > 11)
	{
		free(num);
		if (num[0] == '-')
			ft_arg_error(instr, str);
		else
			ft_arg_error(instr, str);
	}
	else
		num_l = ft_atoi_long(num);
	free(num);
	if (num_l > INT_MAX)
		ft_arg_error(instr, str);
	if (num_l < INT_MIN)
		ft_arg_error(instr, str);
	return (num_l);
}
