#include "asm.h"

int		ft_is_read_error(int r)
{
	if (r == -1)
	{
		write(2, "Read error\n", 11);
		exit(-1);
	}
	return (r);
}

void	ft_check_newline_symbol_at_end_of_file(int fd, t_line *line)
{
	char	c;
	int		i;
	int		end_pos;

	i = 0;
	end_pos = lseek(fd, -1L, SEEK_END);
	if (end_pos == -1)
		ft_error_message(2, "The file is empty", "", "");
	read(fd, &c, 1);
	while ((line->content[i]) == ' ' || (line->content[i]) == '\t')
		i++;
	if (c != '\n' && (line->content[i] == '#'
	|| line->content[i] == ';' || line->content[i] == '\0'))
	{
		;
	}
	else if (c != '\n')
	{
		ft_putstr_fd("Error - unexpected end of input "
			"(Perhaps you forgot to end with a newline ?)\n", 2);
		exit(1);
	}
	lseek(fd, 0, SEEK_SET);
}

char	*ft_get_des_file_path(char *src_path)
{
	int		i;
	char	*des_path;

	i = 0;
	while (src_path[i])
		i++;
	while (--i >= 0)
		if (src_path[i] == '.')
			break ;
	if (src_path[i + 1] != 's' && src_path[i + 1] != '\0')
	{
		write(2, "The file must have an extension .s\n", 35);
		exit(1);
	}
	des_path = (char*)malloc(sizeof(char) * (i + 5));
	des_path[i + 1] = 'c';
	des_path[i + 2] = 'o';
	des_path[i + 3] = 'r';
	des_path[i + 4] = '\0';
	while (i >= 0)
	{
		des_path[i] = src_path[i];
		i--;
	}
	return (des_path);
}

void	ft_get_all_lines_from_src(int fd_src, t_line **line)
{
	char	*src_line;
	t_line	*last_line;

	while (ft_is_read_error(get_next_line(fd_src, &src_line)))
		last_line = ft_add_line(line, src_line);
	free(src_line);
	ft_check_newline_symbol_at_end_of_file(fd_src, last_line);
}

void	ft_translate_to_byte_code(int fd_src, int fd_des, t_asm *assm)
{
	ft_get_all_lines_from_src(fd_src, &(assm->line_h));
	ft_get_instructions(
		ft_get_name_and_comment(assm->line_h, &(assm->name_h),
		&(assm->comment_h)), assm);
	ft_instr_from_numeric_to_bytes(assm->instr_h, assm);
	ft_print_magic_number(fd_des);
	ft_print_name_into_file(assm->name_h, fd_des);
	ft_print_exec_code_size(assm->instr_h, fd_des);
	ft_print_comment_into_file(assm->comment_h, fd_des);
	ft_print_byte_code_into_file(assm->instr_h, fd_des);
}
