#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include <sched.h>
#include<unistd.h>

#define STACK 10000+1
char childStack[STACK];

int nested2_1(void *parm){
printf("starts TaskB 2_1 Nested...\n\n");
    printf("Number of process id: %d \n\n", getpid());
    char * args[2]={"./nested", NULL};
    execvp(args[0],args);
}

int clone2_2(void *parm){ 
printf("starts TaskB 2_2 Clone...\n\n");
printf("Number of Id:  %d\n\n", getpid());
        char * args[2] = {"./clone",NULL};
		execvp(args[0],args);

}

int deamon2_3(void *parm){ 
printf("starts TaskB 2_3 Deamon...\n\n");
printf("Number of Id:  %d\n\n", getpid());
        char * args[2] = {"./daemon",NULL};
		execvp(args[0],args);

}

int main()
{
	int result1 = clone(nested2_1, childStack + 10000, CLONE_PARENT, 0);
        sleep(15);
	int result2 = clone(clone2_2, childStack + 10000, CLONE_PARENT, 0);
	sleep(15);
	int result3 = clone(deamon2_3, childStack + 10000, CLONE_PARENT, 0);
    return 0;
} 
