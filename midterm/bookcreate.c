#include <stdio.h>
#include <stdbool.h>

struct book{
	int id;
	char bookname[20];
	char author[20];
	int year;
	int numofborrow;
	bool borrow;
};

int main(int argc, char *argv[])
{
	struct book rec;
	FILE *fp;
	if(argc != 2){
		fprintf(stderr, "How to use: %s FileName\n", argv[0]);
		exit(1);
	}

	fp = fopen(argv[1], "wb");
	printf("%-4s %-8s %-10s %-5s %-12s %-6s\n", "id", "bookname", "author", "year", "numofborrow", "borrow");
	while(scanf("%d %s %s %d %d %c", &rec.id, rec.bookname, rec.author, &rec.year, &rec.numofborrow, &rec.borrow) == 6)
		fwrite(&rec, sizeof(rec), 1, fp);

	fclose(fp);

	return 0;
}
