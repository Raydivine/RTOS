#include "Task.h"

uint8_t taskOneStack[1028];
uint8_t taskTwoStack[1028];

Tcb mainTcb;
Tcb taskOneTcb;
Tcb taskTwoTcb;

void taskOne(void){
  return  ;
}

void initTcb(){
	CpuContext *cc;
	cc = (CpuContext*)(((uint32_t)&taskOneStack[1027]) - sizeof(CpuContext));
	taskOneTcb.sp = (uint32_t)cc;


	cc->R4 =0x4444;
	cc->R5 =0x5555;
	cc->R6 =0x6666;
	cc->R7 =0x7777;
	cc->R8 =0x8888;
	cc->R9 =0x9999;
	cc->R10 =0xAAAA;
	cc->R11 =0xBBBB;
	cc->R1 =0x1111;
	cc->R2 =0x2222;
	cc->R3 =0x3333;
	cc->R12 =0xCCCC;
	cc->LR =0xFEFA;
	cc->PC =0x4444;
	cc->xPSR =0x4444;

	mainTcb.name = "main_thread";
	mainTcb.sp = 0;
	taskOneTcb.name = "thread #1";
	taskOneTcb.sp = &taskOneStack[1028];
}