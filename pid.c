#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int count = 1;

int main()
{
	int num;
	printf("type num of childs : ");
	scanf("%d", &num);
	
	int pid, child, status;

	if(num != 0){
	if((pid = fork()) == 0){
		printf("[Child %d] Started! pid=%d, sleep=%d\n", count - 1, getpid(), count);
		pid = fork();

		sleep(count);
		printf("[Child %d] Killed! pid=%d, sleep=%d\n", count - 1, getpid(), count);
		count++;
		num--;
	}
	else{
	child = waitpid(pid, &status, 0);
	printf("parent killed - last child id = %d\n", getpid() - child);
		}	
	}
}
