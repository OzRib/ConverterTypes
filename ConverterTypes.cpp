/*
	 Converter types variables

	 A lot od functions to convert types of variables without
	 conflict. for more compatibilty with communication with
	 non typed languageS.

	 Author: Ozeias Ribeiro
	 Data: 2020/12/25 (Japanese formar YYYY/MM/DD) 
*/

#include <math.h>
#include <Arduino.h>
#include "ConverterTypes.h"

int StringToInt(String str){
	 /* Description of variables
	 * str = Received string
	 * cn = Character numeric founded in the string
	 * dp = Number of decimal points
	 */
	//Declaration of variables
	char *cn = (char *) malloc(str.length()*sizeof(char)); 
	int dp = 0; 
	int result = 0;
	//Filter for character numerics
	for(int x=0;x<=str.length();x++){
		for(int y=0; y<10;y++){
			if('.'==str[x]){
				goto Endfor1;
			}else if((y+48)==str[x]){//48 = '0' in ASCII
				cn[dp]=y;
				dp++;
			}
		}
	}
	Endfor1:
	//mounting the number
	for(int x=0;x<dp;x++){
		/*Matematical principle of convertion
		 * summ = (10^x)*vd
		 * x = value of the decimal point(unit = 10⁰; decene = 10¹...)
		 */
		int summ = (int)(pow(10, x)*(int)(cn[dp-x-1]));
		result += summ;
	}
	free(cn);
	return result;
}

float StringToFloat(String str){
	/*Description of variables
	 * da = Number of decimal point after "."
	 * db = Number of decimal point before "."
	 * na = array for write the numbers after "."
	 * nb = array for write the numbers before "."
	 */
	//Declaration of variables
	float result = 0;
	bool point = false;
	int da = 0;
	int db = 0;
	char *na = (char *) malloc(str.length()*sizeof(char));
	char *nb = (char *) malloc(str.length()*sizeof(char));
	//Filter for character numerics
	for(int x=0;x<=str.length();x++){
		for(int y=0;y<10;y++){
			if('.'==str[x]){//Check if the char is the point
				point = true;
			}else if((y+48)==str[x]){//48 = '0' in ASCII
				if(true==point){//If the number passed of point..
					nb[db]=y;
					db++;
				}else{//Else
					na[da]=y;
					da++;
				}
			}
		}
	}
	//Mounting the number
	for(int x=0;x<da;x++){
		/*Matematical principle
		 * summ = (10^x)*vd
		 * x = value of the decimal point after "." (unit = 10⁰; decene = 10¹...)
		 * vd = value in the decimal point after "." */
		int summ = (int)(pow(10,x))*(int)(na[da-x-1]);
		result += summ;
	}
	for(int x=0;x<db;x++){
		/*Matematical principle
		 * summ = vd/(10^x)
		 * x = value of the decimal point after "." (unit = 10⁰; decene = 10¹...)
		 * vd = value in the decimal point*/
		float summ = (float)(nb[db-x-1])/(float)(pow(10,x+1));
		result += summ;
	}
	free(na);
	free(nb);
	return result;
}
