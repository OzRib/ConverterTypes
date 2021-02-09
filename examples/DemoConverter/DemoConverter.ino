#include <ConverterTypes.h>

void setup(){
	Serial.begin(9600);
	String str = "a022.22b"
	int numInt = StringToInt(str);
	float numFloat = StringToFloat(str);
	Serial.print("Integer: ");
	Serial.println(numInt);
	Serial.print("Float: ");
	Serial.println(numFloat);
}

void loop(){

}
