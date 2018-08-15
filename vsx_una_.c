#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main() {

unsigned int i;

for (i=0; i < 1024*1024*1024; i++);
for (i=0; i < 1024*1024*1024; i++);
// for (i=0; i < 1024*1024*1024; i++);
// for (i=0; i < 1024*1024*1024; i++);

asm goto (

#ifdef FP
"       fadd            10, 10, 10              ;" // Touch FP
#endif

#ifdef VEC
"       vaddcuw         10, 10, 10              ;" // Touch VEC
#endif

   "1: tbegin.              ;"
   "beq %l[failure_handler] ;"
   "xxmrghd 31, 33, 34      ;"
   "tend.                   ;"
   "b %l[exit_ok]           ;"
   :
   :
   :
   : failure_handler, exit_ok
   );

failure_handler:
	printf("fail\n");
	exit(1);

exit_ok:
	printf("pass\n"); 
	exit(0);
}
