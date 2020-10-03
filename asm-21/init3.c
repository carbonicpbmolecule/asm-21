#include "asm.h"

void	ft_init_zjmp(t_asm *assm)
{
	if (!(assm->zjmp = (t_op*)malloc(sizeof(t_op))))
		ft_error_message(2, "Memory error\n", "", "");
	assm->zjmp->name = "zjmp";
	assm->zjmp->id = 9;
	assm->zjmp->arg_num = 1;
	assm->zjmp->dir_type_size = 2;
	assm->zjmp->arg_type_code = 0;
	assm->zjmp->arg1_type[0] = 'd';
	assm->zjmp->arg1_type[1] = '\0';
	assm->zjmp->arg1_type[2] = '\0';
	assm->zjmp->arg2_type[0] = '\0';
	assm->zjmp->arg2_type[1] = '\0';
	assm->zjmp->arg2_type[2] = '\0';
	assm->zjmp->arg3_type[0] = '\0';
	assm->zjmp->arg3_type[1] = '\0';
	assm->zjmp->arg3_type[2] = '\0';
}

void	ft_init_ldi(t_asm *assm)
{
	if (!(assm->ldi = (t_op*)malloc(sizeof(t_op))))
		ft_error_message(2, "Memory error\n", "", "");
	assm->ldi->name = "ldi";
	assm->ldi->id = 10;
	assm->ldi->arg_num = 3;
	assm->ldi->dir_type_size = 2;
	assm->ldi->arg_type_code = 1;
	assm->ldi->arg1_type[0] = 'r';
	assm->ldi->arg1_type[1] = 'd';
	assm->ldi->arg1_type[2] = 'i';
	assm->ldi->arg2_type[0] = 'r';
	assm->ldi->arg2_type[1] = 'd';
	assm->ldi->arg2_type[2] = '\0';
	assm->ldi->arg3_type[0] = 'r';
	assm->ldi->arg3_type[1] = '\0';
	assm->ldi->arg3_type[2] = '\0';
}

void	ft_init_sti(t_asm *assm)
{
	if (!(assm->sti = (t_op*)malloc(sizeof(t_op))))
		ft_error_message(2, "Memory error\n", "", "");
	assm->sti->name = "sti";
	assm->sti->id = 11;
	assm->sti->arg_num = 3;
	assm->sti->dir_type_size = 2;
	assm->sti->arg_type_code = 1;
	assm->sti->arg1_type[0] = 'r';
	assm->sti->arg1_type[1] = '\0';
	assm->sti->arg1_type[2] = '\0';
	assm->sti->arg2_type[0] = 'r';
	assm->sti->arg2_type[1] = 'd';
	assm->sti->arg2_type[2] = 'i';
	assm->sti->arg3_type[0] = 'r';
	assm->sti->arg3_type[1] = 'd';
	assm->sti->arg3_type[2] = '\0';
}

void	ft_init_fork(t_asm *assm)
{
	if (!(assm->fork_ = (t_op*)malloc(sizeof(t_op))))
		ft_error_message(2, "Memory error\n", "", "");
	assm->fork_->name = "fork";
	assm->fork_->id = 12;
	assm->fork_->arg_num = 1;
	assm->fork_->dir_type_size = 2;
	assm->fork_->arg_type_code = 0;
	assm->fork_->arg1_type[0] = 'd';
	assm->fork_->arg1_type[1] = '\0';
	assm->fork_->arg1_type[2] = '\0';
	assm->fork_->arg2_type[0] = '\0';
	assm->fork_->arg2_type[1] = '\0';
	assm->fork_->arg2_type[2] = '\0';
	assm->fork_->arg3_type[0] = '\0';
	assm->fork_->arg3_type[1] = '\0';
	assm->fork_->arg3_type[2] = '\0';
}

void	ft_init_zjmp_ldi_sti_fork(t_asm *assm)
{
	ft_init_zjmp(assm);
	ft_init_ldi(assm);
	ft_init_sti(assm);
	ft_init_fork(assm);
}
