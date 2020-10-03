#include "asm.h"

void	ft_add_instr(t_line *line, char *instr_content,
								int id_instr, t_asm *assm)
{
	t_instr			*ins;
	static t_instr	*last;

	if (!(ins = (t_instr *)malloc(sizeof(t_instr))))
		ft_error_message(2, "Memory error\n", "", "");
	ins->id = id_instr;
	ins->size = ft_get_instr_size(instr_content, assm);
	ins->cont = instr_content;
	ins->bytes = NULL;
	ins->line = line;
	ins->next = NULL;
	ins->prev = NULL;
	if (assm->instr_h == NULL)
	{
		assm->instr_h = ins;
		last = ins;
	}
	else
	{
		last->next = ins;
		ins->prev = last;
		last = ins;
	}
}

void	ft_add_instr_and_label(t_line *line, int *id_instr, t_asm *assm)
{
	char *label_content;
	char *instr_content;
	char *chl;
	char *temp;

	temp = ft_del_comment_and_trim(line->content);
	chl = ft_strchr(temp, LABEL_CHAR);
	*chl = '\0';
	label_content = ft_strdup(temp);
	ft_check_label_symbols(line, label_content);
	ft_add_label(&(assm->label_h), id_instr, label_content);
	(*id_instr)++;
	++chl;
	while (*chl == ' ' || *chl == '\t')
		chl++;
	instr_content = ft_strdup(chl);
	free(temp);
	ft_check_instr(line, instr_content, assm);
	ft_add_instr(line, instr_content, *id_instr, assm);
}

int		ft_if_empty_line_next(t_line **line, char *content)
{
	if (*content == '\0')
	{
		*line = (*line)->next;
		free(content);
		return (1);
	}
	return (0);
}

void	ft_check_and_add_instr(t_line *line, char *content,
							int id_instr, t_asm *assm)
{
	ft_check_instr(line, content, assm);
	ft_add_instr(line, content, id_instr, assm);
}

void	ft_get_instructions(t_line *line, t_asm *assm)
{
	static int	id_instr = 0;
	char		*content;

	while ((line))
	{
		content = ft_del_comment_and_trim(line->content);
		if (ft_if_empty_line_next(&line, content))
			continue;
		if (ft_is_only_label(content) && (++id_instr))
		{
			content[ft_strlen(content) - 1] = '\0';
			ft_add_label(&(assm->label_h), &id_instr, content);
		}
		else if (ft_is_label_and_instr(content, assm) && (++id_instr))
		{
			ft_add_instr_and_label(line, &id_instr, assm);
			free(content);
		}
		else if (ft_is_only_instr(content, assm) && (++id_instr))
			ft_check_and_add_instr(line, content, id_instr, assm);
		else
			ft_find_error(line);
		line = line->next;
	}
}
