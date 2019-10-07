#include "Sensor.h"
#include <SPI.h>
#include <SD.h>

File file;
String nameFile;

Sensor sensorAgua;

void setup() {
  Serial.begin(9600);
  if(!connectToSD()){
    return -1;
  } 
  sensorAgua.SetNombre("Nombre");    
}

void loop() { 
  double valorSensor = 10.0;
  sensorAgua.SetValor(valorSensor);
  writeFileSD(sensorAgua.GetJSON());
}

boolean connectToSD(){
   if (!SD.begin(4)) {    
    while (1);
    return false;    
  }  
  return true;
}

void openSD() {
  file = SD.open(nameFile, FILE_WRITE);
}

boolean writeFileSD(String format){
   openSD();
  if(file){
    file.println(format);
  }
  file.close();
}
