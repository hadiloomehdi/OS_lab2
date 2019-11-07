#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int pid = *argv[1] - '0';
	int children;
    
    children = getChildren(pid);
    printf(1,"children are = %d \n",children);
	exit();
}
