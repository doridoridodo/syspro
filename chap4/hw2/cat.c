#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_num(FILE *fp, int *line_num ,int show_num){
	int c;

	if(show_num){
		printf("%d  ", (*line_num)++);
	}

	while((c = getc(fp)) != EOF){
		putc(c, stdout);

		if(c == '\n' && show_num){
			printf("%d  ", (*line_num)++);
		}
	}
}

int main(int argc, char *argv[])
{
	FILE *fp;
	int show_num = 0;
	int line_num = 1;
	int file_index = 1;

	if(argc < 2){
		return 1;
	}
	
	if(strcmp(argv[1], "-n") == 0){
		show_num = 1;
		file_index = 2;
	}

	for(int i = file_index; i < argc; i++){
		fp = fopen(argv[i], "r");
		
		print_num(fp, &line_num, show_num);
		fclose(fp);

	}
		
	fclose(fp);
	return 0;
}
