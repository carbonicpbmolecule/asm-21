#include "asm.h"

int		ft_is_comment_or_empty_line(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == COMMENT_CHAR || line[i] == '\0'
	|| line[i] == ALT_COMMENT_CHAR)
		return (1);
	return (0);
}

int		ft_find_qoutes(t_line *line, int after_pos, char *command_token)
{
	int i;

	i = after_pos;
	while ((line->content)[i] == ' ' || (line->content)[i] == '\t')
		i++;
	if ((line->content)[i] == '"')
		return (i);
	else if ((line->content)[i] == '\0')
		return (-1);
	else
	{
		ft_print_syntax_error(line->id_line, i + 1, command_token, "");
		exit(1);
	}
}

int		ft_get_attribute_content_part(t_line *line,
										char **content_part, int after_pos)
{
	int		j;
	int		i;

	i = 0;
	j = -1;
	while (line->content[i + after_pos] != '"'
		&& line->content[i + after_pos] != '\0')
		i++;
	if (line->content[i + after_pos] == '\0')
	{
		if (!(*content_part = (char*)malloc(sizeof(char) * (i + 2))))
			ft_error_message(2, "Memory error\n", "", "");
		(*content_part)[i] = '\n';
		(*content_part)[i + 1] = '\0';
	}
	else
	{
		if (!(*content_part = (char *)malloc(sizeof(char) * (i + 1))))
			ft_error_message(2, "Memory error\n", "", "");
		(*content_part)[i] = '\0';
	}
	while (++j < i)
		(*content_part)[j] = line->content[j + after_pos];
	return (i);
}

int		ft_get_attribute_content(t_line *line, char **content,
								char *comnd_tkn, int after_pos)
{
	int		i;
	char	*content_part;
	char	*temp;

	if (line == NULL)
		ft_error_message(2, "There is no quotes for \"", comnd_tkn, "\"\n");
	i = ft_get_attribute_content_part(line, &content_part, after_pos);
	temp = *content;
	*content = ft_strjoin(*content, content_part);
	free(temp);
	free(content_part);
	if (line->content[i + after_pos] == '"')
	{
		while (line->content[++i + after_pos] != '\0')
			if (line->content[i + after_pos] != ' ' &&
				line->content[i + after_pos] != '\t')
			{
				if (line->content[i + after_pos] == '#')
					break ;
				ft_print_syntax_error(line->id_line, i + after_pos + 1,
						comnd_tkn, &line->content[i + after_pos]);
			}
		return (0);
	}
	return (1);
}

char	*ft_get_champ_attributes(t_line **line,
								char *cmmnd_tkn, char *champ_attrib)
{
	int		i;
	int		j;
	char	*content;
	t_line	*attr_line;

	attr_line = *line;
	content = ft_malloc_char();
	content[0] = '\0';
	i = 0;
	while (((*line)->content)[i] == ' ' || ((*line)->content)[i] == '\t')
		i++;
	if ((j = ft_find_qoutes(*line,
							i + ft_strlen(champ_attrib), cmmnd_tkn)) == -1)
		while ((*line = (*line)->next))
			if ((j = ft_find_qoutes(*line, 0, cmmnd_tkn)) != -1)
				break ;
	if (ft_get_attribute_content(*line, &content, cmmnd_tkn, j + 1))
	{
		while ((*line = (*line)->next))
			if (!(j = ft_get_attribute_content(*line, &content, cmmnd_tkn, 0)))
				break ;
		if (*line == NULL && j == 1)
			ft_print_syntax_error(attr_line->id_line, i + 1, cmmnd_tkn, "");
	}
	return (content);
}
