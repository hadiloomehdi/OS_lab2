#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
	// printf(1,"sdasdasd \n");
    int num = 531;
	int regTemp;
	asm("movl %%esi, %0" : "=r"(regTemp));
	asm("movl %0, %%esi" :: "r"(num));
	// asm("movl $22 , %eax;");
    // asm("int $64");
	cInt();
	asm("movl %0, %%esi" :: "r"(regTemp));
	exit();
}
