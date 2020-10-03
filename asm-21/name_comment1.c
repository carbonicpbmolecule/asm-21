#include "asm.h"

int		ft_is_champ_comment(t_line *line, char **comment, char *content)
{
	int i;

	i = 0;
	while (content[i] == ' ' || content[i] == '\t')
		i++;
	if (!ft_strncmp(&(content[i]),
			COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
	{
		if (*comment == NULL)
			return (1);
		else
			ft_print_syntax_error(line->id_line, i + 1,
					"COMMAND_COMMENT", ".comment");
	}
	return (0);
}

int		ft_is_champ_name(t_line *line, char **name, char *content)
{
	int i;

	i = 0;
	while (content[i] == ' ' || content[i] == '\t')
		i++;
	if (!ft_strncmp(&(content[i]),
			NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
	{
		if (*name == NULL)
			return (1);
		else
			ft_print_syntax_error(line->id_line, i + 1,
					"COMMAND_NAME", ".name");
	}
	return (0);
}

char	*ft_malloc_char(void)
{
	char	*ch;

	if (!(ch = (char*)malloc(sizeof(char))))
		ft_error_message(2, "Memory error\n", "", "");
	return (ch);
}

void	ft_check_name_and_comment(t_line *line, char *name, char *comment)
{
	if (name == NULL)
		ft_error_message(2, "There is no command \".name\"\n", "", "");
	if (comment == NULL)
		ft_error_message(2, "There is no command \".comment\"\n", "", "");
	if (ft_strlen(name) > PROG_NAME_LENGTH)
	{
		write(2, "Champion name too long (Max length ", 35);
		ft_putnbr_fd(PROG_NAME_LENGTH, 2);
		write(2, ")\n", 2);
		exit(-1);
	}
	if (ft_strlen(comment) > COMMENT_LENGTH)
	{
		write(2, "Champion comment too long (Max length ", 38);
		ft_putnbr_fd(COMMENT_LENGTH, 2);
		write(2, ")\n", 2);
		exit(-1);
	}
}

t_line	*ft_get_name_and_comment(t_line *line, char **name, char **comment)
{
	t_line *iter;

	iter = line;
	while (iter)
	{
		if (ft_is_comment_or_empty_line(iter->content))
		{
			iter = iter->next;
			continue;
		}
		if (ft_is_champ_comment(iter, comment, iter->content))
			*comment = ft_get_champ_attributes(&iter,
					"COMMENT_COMMAND", COMMENT_CMD_STRING);
		else if (ft_is_champ_name(iter, name, iter->content))
			*name = ft_get_champ_attributes(&iter,
					"NAME_COMMAND", NAME_CMD_STRING);
		else
			break ;
		if (iter == NULL)
			ft_error_message(2, "There is no quote for command at header \n",
					"", "");
		iter = iter->next;
	}
	ft_check_name_and_comment(iter, *name, *comment);
	return (iter);
}
