#include <SoftwareSerial.h>

SoftwareSerial mySerial(5,4); //Rx et Tx

#include <Hx711.h>
Hx711 scale(A0, A1);

void tare ();
void setColor(int red, int green, int blue);
const int redPin=13;
const int greenPin=11;
const int bluePin=12;
int poidsVal;
int tareVal=0;
int buzzer=2;
const int speed=9600;
int valMax=0;
int valBT=0;

void setup() {

Serial.begin(9600);
mySerial.begin(9600);

pinMode(greenPin,OUTPUT);
pinMode(redPin,OUTPUT);
pinMode(bluePin,OUTPUT);
mySerial.print("Choisissez la valeur de l'ingrédient \n");


}

void loop() {

if(valMax==0)
{
  setColor(255,255,255);
  delay(1000);
  setColor(0,0,0);
  delay(1000);
}
  int changementColor;
  if(mySerial.available())
  {
   valMax=mySerial.parseInt();
   
   //Serial.print(mySerial.parseInt());
  }
  
  poidsVal=scale.getGram() - tareVal;

  int p=(poidsVal*100/valMax)*2.55;
  
  if(p < 255/2)
  {
    setColor(255,p*2,0);
  }

  else if (p>255/2 && p<255)
  {
    changementColor = 255 - (p*2 - 255);
    setColor(changementColor,255,0);
  }
  else 
  {
    setColor(0,0,255);
    tare ();
  }

    delay(10);
    Serial.print("poidsVal : ");
    Serial.println(poidsVal);
    Serial.print("valMax : ");
    Serial.println(valMax);
    mySerial.println(poidsVal);
  
 }
  
void tare ()
{
  tareVal+= poidsVal;
  tone(buzzer,2000,20);
  delay(100);
  tone(buzzer,2500,20);
  delay(100);
  tone(buzzer,1500,20);
  delay(100);
  tone(buzzer,3000,20);
  delay(5000);
}
void setColor(int red, int green, int blue)
  {
    analogWrite(redPin,red);
    analogWrite(greenPin,green);
    analogWrite(bluePin,blue);
  }
