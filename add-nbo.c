#include<stdio.h>
#include<stdint.h>

uint32_t to_little (uint32_t n) {
	uint32_t n1 = (n & 0xFF000000) >> 24;
	uint32_t n2 = (n & 0x00FF0000) >> 8;
	uint32_t n3 = (n & 0x0000FF00) << 8;
	uint32_t n4 = (n & 0x000000FF) << 24;
	return n1 | n2 | n3 | n4;
}

uint32_t sum(uint32_t n1, uint32_t n2) {
	return n1 + n2;
}

void  main(void)
{
	FILE *fp1, *fp2;
	uint32_t thousand, five_hundred;
	
	fp1 = fopen("thousand.bin", "rb");
	fread(&thousand, sizeof(uint32_t), 1, fp1);
	fclose(fp1);
	
	fp2 = fopen("five-hundred.bin", "rb");
	fread(&five_hundred,sizeof(uint32_t),  1, fp2);
	fclose(fp2);

	uint32_t result1 = to_little(thousand);
	uint32_t result2 = to_little(five_hundred);
	
	uint32_t final = sum(result1, result2);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", result1, result1, result2, result2, final, final);
}
