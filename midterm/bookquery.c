#include <stdio.h>
#include <stdbool.h>

struct book{
	int id;
	char bookname;
	char author;
	int year;
	int numofborrow;
	bool borrow
};

int main(int argc, char *argv[]){
	struct book rec;
	FILE *fp;
	
	if(argc != 2){
		fprintf(stderr, "How to use: %s FileName\n", argv[0]);
		return 1;
	}

	if((fp = fopen(argv[1], "rb")) == NULL){
		fprintf(stderr, "Error open File\n");
		return 2;
	}

	printf("%4s %9s %10s %5s %11s %5s\n", "id", "bookname", "author", "year", "numofborrow", "borrow");

	while(fread(&rec, sizeof(rec), 1, fp) > 0)
			if(rec.id != 0)
				printf("%4d %9s %10s %5d %11d %5d\n", rec.id, rec.bookname, rec.author, rec.year, rec.numofborrow, rec.borrow);
	
	
	fclose(fp);

	return 0;
}
