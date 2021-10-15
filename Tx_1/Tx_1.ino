#include <ArduinoJson.h>


int rawValue0; // A/D readings
int rawValue1;
int rawValue2;
int rawValue3;
int rawValue4;
int rawValue5;
int rawValue6;
int rawValue7;
int rawValue8;
int rawValue9;
int offset = 410; // zero pressure adjust
int fullScale = 9630; // max pressure (span) adjust
double pressure1; // final pressure
double pressure2;
double pressure3;
double pressure4;
double pressure5;
double pressure6;
double pressure7;
double pressure8;
double pressure9;

void setup() {

  Serial.begin(9600); // This tells the Arduino to get ready to exchange messages with the Serial Monitor at a data rate of 9600 bits per second
  Serial1.begin(9600);
}

void loop() {
  Tx();
  delay(1000); // Delay loop for 1 sec at each loop.

}

void Tx() {
  rawValue0 = 0;
  rawValue1 = 0;
  rawValue2 = 0;
  rawValue3 = 0;
  rawValue4 = 0;
  rawValue5 = 0;
  rawValue6 = 0;
  rawValue7 = 0;
  rawValue8 = 0;

  for (int x0 = 0; x0 < 10; x0++) rawValue0 = rawValue0 + analogRead(A0); // To average rawValue0
  pressure1 = (rawValue0 - offset) * 700.0 / (fullScale - offset); // Adjust sensor from rawValue0 to final pressure
  for (int x1 = 0; x1 < 10; x1++) rawValue1 = rawValue1 + analogRead(A1);
  pressure2 = (rawValue1 - offset) * 700.0 / (fullScale - offset);
  for (int x2 = 0; x2 < 10; x2++) rawValue2 = rawValue2 + analogRead(A2);
  pressure3 = (rawValue2 - offset) * 700.0 / (fullScale - offset);
  for (int x3 = 0; x3 < 10; x3++) rawValue3 = rawValue3 + analogRead(A3);
  pressure4 = (rawValue3 - offset) * 700.0 / (fullScale - offset);
  for (int x4 = 0; x4 < 10; x4++) rawValue4 = rawValue4 + analogRead(A4);
  pressure5 = (rawValue4 - offset) * 700.0 / (fullScale - offset);
  for (int x5 = 0; x5 < 10; x5++) rawValue5 = rawValue5 + analogRead(A5);
  pressure6 = (rawValue5 - offset) * 700.0 / (fullScale - offset);
  for (int x6 = 0; x6 < 10; x6++) rawValue6 = rawValue6 + analogRead(A6);
  pressure7 = (rawValue6 - offset) * 700.0 / (fullScale - offset);
  for (int x7 = 0; x7 < 10; x7++) rawValue7 = rawValue7 + analogRead(A7);
  pressure8 = (rawValue7 - offset) * 700.0 / (fullScale - offset);
  for (int x8 = 0; x8 < 10; x8++) rawValue8 = rawValue8 + analogRead(A8);
  pressure9 = (rawValue8 - offset) * 700.0 / (fullScale - offset);

  while (!Serial1); // While did't use serial1 port create json object.
  DynamicJsonBuffer jSonDv1; // Start json with dynamic
  JsonObject& TxDevice1 = jSonDv1.createObject(); // Create an json object
  TxDevice1["Device_Name_1"] = "Device_1"; // Set Device1 name to Device_1 for communicate with Rx
  TxDevice1["SensorPoint_0"] = 0.00; // Leading Edge
  TxDevice1["Sensor_0"] = pressure1; // Pressure from sensor send to Rx
  TxDevice1["SensorPoint_1"] = 0.06; // At point compare with chord
  TxDevice1["Sensor_1"] = pressure2;
  TxDevice1["SensorPoint_2"] = 0.12;
  TxDevice1["Sensor_2"] = pressure3;
  TxDevice1["SensorPoint_3"] = 0.2;
  TxDevice1["Sensor_3"] = pressure4;
  TxDevice1["SensorPoint_4"] = 0.3;
  TxDevice1["Sensor_4"] = pressure5;
  TxDevice1["SensorPoint_5"] = 0.5;
  TxDevice1["Sensor_5"] = pressure6;
  TxDevice1["SensorPoint_7"] = 0.72;
  TxDevice1["Sensor_7"] = pressure7;
  TxDevice1["SensorPoint_8"] = 0.89;
  TxDevice1["Sensor_8"] = pressure8;
  TxDevice1["SensorPoint_9"] = 0.95;
  TxDevice1["Sensor_9"] = pressure9;
  String device1 = "";
  TxDevice1.prettyPrintTo(device1); // Collect json TxDevice1 to device1
  Serial.print(device1); // Send json to Rx
  Serial1.print(device1); // Send json to Rx
}


