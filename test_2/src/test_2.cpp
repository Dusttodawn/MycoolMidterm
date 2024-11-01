/* 
 * Project test2
 * Author: Joseph Maes
 * Date: 10/31/2024
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */


#include "Particle.h"
#include "IoTclassroom_CNM.h"


bool OnOff; //use this to toggle between true or false (on or off)
const int BULB=3; 
int color;

Button hueButton(D3); //create button object from button class
SYSTEM_MODE(MANUAL);


SYSTEM_THREAD(ENABLED);


void setup() {
  Serial.begin(9600);
  waitFor(Serial.isConnected,15000);

  WiFi.on();
  WiFi.clearCredentials();
  WiFi.setCredentials("IoTNetwork");
  
  WiFi.connect();
  while(WiFi.connecting()) {
    Serial.printf(".");
  }
  Serial.printf("\n\n");
 
}


void loop() {
  if(hueButton.isClicked()){
    OnOff =! OnOff;
  }
if(OnOff){ 
}
if(!OnOff){

    Serial.printf("Setting color of bulb %i to color %06i\n",BULB,HueRainbow[color%7]);
  setHue(BULB,true,HueRainbow[color%7],random(32,255),255);
  color++;
  delay(5000);

}
