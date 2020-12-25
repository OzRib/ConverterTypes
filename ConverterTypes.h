/*
	Converter Types variables

	A lot of functions to convert types of variables without
	conflit. For more compatibilty with communication with
	non typed languages

	Author: Ozeias Ribeiro
	Data: 2020/12/25 (Japanese Format YYYY/MM/DD)
*/

#include <math.h>

int StringToInt(char* str, int len){
	/*Description of variables
	* cs = Possible character value in a string
	* cn = Character numeric founded in the string
	* dp = Number of decimal points
	*/
	//Declaration of variables
	char cn[10];
	int dp, result = 0;
	//Cleaner from numeric vetor
	for(int x=0;x<10;x++){
		cn[x]=0;
	}
	//Filter for character numerics
	//Obs: the middle term is the lenght of the string
	for(int x=0;x<len; x++){
		for(int y=0; y<10; y++){
			if(str[x]==(y+48)){//48 = '0' in ASCII
				cn[dp]=y;
				dp++;
			}
		}
	}
	//Mounting the number
	for(int x=0; x<dp; x++){
		/*Matematical principle of convertion
		* summ = (10^x)*vd
		* x = value of the decimal point(unit = 10⁰; decene = 10¹...)
		* vd = value in the decimal point
		*/
		int summ = (int)(pow(10, x))*(int)(cn[dp-x-1]);
		result += summ;
	}
	return result;
}

//Prototype
float StringToFloat(char* str){
	const char cs[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	float result = 0;
	int df, db = 0;
}
