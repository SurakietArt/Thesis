#include <ArduinoJson.h>

int i = 0;
boolean waite_done = false;
String value_1 = "----";
String value_2 = "----";
String value_3 = "----";
String value_4 = "----";
String value_5 = "----";
String value_6 = "----";
String value_7 = "----";
String value_8 = "----";
String value_x = "----";
String point_1 = "----";
String point_2 = "----";
String point_3 = "----";
String point_4 = "----";
String point_5 = "----";
String point_6 = "----";
String point_7 = "----";
String point_8 = "----";
int rawValuePitot;
int rawValueStatic;
int offset = 410; // Zero pressure adjust
int fullScale = 9630; // Max pressure (span) adjust
double pressurePitot; // Pressure from Pitot sensor
double pressureStatic; // Pressure from Static sensor
unsigned long startTime = millis();

void setup() {

  Serial.begin(9600);
  Serial2.begin(9600);
  Serial1.begin(9600);

  Serial.println("CLEARDATA"); // clears sheet starting at row 2
  Serial.println("CLEARSHEET"); // clears sheet starting at row 1

  // define 5 columns named "Date", "Time", "Counter", "Airfoil_Point" "Pressure" "Pitot" "Static" "AirSpeed" and "Cp"
  Serial.println("LABEL,Date,Time,Counter,Airfoil_Point,Pressure,Pitot,Static,AirSpeed,Cp");

  // set the names for the 3 checkboxes
  Serial.println("CUSTOMBOX1,LABEL,Just Box 1");
  Serial.println("CUSTOMBOX2,LABEL,Just Box 2");
  Serial.println("CUSTOMBOX3,LABEL,Just Box 3");

  // check 2 of the 3 checkboxes (first two to true, third to false)
  Serial.println("CUSTOMBOX1,SET,0");
  Serial.println("CUSTOMBOX2,SET,0");
  Serial.println("CUSTOMBOX3,SET,0");
}

void loop() {
  Pitot_Static();
  get_Serial_1() ;
  get_Serial_2();
  check_value();

}

