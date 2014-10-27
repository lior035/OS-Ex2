#include "types.h"
#include "user.h"
#include "syscall.h"
#include "traps.h"

int getppid2(void){

int ppid ;

asm volatile( "int %1" : "=a" (ppid) : "i" (T_SYSCALL) , "a" (SYS_getppid));

return ppid ;
}

int main(void){
	int fd[2];
	int err = pipe(fd);
	if (err <0){
		printf(1, "pipe creation failed !\n");
		exit();
	}
	
	int k;
	int ChildPid;
	for (k = 0; k < 2; k++){
		ChildPid = fork();
		if (ChildPid == 0)
			break;
		if (ChildPid < 0){
			printf(1, "Fork failed %d! \n", ChildPid);
			exit();
		}
		printf(1, "I am the parent. \n my pid is %d, my child id is %d", getpid(), ChildPid);
	}
	
	if (ChildPid >0) {
		char buf[300];
		int cnt, count, i;
		char last = 0;
		count = 0;
		while ( (cnt = read(fd[0],buf,300)) >= 0 ) {
			//printf(1m "cnt=%d:\n", cnt);
			for( i = 0; i < cnt ; i++){
				if(buf[i] == last) {
					count++;
				} else{
					printf(1, "Consecutive %d\n", count);
					last = buf[i];
					count = 1;
				}
			}
		}
		printf(1, "pipe read failed!\n");
	} else {
		int pid;
		printf(1, "I am the child. my pid is %d \n my parent id is %d", pid = getpid(), getppid2());
		
		char buf[300];
		int i;
		for( i = 0; i < 300; i++)
			buf[i] ='a' + pid;
		
		while(1) {
			mutex_acquire(1);	
			err = write(fd[1], buf, 300);
			if(err <0)
				printf(1,"pipe write failed!\n");
			mutex_release(1);
		}
		
		
	}
	return 0;
}