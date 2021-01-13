#include <math.h>
#include "ConverterTypes.h"

int StringToInt(char* str, unsigned int len){
	char cn[10] = {0,0,0,0,0,0,0,0,0,0};
	int dp, result = 0;
	
	for(int x=0;x<len;x++){
		for(int y=0; y<10;y++){
			if(str[x]==(y+48)){
				cn[dp]=y;
				dp++;
			}
		}
	}

	for(int x=0;x<dp;x++){
		int summ = (int)(pow(10, x)*(int)(cn[dp-x-1]));
		result += summ;
	}
	return result;
}

float StringToFloat(char* str, unsigned int len){
	float result = 0;
	bool point = false;
	int da, db = 0;
	int na[10], nb[10] = {0,0,0,0,0,0,0,0,0,0};

	for(int x=0;x<len;x++){
		for(int y=0;y<10;y++){
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
		int summ = (int)(pow(10,x))*(int)(na[da-x-1]);
		result += summ;
	}
	for(int x=0;x<db;x++){
		float summ = (float)(nb[db-x-1])/(float)(pow(10,x+1));
		result += summ;
	}
	return result;
}
