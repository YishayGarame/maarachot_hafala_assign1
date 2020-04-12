#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>


int main()
{
	//create child that will be deamon
	pid_t pid =fork();
	
	if(pid==0)
	{
		//we are in child
		//move to root dir used to not block the file system
		chdir("/");
		
		//move the child to another session ,so the parent may be closed
		setsid();

		printf("starting my daemon\n");

		//close output chanels
		close(stdout);
		close(stdin);
		close(stderr);

		//open log
		openlog("myDeamon",LOG_PID,LOG_DAEMON);
		syslog(LOG_NOTICE,"daemon statred");
		usleep(30000);
		syslog(LOG_NOTICE,"doing some work ...");
		usleep(30000);
		syslog(LOG_NOTICE,"daemon finished");
	}

	else
	{
		printf("daemon PID %d\n",pid);
	}

	return 0;

}

