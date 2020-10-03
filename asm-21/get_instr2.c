#include "asm.h"

void	ft_add_label(t_label **label_header, int *id_instr, char *label_content)
{
	t_label			*new_label;
	static t_label	*last;

	if (!(new_label = (t_label *)malloc(sizeof(t_label))))
		ft_error_message(2, "Memory error\n", "", "");
	new_label->name = label_content;
	new_label->id_instr = *id_instr;
	new_label->next = NULL;
	ft_check_label_duplication(label_header, new_label);
	if (*label_header == NULL)
	{
		*label_header = new_label;
		last = new_label;
	}
	else
	{
		last->next = new_label;
		last = new_label;
	}
	(*id_instr)--;
}

int		ft_get_oper_end_pos(char *instr_content, int *i, t_asm *assm)
{
	int k;

	*i = -1;
	while (++(*i) < 16)
	{
		k = ft_strlen(assm->operations[*i]->name);
		if (!ft_strncmp(instr_content, assm->operations[*i]->name, k))
			break ;
	}
	return (k);
}

int		ft_get_instr_size(char *instr_content, t_asm *assm)
{
	int		i;
	int		j;
	int		size;
	int		k;
	char	**args;

	k = ft_get_oper_end_pos(instr_content, &i, assm);
	args = ft_strsplit(&(instr_content[k]), SEPARATOR_CHAR);
	k = i;
	size = 1 + assm->operations[k]->arg_type_code;
	i = -1;
	while (args[++i] && !(j = 0))
	{
		while (args[i][j] == ' ' || args[i][j] == '\t')
			j++;
		if (args[i][j] == 'r')
			size = size + 1;
		else if (args[i][j] == '%')
			size = size + assm->operations[k]->dir_type_size;
		else
			size = size + 2;
		free(args[i]);
	}
	free(args);
	return (size);
}
