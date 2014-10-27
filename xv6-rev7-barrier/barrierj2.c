#include "types.h"
#include "user.h"
#include "syscall.h"
#include "traps.h"

int main(void){
	int barrier_id = 2;
	int ChildPid;
	int i;
	barrier_join(barrier_id);
	
	for( i = 0; i < 5; i++){
		ChildPid = fork();
		if(ChildPid>0){
		} 
		if(ChildPid == 0){
			break;
		}
		if( ChildPid < 0){
			//fork failed
		}
	}
	
	if(ChildPid>0){
		barrier_wait();
		//wait();
	} 
	if(ChildPid == 0){
		barrier_wait();
		
		//exit();
	}
	
	while(1){}
	return 0;
}