#include "types.h"
#include "user.h"
#include "syscall.h"
#include "traps.h"

int main(void){
	int barrier_id = 1;
	
	if(barrier_join(barrier_id) == 1){
		printf(1,"My process id is: %d, and I Joined barrier %d\n", getpid(),barrier_id);
	}else{
		printf(1,"My process id is: %d, and I Failed joining barrier %d\n", getpid(),barrier_id);
	};
	
	if(barrier_join(barrier_id) == 1){
		printf(1,"My process id is: %d, and I Joined barrier %d\n", getpid(),barrier_id);
	}else{
		printf(1,"My process id is: %d, and I Failed joining barrier %d\n", getpid(),barrier_id);
	};
	
	if(barrier_leave() == 1){
		printf(1,"My process id is: %d, and I Left barrier %d\n", getpid(),barrier_id);
	}else{
		printf(1,"My process id is: %d, and I Failed leaving barrier %d\n", getpid(),barrier_id);
	};
	
	if(barrier_leave() == 1){
		printf(1,"My process id is: %d, and I Left barrier %d\n", getpid(),barrier_id);
	}else{
		printf(1,"My process id is: %d, and I Failied leaving barrier %d\n", getpid(),barrier_id);
	};
	
	exit();
}