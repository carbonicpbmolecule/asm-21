#include "asm.h"

void	ft_init_instructions(t_asm *assm)
{
	assm->operations[0] = assm->live;
	assm->operations[1] = assm->lldi;
	assm->operations[2] = assm->lld;
	assm->operations[3] = assm->ldi;
	assm->operations[4] = assm->ld;
	assm->operations[5] = assm->sti;
	assm->operations[6] = assm->st;
	assm->operations[7] = assm->add;
	assm->operations[8] = assm->sub;
	assm->operations[9] = assm->and;
	assm->operations[10] = assm->or;
	assm->operations[11] = assm->xor;
	assm->operations[12] = assm->zjmp;
	assm->operations[13] = assm->fork_;
	assm->operations[14] = assm->lfork;
	assm->operations[15] = assm->aff;
}

void	ft_init_globals(t_asm *assm)
{
	ft_init_live_ld_st_add_operations(assm);
	ft_init_sub_and_or_xor_operations(assm);
	ft_init_zjmp_ldi_sti_fork(assm);
	ft_init_aff_lld_lldi_lfork(assm);
	ft_init_instructions(assm);
	assm->line_h = NULL;
	assm->name_h = NULL;
	assm->comment_h = NULL;
	assm->instr_h = NULL;
	assm->label_h = NULL;
}
