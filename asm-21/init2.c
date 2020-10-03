#include "asm.h"

void	ft_init_sub(t_asm *assm)
{
	if (!(assm->sub = (t_op *)malloc(sizeof(t_op))))
		ft_error_message(2, "Memory error\n", "", "");
	assm->sub->name = "sub";
	assm->sub->id = 5;
	assm->sub->arg_num = 3;
	assm->sub->dir_type_size = 4;
	assm->sub->arg_type_code = 1;
	assm->sub->arg1_type[0] = 'r';
	assm->sub->arg1_type[1] = '\0';
	assm->sub->arg1_type[2] = '\0';
	assm->sub->arg2_type[0] = 'r';
	assm->sub->arg2_type[1] = '\0';
	assm->sub->arg2_type[2] = '\0';
	assm->sub->arg3_type[0] = 'r';
	assm->sub->arg3_type[1] = '\0';
	assm->sub->arg3_type[2] = '\0';
}

void	ft_init_and(t_asm *assm)
{
	if (!(assm->and = (t_op *)malloc(sizeof(t_op))))
		ft_error_message(2, "Memory error\n", "", "");
	assm->and->name = "and";
	assm->and->id = 6;
	assm->and->arg_num = 3;
	assm->and->dir_type_size = 4;
	assm->and->arg_type_code = 1;
	assm->and->arg1_type[0] = 'r';
	assm->and->arg1_type[1] = 'd';
	assm->and->arg1_type[2] = 'i';
	assm->and->arg2_type[0] = 'r';
	assm->and->arg2_type[1] = 'd';
	assm->and->arg2_type[2] = 'i';
	assm->and->arg3_type[0] = 'r';
	assm->and->arg3_type[1] = '\0';
	assm->and->arg3_type[2] = '\0';
}

void	ft_init_or(t_asm *assm)
{
	if (!(assm->or = (t_op *)malloc(sizeof(t_op))))
		ft_error_message(2, "Memory error\n", "", "");
	assm->or->name = "or";
	assm->or->id = 7;
	assm->or->arg_num = 3;
	assm->or->dir_type_size = 4;
	assm->or->arg_type_code = 1;
	assm->or->arg1_type[0] = 'r';
	assm->or->arg1_type[1] = 'd';
	assm->or->arg1_type[2] = 'i';
	assm->or->arg2_type[0] = 'r';
	assm->or->arg2_type[1] = 'd';
	assm->or->arg2_type[2] = 'i';
	assm->or->arg3_type[0] = 'r';
	assm->or->arg3_type[1] = '\0';
	assm->or->arg3_type[2] = '\0';
}

void	ft_init_xor(t_asm *assm)
{
	if (!(assm->xor = (t_op *)malloc(sizeof(t_op))))
		ft_error_message(2, "Memory error\n", "", "");
	assm->xor->name = "xor";
	assm->xor->id = 8;
	assm->xor->arg_num = 3;
	assm->xor->dir_type_size = 4;
	assm->xor->arg_type_code = 1;
	assm->xor->arg1_type[0] = 'r';
	assm->xor->arg1_type[1] = 'd';
	assm->xor->arg1_type[2] = 'i';
	assm->xor->arg2_type[0] = 'r';
	assm->xor->arg2_type[1] = 'd';
	assm->xor->arg2_type[2] = 'i';
	assm->xor->arg3_type[0] = 'r';
	assm->xor->arg3_type[1] = '\0';
	assm->xor->arg3_type[2] = '\0';
}

void	ft_init_sub_and_or_xor_operations(t_asm *assm)
{
	ft_init_sub(assm);
	ft_init_and(assm);
	ft_init_or(assm);
	ft_init_xor(assm);
}
