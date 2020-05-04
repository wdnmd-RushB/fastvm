﻿
#if defined(__cplusplus)
extern "C" {
#endif

#ifndef __arm_emu_h__
#define __arm_emu_h__

#include "vm.h"

    /* 在机器上运行模拟器时，自己的机器叫host，模拟器里的环境叫target*/
struct arm_emu_create_param
{
    unsigned char*  code;
    int             code_len;
	void			*user_ctx;
	int(*inst_func)(unsigned char *inst, int len,  char *inst_str, void *user_ctx);

    int             dump_dfa;
    int             dump_enfa;
    /* function base address */
    int             baseaddr;
    /* is thumb instruction */
    int             thumb;
};

struct arm_emu*		arm_emu_create(struct arm_emu_create_param *param);
void				arm_emu_destroy(struct arm_emu *);

/*

 @return	0		success
			1		finish
			<0		error
*/
int					arm_emu_run(struct arm_emu *vm);
int					arm_emu_run_once(struct arm_emu *vm, unsigned char *code, int code_len);

#endif /* __arm_emu_h__ */

#if defined(__cplusplus)
}
#endif