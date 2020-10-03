#ifndef ASM_H
# define ASM_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include "op.h"

typedef	struct	s_op
{
	char	id;
	char	*name;
	int		dir_type_size;
	int		arg_num;
	int		arg_type_code;
	char	arg1_type[3];
	char	arg2_type[3];
	char	arg3_type[3];
}				t_op;

typedef	struct	s_label
{
	int				id_instr;
	char			*name;
	struct s_label	*next;
}				t_label;

typedef	struct	s_line
{
	int				id_line;
	char			*content;
	struct s_line	*next;
}				t_line;

typedef	struct	s_instr
{
	int				id;
	char			*cont;
	unsigned char	*bytes;
	int				size;
	t_line			*line;
	struct s_instr	*next;
	struct s_instr	*prev;
}				t_instr;

typedef struct	s_assem
{
	t_op	*live;
	t_op	*ld;
	t_op	*st;
	t_op	*add;
	t_op	*sub;
	t_op	*and;
	t_op	*or;
	t_op	*xor;
	t_op	*zjmp;
	t_op	*ldi;
	t_op	*sti;
	t_op	*fork_;
	t_op	*lld;
	t_op	*lldi;
	t_op	*lfork;
	t_op	*aff;
	t_op	*operations[16];
	t_line	*line_h;
	char	*name_h;
	char	*comment_h;
	t_label	*label_h;
	t_instr	*instr_h;
}				t_asm;

t_line			*ft_get_name_and_comment(t_line *line, char **name,
														char **comment);
void			ft_print_lexical_error(int line_num, int pos_num);
void			ft_print_syntax_error(int line_num, int pos_num,
									char *token_type, char *token_cont);
char			*ft_get_champ_attributes(t_line **line, char *cmmnd_tkn,
													char *champ_attrib);
int				ft_is_comment_or_empty_line(char *line);
void			ft_instr_from_numeric_to_bytes(t_instr *instr, t_asm *assm);
int				ft_get_operation_num(char *content, t_asm *assm);
void			ft_print_nonexistent_label_1(t_instr *instr, char *label_arg);
void			ft_get_numeric_label_value(int *numeric_arg, t_instr *instr,
										t_instr *iter_instr, int lbl_instr_id);
unsigned char	ft_add_arg_code_to_byte(char **args);
void			ft_print_byte_code_into_file(t_instr *instr, int fd);
void			ft_print_magic_number(int fd2);
void			ft_print_name_into_file(char *name, int fd);
void			ft_print_exec_code_size(t_instr *instr, int fd);
void			ft_print_comment_into_file(char *comment, int fd);
void			ft_check_empty_args_1(t_line *line, int op_num, char **args,
															t_asm *assm);
void			ft_check_args(t_line *line, int op_num, char **args,
															t_asm *assm);
void			ft_check_arg_value(t_line *line, char *arg, char arg_type);
void			ft_check_args_num(t_line *line, int op_num, char **args,
															t_asm *assm);
int				ft_is_only_label(char *trim_line);
int				ft_is_only_instr(char *content, t_asm *assm);
int				ft_is_label_and_instr(char *trim_content, t_asm *assm);
void			ft_check_instr(t_line *line, char *content, t_asm *assm);
void			ft_check_label_symbols(t_line *line, char *label);
void			ft_get_instructions(t_line *line, t_asm *assm);
char			*ft_del_comment_and_trim(char *content);
void			ft_find_error(t_line *line);
void			ft_error_message(int fd, char *str1, char *str2, char *str3);
void			ft_init_live_ld_st_add_operations(t_asm *assm);
void			ft_init_sub_and_or_xor_operations(t_asm *assm);
void			ft_init_zjmp_ldi_sti_fork(t_asm *assm);
void			ft_init_aff_lld_lldi_lfork(t_asm *assm);
t_line			*ft_add_line(t_line **line, char *content);
void			ft_translate_to_byte_code(int fd_src, int fd_des, t_asm *assm);
char			*ft_get_des_file_path(char *src_path);
void			ft_check_newline_symbol_at_end_of_file(int fd,
														t_line *last_line);
void			ft_creat_byte_array(t_instr *instr, int op_num, int *pos,
															t_asm *assm);
void			ft_check_label_duplication(t_label **label, t_label *lbl);
void			ft_add_label(t_label **label_header, int *id_instr,
														char *label_content);
int				ft_get_instr_size(char *instr_content, t_asm *assm);
void			ft_init_globals(t_asm *assm);
void			ft_print_separator_error (t_line *line);
char			*ft_malloc_char(void);
int				ft_ovrint(char *str, t_instr *instr);

#endif
