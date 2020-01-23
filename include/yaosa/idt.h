#ifndef __IDT_H__
#define __IDT_H__

typedef struct
{
	__ku16	intH_low;
	__ku16	code_sel;
	__ku16	type;
	__ku16	intH_hi;
}__attribute__((packed))IDT_Entry;

#endif//__IDT_H__
