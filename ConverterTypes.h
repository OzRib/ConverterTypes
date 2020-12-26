/*
	Converter Types variables

	A lot of functions to convert types of variables without
	conflit. For more compatibilty with communication with
	non typed languages

	Author: Ozeias Ribeiro
	Data: 2020/12/25 (Japanese Format YYYY/MM/DD)
*/

#include <math.h>

//Converter String to Int
int StringToInt(char* str, unsigned int len){
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

//Converter String to Float
float StringToFloat(char* str, unsigned int len){
	float result = 0;
	bool point = false;
	int da, db = 0;
	int na[10], nb[10];
	for(int x=0;x<10;x++){
		na[x], nb[x] = 0;
	}
	for(int x=0;x<len; x++){
		for(int y=0; y<10; y++){
			if('.' == str[x]){
				point = true;
			}else if((y+48)==str[x]){
				if(point){
					nb[db]=y;
					db++;
				}else{
					na[da]=y;
					da++;
				}
			}
		}
	}
	for(int x=0;x<da;x++){
		int summ = (int)(pow(10, x))*(int)(na[da-x-1]);
		result += summ;
	}
	for(int x=0;x<db;x++){
		float summ = (float)(nb[db-x-1])/(float)(pow(10,x+1));
		result += summ;
	}
	return result;
}
