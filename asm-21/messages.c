#include "asm.h"

void	ft_print_lexical_error(int line_num, int pos_num)
{
	ft_putstr_fd("Error [", 2);
	ft_putnbr_fd(line_num, 2);
	ft_putstr_fd(":", 2);
	ft_putnbr_fd(pos_num, 2);
	ft_putstr_fd("] ", 2);
	ft_putstr_fd("\n", 2);
	exit(-1);
}

void	ft_print_syntax_error(int line_num, int pos_num,
								char *token_type, char *token_cont)
{
	ft_putstr_fd("Error [", 2);
	ft_putnbr_fd(line_num, 2);
	ft_putstr_fd(":", 2);
	ft_putnbr_fd(pos_num, 2);
	ft_putstr_fd("] ", 2);
	ft_putstr_fd(token_type, 2);
	if (*token_cont != '\0')
	{
		ft_putstr_fd(" \"", 2);
		ft_putstr_fd(token_cont, 2);
		ft_putstr_fd("\"\n", 2);
	}
	else
		ft_putstr_fd("\n", 2);
	exit(-1);
}

void	ft_error_message(int fd, char *str1, char *str2, char *str3)
{
	ft_putstr_fd(str1, fd);
	ft_putstr_fd(str2, fd);
	ft_putstr_fd(str3, fd);
	exit(-1);
}

void	ft_print_separator_error(t_line *line)
{
	ft_putstr_fd("Separator use error at line ", 2);
	ft_putnbr_fd(line->id_line, 2);
	ft_putstr_fd("\n", 2);
	exit(-1);
}
