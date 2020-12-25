#include <stdio.h>
#include <math.h>
#include <ConverterTypes.h>

int main(){
	char b[] = "01234a";
	int a=StringToInt(b, sizeof(b));
	printf("\nResult: %d\nsizeof: %ld", a, sizeof(b));
	return 0;
}
