#include <stdio.h>
#include "copy.h"
#include <string.h>

char longest[MAXLINE];

main(){
	int str[5][MAXLINE];

	for(int i = 0; i < 5; i++){
		
		scanf("%s", &str[i]);

	}

	for(int i = 0; i < 4; i++){
		for(int j = i + 1; j < 5; j++){
			if(strlen(str[i]) < strlen(str[j])){
					char temp[MAXLINE];
					copy(str[i], temp);
					copy(str[j], str[i]);
					copy(temp, str[j]);
							}
							}
							}


	for(int i = 0; i < 5; i++){
	printf("%s\n", str[i]);
	}

	return 0;
}
