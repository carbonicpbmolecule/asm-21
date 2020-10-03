#include "asm.h"

void	ft_check_label_duplication(t_label **label, t_label *lbl)
{
	t_label *iter;

	iter = *label;
	while (iter)
	{
		if (!ft_strcmp(iter->name, lbl->name))
		{
			write(2, "error: label duplication (", 26);
			ft_putstr_fd(iter->name, 2);
			write(2, ")\n", 2);
			exit(-1);
		}
		iter = iter->next;
	}
}

char	*ft_del_comment_and_trim(char *content)
{
	int		i;
	char	*no_comment;
	char	*temp;

	i = -1;
	while (content[++i])
	{
		if (content[i] == ALT_COMMENT_CHAR || content[i] == COMMENT_CHAR)
		{
			no_comment = (char*)malloc(sizeof(char) * (i + 1));
			no_comment[i] = '\0';
			i--;
			while (i >= 0)
			{
				no_comment[i] = content[i];
				i--;
			}
			temp = no_comment;
			no_comment = ft_strtrim(no_comment);
			free(temp);
			return (no_comment);
		}
	}
	temp = ft_strtrim(content);
	return (temp);
}

void	ft_find_error(t_line *line)
{
	int		i;
	char	**lecs;
	char	*chl;
	char	*content;

	content = ft_strdup(line->content);
	i = -1;
	while (content[++i])
	{
		if (content[i] == '\t')
			content[i] = ' ';
	}
	lecs = ft_strsplit(content, ' ');
	i = 0;
	if (ft_is_only_label(lecs[0]))
	{
		chl = ft_strchr(content, LABEL_CHAR);
		chl++;
		while (*chl == ' ' || *chl == '\t')
			chl++;
		ft_print_lexical_error(line->id_line, chl - content + 1);
	}
	else
		ft_print_lexical_error(line->id_line,
				ft_strstr(content, lecs[0]) - content + 1);
}

t_line	*ft_add_line(t_line **line, char *content)
{
	t_line			*new_line;
	static t_line	*last_line;
	static int		id_line = 0;

	new_line = (t_line*)malloc(sizeof(t_line));
	new_line->id_line = (++id_line);
	new_line->content = content;
	new_line->next = NULL;
	if (*line == NULL)
	{
		*line = new_line;
		last_line = new_line;
	}
	else
	{
		last_line->next = new_line;
		last_line = new_line;
	}
	return (last_line);
}

void	ft_creat_byte_array(t_instr *instr, int op_num, int *pos, t_asm *assm)
{
	instr->bytes = (unsigned char*)malloc(sizeof(unsigned char) * instr->size);
	instr->bytes[0] = (assm->operations[op_num]->id);
	*pos = 1;
}
