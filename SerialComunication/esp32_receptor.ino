#include "BluetoothSerial.h"
#include <ESP32Servo.h>

BluetoothSerial SerialBT;
Servo servo;
int pinServo=13;
int adelante=12;
int atras=14;

int cont=0;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("Intruder BT");
  servo.attach(pinServo, 500, 2500);
  analogWrite(atras, 0);
  analogWrite(adelante, 0);
}

void loop() {
  if (SerialBT.available()) {
    String datoBt = SerialBT.readStringUntil('#');
    interpretar(datoBt);
  }
  delay(20);
}


void interpretar(String datos){
  int angulo = datos.substring(0,3).toInt();
  int potencia = datos.substring(3,6).toInt();
  char boton = datos.charAt(6);

  int x = valorX(potencia,angulo);
  int y = valorY(potencia,angulo);

  movimiento(x,y);

}

void movimiento(int x, int y){
  if(x>15){
    girar((x*0.4)+90);
  }else{
    girar(0);
  }
  if(x<-15){
    girar((x*0.4)+90);
  }else{
    girar(0);
  }

  if(y>20){
    acelerar(y);
  }
  if(y<-20){
    reversa(-y);
  }
  if(y==0){
    frenar();
  }
}

void girar(int grados){
  servo.write(grados);
}

void acelerar(int velocidad){
  int vel = (velocidad*255)/100;
  Serial.print("adelante:");
  Serial.println(vel);
  analogWrite(adelante, vel);
  analogWrite(atras, 0);
}

void reversa(int velocidad){
  int vel = (velocidad*255)/100;
  Serial.print("atras:");
  Serial.println(vel);
  analogWrite (atras, vel);
  analogWrite (adelante, 0);
}

void frenar(){
  Serial.println("Frenando");
  analogWrite(atras, 0);
  analogWrite(adelante, 0);
}

int valorX(int potencia, int angulo){
  float angulo_rad = (angulo * 3.141592) / 180.0;
  int x = round(potencia * sin(angulo_rad));
  return (-x);
}

int valorY(int potencia, int angulo){
  float angulo_rad = (angulo * 3.141592) / 180.0;
  float correccion = ((potencia*28)/100) * cos((angulo_rad-0.7854)*4);
  int y = round(potencia * cos(angulo_rad));
  if(correccion>0 && y>0){
    y = y + correccion;
  }
  return y;
}
