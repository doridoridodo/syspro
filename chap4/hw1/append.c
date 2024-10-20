#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	FILE *file1, *file2;
	char c;

	file1 = fopen(argv[1], "r");
	if(file1 == NULL){
		return 1;
	}
	
	file2 = fopen(argv[2], "r+");
	if(file2 == NULL){
		return 1;
	}
	
	fseek(file2, -1, SEEK_END);

	while((c = fgetc(file1)) != EOF){
			fputc(c, file2);
	}

	fclose(file1);
	fclose(file2);

	return 0;
}
