#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
extern char **environ;

int main(int argc, char* argv[])
{
	for(int i = 1; i < argc; i++){
		
		// -e
		if(strcmp(argv[i], "-e") == 0){
			if(i + 1 < argc && argv[i + 1][0] != '-'){
				char *env_var = argv[++i];
				char *value = getenv(env_var);
				if(value){
					printf("%s = %s\n", env_var, value);
			}
			}
			else{
				for(char **ptr = environ; *ptr != NULL; ptr++){
					printf("%s\n", *ptr);
				}
			}
		}
		// -u
		else if(strcmp(argv[i], "-u") == 0){
			printf("My Realistic User ID : %d(%s)\n", getuid(), getpwuid(getuid())->pw_name);
			printf("My Valid User ID : %d(%s)\n", geteuid(), getpwuid(geteuid()) -> pw_name);
		}
		// -g
		else if(strcmp(argv[i], "-g") == 0){
			printf("My Realistic Group ID : %d(%s)\n", getgid(), getgrgid(getgid())->gr_name);
			printf("My Valid Group ID : %d(%s)\n", getegid(), getgrgid(getegid())->gr_name);
		}
		// -i
		else if(strcmp(argv[i], "-i") == 0){
			printf("my process number : [%d]\n", getpid());
		}
		//-p
		else if(strcmp(argv[i], "-p") == 0){
			printf("my parent's process number : [%d]\n", getppid());
		}
	}
	return 0;
}
