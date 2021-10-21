#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define WORDS_PER_SEC	((72.0 + 56.0 + 70.0 + 22.0 + 42.0)/(40+27+35+13+23))


int main() {
	float n;
	char rep[1] = "y";
	while(strcmp(rep,"n")) 
	{
		/*system("@cls||clear");*/
		printf("Enter number of words: ");
		scanf("%f", &n);
		n /= WORDS_PER_SEC;
		if(n<60)
			printf("Duration of speech:    %d s\n", (int) n);
		else if(n<3600)
			printf("Duration of speech:    %d min %d s\n", (int) n/60, (int) n%60);
		else
			printf("Duration of speech:    %d h %d min %d s\n", (int) n/3600, ((int) (n/60))%60, (int) n%60);
		
		printf("\n");
		do {
			printf("Repeat (y/n)?: ");
			scanf("%s", rep);
		} while(strcmp(rep,"y")*strcmp(rep,"n"));
		printf("\n");
	}
	return 0;
}
