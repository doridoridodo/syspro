#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

int p1, p2, p3, p4, p5, p6, p7;

int main()
{

	p1 = fork();
	if(p1 == 0){
		p3 = fork();
		p6 = fork();
		sleep(2);
		exit(1);
	}
	else{
		p2 = fork();
		if(p2 == 0){
			printf("Hello\n");
			p5 = fork();
			sleep(2);
			exit(1);
		}
	}
	
	if(p3  == 0){
		p7 = fork();
	}

	if(p6 == 0){
		printf("Hello\n");
	}
	else{
		p4 = fork();
	}

	if(p5  == 0){
		printf("Hello\n");
	}
	
	if(p7 == 0){
		printf("Hello\n");
	}

	printf("Hello\n");
	return 0;
}
