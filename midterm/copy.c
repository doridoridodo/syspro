#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char c;
	FILE *fp1, *fp2;
	int opt;

	if(argc != 3){
		fprintf(stderr, "How to use: %s File1 File2\n", argv[0]);
		return 1;
	}
	
	fp1 = fopen(argv[1], "r");
	if(fp1 == NULL){
		fprintf(stderr, "File %s Open Error\n", argv[1]);
		return 2;
	}
	
	if((opt = getopt(argc, argv, "012")) != -1){
		switch(opt){
			case '0':
				fp2 = fopen(argv[2], "w");
				while((c = fgetc(fp1)) != EOF)
				fputc(c, fp2);
				fclose(fp1);
				fclose(fp2);
				break;

			case '1':

				break;

			case '2':
				break;

			case '?':
				printf("Unknown Flag: %c", opt);
				break;
		}
	}

	return 0;
}
