#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int count = 0, sleep_count = 1;

int main()
{
	int num, pid1, child, status;

	printf("type num of childs : ");
	scanf("%d", &num);


	for(int i = 0; i < num; i++, count++, sleep_count++){
	pid1 = fork();
	if(pid1 == 0){
		printf("[Child %d] : Started! pid=%d, sleep=%d\n", count, getpid(), sleep_count);
		sleep(sleep_count);
		printf("[Child %d] : Killed! pid=%d, sleep=%d\n", count, getpid(), sleep_count);
		pid1 = fork();
		exit(1);
	}

	}
	child = waitpid(pid1, &status, 0);
	printf("parent killed - last child id =  %d\n", (getpid() -  child));
}