void check_value() {

  if (  millis() - startTime >= 2000 ) {
    i = i + 1;

    float airspeed = ((2 * (pressureStatic - pressurePitot)) / 1.225); // To calculate airspeed.
    //Lower Surface
    //Cp1
    float value1_float = value_1.toFloat();
    float Cp1 = (101454.972625 - pressureStatic) / ((1.225 * airspeed) / 2);
    //Cp2
    float value2_float = value_2.toFloat();
    float Cp2 = (101251.203 - pressureStatic) / ((1.225 * airspeed) / 2);
    //Cp3
    float value3_float = value_3.toFloat();
    float Cp3 = (101220.938 - pressureStatic) / ((1.225 * airspeed) / 2);
    //Cp4
    float value4_float = value_4.toFloat();
    float Cp4 = (101200.469 - pressureStatic) / ((1.225 * airspeed) / 2);
    //Cp5
    float value5_float = value_5.toFloat();
    float Cp5 = (101197.539 - pressureStatic) / ((1.225 * airspeed) / 2);
    //Cp6
    float value6_float = value_6.toFloat();
    float Cp6 = (101228.273 - pressureStatic) / ((1.225 * airspeed) / 2);
    //Cp7
    float value7_float = value_7.toFloat();
    float Cp7 = (101265.398 - pressureStatic) / ((1.225 * airspeed) / 2);
    //Cp8
    float value8_float = value_8.toFloat();
    float Cp8 = (101310.508 - pressureStatic) / ((1.225 * airspeed) / 2);
    //Upper Surface
    //Cp9
    float value9_float = value_9.toFloat();
    float Cp9 = (101328.648 - pressureStatic) / ((1.225 * airspeed) / 2);
    //Cp10
    float value10_float = value_10.toFloat();
    float Cp10 = (101274.352 - pressureStatic) / ((1.225 * airspeed) / 2);
    //Cp11
    float value11_float = value_11.toFloat();
    float Cp11 = (101293.125 - pressureStatic) / ((1.225 * airspeed) / 2);
    //Cp12
    float value12_float = value_12.toFloat();
    float Cp12 = (101310.516 - pressureStatic) / ((1.225 * airspeed) / 2);
    //Cp13
    float value13_float = value_13.toFloat();
    float Cp13 = (101325.797 - pressureStatic) / ((1.225 * airspeed) / 2);
    //Cp14
    float value14_float = value_14.toFloat();
    float Cp14 = (101337.75 - pressureStatic) / ((1.225 * airspeed) / 2);
    //Cp15
    float value15_float = value_15.toFloat();
    float Cp15 = (101347.7265 - pressureStatic) / ((1.225 * airspeed) / 2);
    //Cp16
    float value16_float = value_16.toFloat();
    float Cp16 = (101352.586 - pressureStatic) / ((1.225 * airspeed) / 2);
    //Cp17
    float value17_float = value_17.toFloat();
    float Cp17 = (101356.461 - pressureStatic) / ((1.225 * airspeed) / 2);

    //Row2
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,I,2," + String(Cp9, 4));
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,E,2," + value_1);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,2,0.06");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,2," + i);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,B,2,TIME,");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,A,2,DATE,");
    //Row3
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,I,3," + String(Cp10, 4));
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,E,3," + value_2);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,3,0.12");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,3," + i);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,B,3,TIME,");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,A,3,DATE,");
    //Row4
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,I,4," + String(Cp11, 4));
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,E,4," + value_3);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,4,0.2");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,4," + i);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,B,4,TIME,");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,A,4,DATE,");
    //Row5
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,I,5," + String(Cp12, 4));
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,E,5," + value_4);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,5,0.3");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,5," + i);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,B,5,TIME,");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,A,5,DATE,");
    //Row6
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,I,6," + String(Cp13, 4));
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,E,6," + value_5);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,6,0.50");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,6," + i);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,B,6,TIME,");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,A,6,DATE,");
    //Row7
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,I,7," + String(Cp14, 4));
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,E,7," + value_6);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,7,0.72");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,7," + i);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,B,7,TIME,");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,A,7,DATE,");
    //Row8
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,I,8," + String(Cp15, 4));
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,E,8," + value_7);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,8,0.89");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,8," + i);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,B,8,TIME,");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,A,8,DATE,");
    //Row9
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,I,9," + String(Cp16, 4));
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,E,9," + value_8);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,9,0.95");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,9," + i);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,B,9,TIME,");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,A,9,DATE,");

    //Lower Surface
    //Row10
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,I,10," + String(Cp1, 4));
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,E,10," + value_1);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,10,0.06");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,10," + i);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,B,10,TIME,");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,A,10,DATE,");
    //Row11
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,I,11," + String(Cp2, 4));
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,E,11," + value_2);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,11,0.12");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,11," + i);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,B,11,TIME,");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,A,11,DATE,");
    //Row12
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,I,12," + String(Cp3, 4));
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,E,12," + value_3);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,12,0.2");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,12," + i);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,B,12,TIME,");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,A,12,DATE,");
    //Row13
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,I,13," + String(Cp4, 4));
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,E,13," + value_4);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,13,0.3");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,13," + i);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,B,13,TIME,");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,A,13,DATE,");
    //Row14
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,I,14," + String(Cp5, 4));
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,E,14," + value_5);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,14,0.50");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,14," + i);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,B,14,TIME,");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,A,14,DATE,");
    //Row15
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,I,15," + String(Cp6, 4));
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,E,15," + value_6);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,15,0.72");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,15," + i);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,B,15,TIME,");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,A,15,DATE,");
    //Row16
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,I,16," + String(Cp7, 4));
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,E,16," + value_7);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,16,0.89");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,16," + i);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,B,16,TIME,");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,A,16,DATE,");
    //Row17
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,I,17," + String(Cp8, 4));
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,E,17," + value_8);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,17,0.95");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,17," + i);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,B,17,TIME,");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,A,17,DATE,");

    //Pitot_Static
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,F,18," + pressurePitot);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,G,18," + pressureStatic);
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,H,18," + sqrt (airspeed));

    //Cl Upper Surface
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,33,Cl Upper 1 =");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,34,=SUM((D3-D2))*((I2+I3)/2)");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,35,Cl Upper 2 =");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,36,=SUM((D4-D3))*((I3+I4)/2)");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,37,Cl Upper 3 =");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,38,=SUM((D5-D4))*((I4+I5)/2)");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,39,Cl Upper 4 =");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,40,=SUM((D6-D5))*((I5+I6)/2)");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,41,Cl Upper 5 =");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,42,=SUM((D7-D6))*((I6+I7)/2)");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,43,Cl Upper 6 =");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,44,=SUM((D8-D7))*((I7+I8)/2)");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,45,Cl Upper 7 =");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,46,=SUM((D9-D8))*((I8+I9)/2)");
    // Cl lower surface
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,47,Cl Lower 1 =");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,48,=SUM((D3-D2))*((I10+I11)/2)");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,49,Cl Lower 2 =");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,50,=SUM((D4-D3))*((I11+I12)/2)");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,51,Cl Lower 3 =");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,52,=SUM((D5-D4))*((I12+I13)/2)");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,53,Cl Lower 4 =");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,54,=SUM((D6-D5))*((I13+I14)/2)");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,55,Cl Lower 5 =");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,56,=SUM((D7-D6))*((I14+I15)/2)");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,57,Cl Lower 6 =");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,58,=SUM((D8-D7))*((I15+I16)/2)");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,59,Cl Lower 7 =");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,60,=SUM((D9-D8))*((I16+I17)/2)");
    //Sum
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,21,Upper =");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,21,=SUM(((D9-D2)/2)/7)*((I2+(2*(I3))+(2*(I4))+(2*(I5))+(2*(I6))+(2*(I7))+(2*(I8))+(I9)))");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,22,Lower =");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,22,=SUM(((D9-D2)/2)/7)*((I10+(2*(I11))+(2*(I12))+(2*(I13))+(2*(I14))+(2*(I15))+(2*(I16))+(I17)))");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,C,23,Cl =");
    Serial.println((String)"CELL,SET,ONSHEET,Simple Data,D,23,=(D22-D21)");
    startTime = millis() ;

  }


}

