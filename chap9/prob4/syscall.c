#include <stdio.h>
#include <sys/wait.h>

int main()
{
	int status;
	if((status = system("date")) < 0)
		perror("system() error");
	printf("end code %d\n", WEXITSTATUS(status));

	if((status = system("hello")) < 0)
		perror("system() error");
	printf("end code %d\n", WEXITSTATUS(status));

	if((status = system("who; exit44")) < 0)
		perror("system() error");
	printf("end code %d\n", WEXITSTATUS(status));
}
