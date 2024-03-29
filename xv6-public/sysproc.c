#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

//////////////////////////////////////////

int sys_cInt(void)
{
  int num,counter=0;
  
  asm("movl %%esi, %0" : "=r"(num));
  // cprintf("here%d\n",num);
  while(num/10 != 0)
  {
    num = num/10;
    counter +=1;
  }
  counter += 1;
  cprintf("numbers of digit = %d\n",counter);
  return 0;
}


int sys_getParent(void)
{
  // int a =  getParent();  
  // cprintf("his %d\n", a);
  return myproc()->parent->pid;
}

int sys_getChildren(void)
{
  int pid;
  if(argint(0, &pid) < 0)
    return -1;
  return Children(pid);

}


int sys_manualSleep(void)
{
  int delay;
  if(argint(0, &delay) < 0)
    return -1;  
  int first =sys_uptime() ,now;
  cprintf("before sleep %d\n",first);
  while (1 )
  {
    now =sys_uptime();
    if(now - first == delay*100 )
      break; 
  }
  cprintf("before sleep %d\n",now);
  return 0;
}

int sys_setPath (void) {
  return setExecPath();
}