void get_Serial_2() {

  while (Serial2.available()) {
    DynamicJsonBuffer jSonDv2;
    JsonObject& TxDevice_2 = jSonDv2.parseObject(Serial2); // Recive JsonObject from Device_2
    if (TxDevice_2.success()) {

      String Rxdv2_DeiveName = TxDevice_2.get<String>("Device_Name_2");
      String Rxdv2_Point5    = TxDevice_2.get<String>("SensorPoint_5");
      String Rxdv2_Sensor_5  = TxDevice_2.get<String>("Sensor_5");
      String Rxdv2_Point6    = TxDevice_2.get<String>("SensorPoint_6");
      String Rxdv2_Sensor_6  = TxDevice_2.get<String>("Sensor_6");
      String Rxdv2_Point7    = TxDevice_2.get<String>("SensorPoint_7");
      String Rxdv2_Sensor_7  = TxDevice_2.get<String>("Sensor_7");
      String Rxdv2_Point8    = TxDevice_2.get<String>("SensorPoint_8");
      String Rxdv2_Sensor_8  = TxDevice_2.get<String>("Sensor_8");

      point_5 = Rxdv2_Point5  ;
      value_5 = Rxdv2_Sensor_5 ;
      point_6 = Rxdv2_Point6  ;
      value_6 = Rxdv2_Sensor_6 ;
      point_7 = Rxdv2_Point7  ;
      value_7 = Rxdv2_Sensor_7 ;
      point_8 = Rxdv2_Point8  ;
      value_8 = Rxdv2_Sensor_8 ;


    }
  }
}

void get_Serial_1() {

  while (Serial1.available()) {
    DynamicJsonBuffer jSonDv1;
    JsonObject& TxDevice_1 = jSonDv1.parseObject(Serial1); // Recive JsonObject from Device_1


    if (TxDevice_1.success()) {

      String Rxdv1_DeiveName = TxDevice_1.get<String>("Device_Name");
      String Rxdv1_Point1    = TxDevice_1.get<String>("SensorPoint_1");
      String Rxdv1_Sensor_1  = TxDevice_1.get<String>("Sensor_1");
      String Rxdv1_Point2    = TxDevice_1.get<String>("SensorPoint_2");
      String Rxdv1_Sensor_2  = TxDevice_1.get<String>("Sensor_2");
      String Rxdv1_Point3    = TxDevice_1.get<String>("SensorPoint_3");
      String Rxdv1_Sensor_3  = TxDevice_1.get<String>("Sensor_3");
      String Rxdv1_Point4    = TxDevice_1.get<String>("SensorPoint_4");
      String Rxdv1_Sensor_4  = TxDevice_1.get<String>("Sensor_4");


      point_1 = Rxdv1_Point1  ;
      value_1 = Rxdv1_Sensor_1 ;
      point_2 = Rxdv1_Point2  ;
      value_2 = Rxdv1_Sensor_2 ;
      point_3 = Rxdv1_Point3  ;
      value_3 = Rxdv1_Sensor_3 ;
      point_4 = Rxdv1_Point4  ;
      value_4 = Rxdv1_Sensor_4 ;

    }
  }
}
void Pitot_Static() { // For get pressure from Pitot and Static sensor.
  rawValuePitot = 0;
  rawValueStatic = 0;
  for (int x_pitot = 0; x_pitot < 10; x_pitot++) rawValuePitot = rawValuePitot + analogRead(A0);
  pressurePitot = (rawValuePitot - offset) * 700.0 / (fullScale - offset);
  for (int x_static = 0; x_static < 10; x_static++) rawValueStatic = rawValueStatic + analogRead(A1);
  pressureStatic = (rawValueStatic - offset) * 700.0 / (fullScale - offset);

}
