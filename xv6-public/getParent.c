#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
	// printf(1,"sdasdasd \n");
	int parentPid;
    parentPid = getParent();
    printf(1,"parent pid is = %d \n",parentPid);
	exit();
}
