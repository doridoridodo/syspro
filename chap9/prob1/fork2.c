#include <stdio.h>
#include <stdlib.h>

int main()
{
	int pid;
	pid = fork();
	if(pid == 0){
		printf("[Child] : Hello, world! Pid=%d\n", getpid());
	}
	else{
		printf("[Parent] : Hello, world! Pid=%d\n", getpid());
	}
}
