#include <ArduinoJson.h>

int rawValue9; // A/D readings
int rawValue10;
int rawValue11;
int rawValue12;
int rawValue13;
int rawValue14;
int rawValue15;
int rawValue16;
int rawValue17;

int offset = 410; // Zero pressure adjust
int fullScale = 9630; // Max pressure (span) adjust
double pressure10; // Final Pressure
double pressure11;
double pressure12;
double pressure13;
double pressure14;
double pressure15;
double pressure16;
double pressure17;

void setup() {

  Serial.begin(9600); // This tells the Arduino to get ready to exchange messages with the Serial Monitor at a data rate of 9600 bits per second
  Serial2.begin(9600);
}

void loop() {
  Tx();
  delay(1000); // Delay loop for 1 sec at each loop.

}

void Tx() {
  rawValue9 = 0;
  rawValue10 = 0;
  rawValue11 = 0;
  rawValue12 = 0;
  rawValue13 = 0;
  rawValue14 = 0;
  rawValue15 = 0;
  rawValue16 = 0;
  rawValue17 = 0;

  for (int x9 = 0; x9 < 10; x9++) rawValue9 = rawValue9 + analogRead(A0); // To average rawValue0
  pressure10 = (rawValue9 - offset) * 700.0 / (fullScale - offset); // Adjust sensor from rawValue0 to final pressure
  for (int x10 = 0; x10 < 10; x10++) rawValue10 = rawValue10 + analogRead(A1);
  pressure11 = (rawValue10 - offset) * 700.0 / (fullScale - offset);
  for (int x11 = 0; x11 < 10; x11++) rawValue11 = rawValue11 + analogRead(A2);
  pressure12 = (rawValue11 - offset) * 700.0 / (fullScale - offset);
  for (int x12 = 0; x12 < 10; x12++) rawValue12 = rawValue12 + analogRead(A3);
  pressure13 = (rawValue12 - offset) * 700.0 / (fullScale - offset);
  for (int x12 = 0; x12 < 10; x12++) rawValue13 = rawValue13 + analogRead(A4);
  pressure14 = (rawValue13 - offset) * 700.0 / (fullScale - offset);
  for (int x12 = 0; x12 < 10; x12++) rawValue14 = rawValue14 + analogRead(A5);
  pressure15 = (rawValue14 - offset) * 700.0 / (fullScale - offset);
  for (int x12 = 0; x12 < 10; x12++) rawValue15 = rawValue15 + analogRead(A6);
  pressure16 = (rawValue15 - offset) * 700.0 / (fullScale - offset);
  for (int x12 = 0; x12 < 10; x12++) rawValue16 = rawValue16 + analogRead(A7);
  pressure17 = (rawValue16 - offset) * 700.0 / (fullScale - offset);

  while (!Serial2); // While did't use serial1 port create json object.
  DynamicJsonBuffer jSonDv2; // Start json with dynamic
  JsonObject& TxDevice2 = jSonDv2.createObject(); // Create an json object
  TxDevice2["Device_Name_2"] = "Device_2"; // Set Device2 name to Device_2 for communicate with Rx
  TxDevice2["SensorPoint_10"] = 0.06; // Pressure from sensor send to Rx
  TxDevice2["Sensor_10"] = pressure10; // At point compare with chord
  TxDevice2["SensorPoint_11"] = 0.12;
  TxDevice2["Sensor_11"] = pressure11;
  TxDevice2["SensorPoint_12"] = 0.2;
  TxDevice2["Sensor_12"] = pressure12;
  TxDevice2["SensorPoint_13"] = 0.3;
  TxDevice2["Sensor_13"] = pressure13;
  TxDevice2["SensorPoint_14"] = 0.5;
  TxDevice2["Sensor_14"] = pressure14;
  TxDevice2["SensorPoint_15"] = 0.72;
  TxDevice2["Sensor_15"] = pressure15;
  TxDevice2["SensorPoint_16"] = 0.89;
  TxDevice2["Sensor_16"] = pressure16;
  TxDevice2["SensorPoint_17"] = 0.95;
  TxDevice2["Sensor_17"] = pressure17;
  String device2 = "";
  TxDevice2.prettyPrintTo(device2); // Collect json TxDevice1 to device1
  Serial.print(device2); // Send json to Rx
  Serial2.print(device2); // Send json to Rx

}
