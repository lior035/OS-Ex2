#include "param.h"
#include "types.h"
#include "user.h"

//this progrm will carsh in xv6-rev7 
int
main()
{
  int* buffer = 0 ;//pointer to zero logic address 
  int num = 0;// just a num
  num = *buffer;//read from 0 address
  printf(1,"num is -%d-", num);//show it ti the user
  *buffer = main();//go to address wicth is not yours , it take a few time but it will go high , meaning fly away ,
  
  exit();//exit - it will end the program i hope
}