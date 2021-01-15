#include <ConverterTypes.h>

void setup(){
	Serial.begin(9600);
	String str = "a022.22b"
	int numInt = StringToInt(str, 8);
	float numFloat = StringToFloat(str, 8);
	Serial.print("Integer: ");
	Serial.println(numInt);
	Serial.print("Float: ");
	Serial.println(numFloat);
}

void loop(){

}
