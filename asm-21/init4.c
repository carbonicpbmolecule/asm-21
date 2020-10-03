#include "asm.h"

void	ft_init_lld(t_asm *assm)
{
	if (!(assm->lld = (t_op *)malloc(sizeof(t_op))))
		ft_error_message(2, "Memory error\n", "", "");
	assm->lld->name = "lld";
	assm->lld->id = 13;
	assm->lld->arg_num = 2;
	assm->lld->dir_type_size = 4;
	assm->lld->arg_type_code = 1;
	assm->lld->arg1_type[0] = 'd';
	assm->lld->arg1_type[1] = 'i';
	assm->lld->arg1_type[2] = '\0';
	assm->lld->arg2_type[0] = 'r';
	assm->lld->arg2_type[1] = '\0';
	assm->lld->arg2_type[2] = '\0';
	assm->lld->arg3_type[0] = '\0';
	assm->lld->arg3_type[1] = '\0';
	assm->lld->arg3_type[2] = '\0';
}

void	ft_init_lldi(t_asm *assm)
{
	if (!(assm->lldi = (t_op *)malloc(sizeof(t_op))))
		ft_error_message(2, "Memory error\n", "", "");
	assm->lldi->name = "lldi";
	assm->lldi->id = 14;
	assm->lldi->arg_num = 3;
	assm->lldi->dir_type_size = 2;
	assm->lldi->arg_type_code = 1;
	assm->lldi->arg1_type[0] = 'r';
	assm->lldi->arg1_type[1] = 'd';
	assm->lldi->arg1_type[2] = 'i';
	assm->lldi->arg2_type[0] = 'r';
	assm->lldi->arg2_type[1] = 'd';
	assm->lldi->arg2_type[2] = '\0';
	assm->lldi->arg3_type[0] = 'r';
	assm->lldi->arg3_type[1] = '\0';
	assm->lldi->arg3_type[2] = '\0';
}

void	ft_init_lfork(t_asm *assm)
{
	if (!(assm->lfork = (t_op *)malloc(sizeof(t_op))))
		ft_error_message(2, "Memory error\n", "", "");
	assm->lfork->name = "lfork";
	assm->lfork->id = 15;
	assm->lfork->arg_num = 1;
	assm->lfork->dir_type_size = 2;
	assm->lfork->arg_type_code = 0;
	assm->lfork->arg1_type[0] = 'd';
	assm->lfork->arg1_type[1] = '\0';
	assm->lfork->arg1_type[2] = '\0';
	assm->lfork->arg2_type[0] = '\0';
	assm->lfork->arg2_type[1] = '\0';
	assm->lfork->arg2_type[2] = '\0';
	assm->lfork->arg3_type[0] = '\0';
	assm->lfork->arg3_type[1] = '\0';
	assm->lfork->arg3_type[2] = '\0';
}

void	ft_init_aff(t_asm *assm)
{
	if (!(assm->aff = (t_op*)malloc(sizeof(t_op))))
		ft_error_message(2, "Memory error\n", "", "");
	assm->aff->name = "aff";
	assm->aff->id = 16;
	assm->aff->arg_num = 1;
	assm->aff->dir_type_size = 4;
	assm->aff->arg_type_code = 1;
	assm->aff->arg1_type[0] = 'r';
	assm->aff->arg1_type[1] = '\0';
	assm->aff->arg1_type[2] = '\0';
	assm->aff->arg2_type[0] = '\0';
	assm->aff->arg2_type[1] = '\0';
	assm->aff->arg2_type[2] = '\0';
	assm->aff->arg3_type[0] = '\0';
	assm->aff->arg3_type[1] = '\0';
	assm->aff->arg3_type[2] = '\0';
}

void	ft_init_aff_lld_lldi_lfork(t_asm *assm)
{
	ft_init_lld(assm);
	ft_init_lldi(assm);
	ft_init_lfork(assm);
	ft_init_aff(assm);
}
