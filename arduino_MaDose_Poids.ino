
//bluetooth
/* #include <SoftwareSerial.h>
SoftwareSerial mavoieserie(10 , 11 ); //Rx et Tx

mavoiserie.begin(speed);// démarre la voie série à la vitesse speed
mavoiserie.available(); // retourne le nombre de caractère à lire
mavoieserie.read();     // retourne le prochain caractère reçu
mavoiserie.write(val);  // envoie le char "val" sur la voie série
*/

#include <Hx711.h>
Hx711 scale(A0, A1);

void tare ();
void setColor(int red, int green, int blue);
const int redPin=13;
const int greenPin=11;
const int bluePin=12;
int poidsVal;
int valMax;
int tareVal=0;
int buzzer=2;


void setup() {

Serial.begin(9600);


pinMode(greenPin,OUTPUT);
pinMode(redPin,OUTPUT);
pinMode(bluePin,OUTPUT);

}

void loop() {
 
  int changementColor;
  int poidsMaxIngredient=100;
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
    Serial.print ("getGram");
    Serial.println(scale.getGram());
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
