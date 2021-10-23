#include <stdio.h>
#include <string.h>


#define WORDS_PER_SEC	(1850/810.0)

void write_txt(float n);


int main() {
	float n;
	char rep[1] = "y";
	while(strcmp(rep,"n")) 
	{
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

		write_txt(n);
		do {
			printf("Repeat (y/n)?: ");
			scanf("%s", rep);
		} while(strcmp(rep,"y")*strcmp(rep,"n"));
		printf("\n");
	}

	return 0;
}


void write_txt(float n) {
	FILE *fw;
	fw = fopen("./log.txt", "a");
	if(fw==NULL) {
		printf("Failed to create log file!\n");
		fclose(fw);
		return;
	}

	if(n<60)
		fprintf(fw,"Duration of speech:    %d s\n", (int) n);
	else if(n<3600)
		fprintf(fw,"Duration of speech:    %d min %d s\n", (int) n/60, (int) n%60);
	else
		fprintf(fw,"Duration of speech:    %d h %d min %d s\n", (int) n/3600, ((int) (n/60))%60, (int) n%60);
	
	if(fclose(fw)==EOF) {
		printf("Failed to close log file!\n");
		return;
	}
	return;
}