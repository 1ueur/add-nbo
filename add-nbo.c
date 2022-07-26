#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h>
#define MAX 1024

int main(int argc, char *argv[]) {
	FILE *fp1;
	FILE *fp2;

	uint32_t num_a;
	uint32_t num_c;
	uint32_t result;
	int len;

	// File Open
	if((fp1 = fopen("thousand.bin", "rb")) == NULL) {
		fputs(".................File open errer!\n", stderr);
		exit(1);
	}
	if((fp2 = fopen("five-hundred.bin", "rb")) == NULL) {
		fputs(".................File open error!\n", stderr);
		exit(1);
	}

	// File read
//	while((num_a = fgetc(fp1)) != EOF) {
//		printf("%02X\n", num_a); // Binary output
//	}
//	while((num_c = fgetc(fp2)) != EOF) {
//		printf("%02X\n", num_c); // Binary output
//	}
	len = fread(&num_a, MAX, 1, fp1);
	len = fread(&num_c, MAX, 1, fp2);
	num_a = ntohl(num_a);
	num_c = ntohl(num_c);

	result = num_a + num_c;
	printf("%u\n", result);

	fclose(fp1);
	fclose(fp2);

	return 0;
}

