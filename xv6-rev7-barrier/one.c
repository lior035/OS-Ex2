#include "param.h"
#include "types.h"
#include "user.h"

//this program  will read and write to 0 address 
int
main()//start of the program
{
  int* buffer = 0 ;//make the value of int* 0 
  int num = 0;// just a number
  num = *buffer;//read from buffer
  printf(1,"num is -%d- \n", num);//show it to the user
  *buffer = 1;//write to 0 address
  
  exit();//exit - exiting the program i hope
}