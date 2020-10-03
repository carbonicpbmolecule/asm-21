#include "asm.h"

void	ft_init_live(t_asm *assm)
{
	if (!(assm->live = (t_op *)malloc(sizeof(t_op))))
		ft_error_message(2, "Memory error\n", "", "");
	assm->live->name = "live";
	assm->live->id = 1;
	assm->live->dir_type_size = 4;
	assm->live->arg_num = 1;
	assm->live->arg_type_code = 0;
	assm->live->arg1_type[0] = 'd';
	assm->live->arg1_type[1] = '\0';
	assm->live->arg1_type[2] = '\0';
	assm->live->arg2_type[0] = '\0';
	assm->live->arg2_type[1] = '\0';
	assm->live->arg2_type[2] = '\0';
	assm->live->arg3_type[0] = '\0';
	assm->live->arg3_type[1] = '\0';
	assm->live->arg3_type[2] = '\0';
}

void	ft_init_ld(t_asm *assm)
{
	if (!(assm->ld = (t_op *)malloc(sizeof(t_op))))
		ft_error_message(2, "Memory error\n", "", "");
	assm->ld->name = "ld";
	assm->ld->id = 2;
	assm->ld->arg_num = 2;
	assm->ld->dir_type_size = 4;
	assm->ld->arg_type_code = 1;
	assm->ld->arg1_type[0] = 'd';
	assm->ld->arg1_type[1] = 'i';
	assm->ld->arg1_type[2] = '\0';
	assm->ld->arg2_type[0] = 'r';
	assm->ld->arg2_type[1] = '\0';
	assm->ld->arg2_type[2] = '\0';
	assm->ld->arg3_type[0] = '\0';
	assm->ld->arg3_type[1] = '\0';
	assm->ld->arg3_type[2] = '\0';
}

void	ft_init_st(t_asm *assm)
{
	if (!(assm->st = (t_op *)malloc(sizeof(t_op))))
		ft_error_message(2, "Memory error\n", "", "");
	assm->st->name = "st";
	assm->st->id = 3;
	assm->st->arg_num = 2;
	assm->st->dir_type_size = 4;
	assm->st->arg_type_code = 1;
	assm->st->arg1_type[0] = 'r';
	assm->st->arg1_type[1] = '\0';
	assm->st->arg1_type[2] = '\0';
	assm->st->arg2_type[0] = 'r';
	assm->st->arg2_type[1] = 'i';
	assm->st->arg2_type[2] = '\0';
	assm->st->arg3_type[0] = '\0';
	assm->st->arg3_type[1] = '\0';
	assm->st->arg3_type[2] = '\0';
}

void	ft_init_add(t_asm *assm)
{
	if (!(assm->add = (t_op*)malloc(sizeof(t_op))))
		ft_error_message(2, "Memory error\n", "", "");
	assm->add->name = "add";
	assm->add->id = 4;
	assm->add->arg_num = 3;
	assm->add->dir_type_size = 4;
	assm->add->arg_type_code = 1;
	assm->add->arg1_type[0] = 'r';
	assm->add->arg1_type[1] = '\0';
	assm->add->arg1_type[2] = '\0';
	assm->add->arg2_type[0] = 'r';
	assm->add->arg2_type[1] = '\0';
	assm->add->arg2_type[2] = '\0';
	assm->add->arg3_type[0] = 'r';
	assm->add->arg3_type[1] = '\0';
	assm->add->arg3_type[2] = '\0';
}

void	ft_init_live_ld_st_add_operations(t_asm *assm)
{
	ft_init_live(assm);
	ft_init_ld(assm);
	ft_init_st(assm);
	ft_init_add(assm);
}
