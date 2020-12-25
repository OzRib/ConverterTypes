#include <stdio.h>
#include <math.h>
#include <ConverterTypes.h>

int main(){
	char b[] = "01234a";
	int a=StringToInt(b);
	printf("\nResult: %d\n", a);
	return 0;
}
