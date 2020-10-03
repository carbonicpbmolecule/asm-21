#include "asm.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	char	*des_path;
	t_asm	*assm;

	if (argc < 2)
		ft_error_message(2, "Enter the path for the source code file\n",
						"", "");
	if (!(assm = (t_asm*)malloc(sizeof(t_asm))))
		ft_error_message(2, "Memory error\n", "", "");
	ft_init_globals(assm);
	if ((fd = open(argv[argc - 1], O_RDONLY)) < 0)
		ft_error_message(2, "Can't read source file ",
				argv[argc - 1], "\n");
	des_path = ft_get_des_file_path(argv[argc - 1]);
	fd2 = creat(des_path, 0000400 | 0000200);
	if (fd2 < 0)
		ft_error_message(2, "Can't creat destination file ", des_path, "\n");
	ft_translate_to_byte_code(fd, fd2, assm);
	ft_putstr("Writing output program to ");
	ft_putstr(des_path);
	ft_putstr("\n");
	close(fd);
	close(fd2);
	exit(0);
}
