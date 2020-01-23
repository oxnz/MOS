#ifndef __PROTOS_H__
#define __PROTOS_H__

#include <yaosa/types.h>

struct Selector
{
	__ku16	addr:13;
	__ku16	TI:1;
	__ku16	RPL:2;
}__attribute__((packed));

struct IDT_entry
{
	__ku16	base_low;
	__ku16	sel;
	__ku16	flags;
	__ku16	base_hi;
}__attribute__((packed));

struct GDT_entry
{
	__ku16	limit_low;
	__ku16	base_low;
	__ku8	base_mid;
	__ku16	type;
	__ku8	base_high;
}__attribute__((packed));

struct LDT_entry
{
	__ku16	limit_low;
	__ku16	base_low;
	__ku8	base_mid;
	__ku16	type;
	__ku8	base_high;
}__attribute__((packed));

struct DESC_ptr
{
	__ku16	limit;
	__ku32	base;
}__attribute__((packed));

struct Regs
{
	/* pushed last */
	__ku32 gs;
	__ku32 fs;
	__ku32 es;
	__ku32 ds;
	/* pushed by 'pusha' */
	__ku32 edi;
	__ku32 esi;
	__ku32 ebp;
	__ku32 esp;
	__ku32 ebx;
	__ku32 edx;
	__ku32 ecx;
	__ku32 eax;

	__ku32 int_no;
	__ku32 err_code;
	/* pushed by the processor automatically */
	__ku32 eip;
	__ku32 cs;
	__ku32 eflags;
	__ku32 useresp;
	__ku32 ss;
};

#endif//__PROTOS_H__
