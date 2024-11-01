/* 
 * Project MyCoolMidtrurn
 * Author: Joseph Maes
 * Date:10/31/2024
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs

#include "Particle.h"
#include "IoTClassroom_CNM.h"

const int BUTTON=D3;
int inputValue;
const int BULB=3; 
int color;


// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(SEMI_AUTOMATIC);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(ENABLED);

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);

// setup() runs once, when the device is first turned on
void setup() {
  pinMode(BUTTON,INPUT_PULLDOWN);
  Serial.begin(9600);
  waitFor(Serial.isConnected,10000);
  
  
WiFi.on();
  WiFi.clearCredentials();
  WiFi.setCredentials("IoTNetwork");
  
  WiFi.connect();
  while(WiFi.connecting()) {
    Serial.printf(".");
  
  }
Serial.println (" Ready to Go");

}
void loop() {
  inputValue=digitalRead(BUTTON);
  Serial.printf("BUTTON=%i\n",inputValue);

Serial.printf("Setting color of bulb %i to color %06i\n",BULB,HueRainbow[color%7]);
  setHue(BULB,true,HueRainbow[color%7],random(32,255),255);
  color++;
  delay(5000);
 }

