#include "cpu/exec/template-start.h"

#define instr cmp

static void do_execute() {
	DATA_TYPE result = op_dest->val - op_src->val;
	update_eflags_pf_zf_sf(result);
	cpu.eflags.CF = op_dest->val < op_src->val;
	int s1, s2, len;
	len = (DATA_BYTE << 3) - 1;
	s1 = op_dest->val>>len;
	s2 = op_src->val>>len;
	cpu.eflags.OF = (s1 != s2 && s2 == cpu.eflags.SF) ;
	print_asm_template2();
}

#if DATA_BYTE == 2 || DATA_BYTE == 4
make_instr_helper(si2rm)
#endif

#include "cpu/exec/template-end.h"