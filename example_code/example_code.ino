/*
  @@@@@@@@@@@@@@@@@@@@@@                                                                                                                               
  @@@@@@@@@@@@@@@@@@@@@@             @@@.    @@@    @@@.     @@@@    @@@@        @@@@@@@@@        @@@@@@@@@@@@@.     .@@@@@@@@@@@@@        @@@@@@@@@  
  @@@@@%%@@@%%@@@%%@@@@@             @@@@    @@@    @@@@     @@@@    @@@@       @@@@@@@@@@        @@@@@@@@@@@@@@     @@@@@@@@@@@@@@        @@@@@@@@@  
  @@@@@  @@@  @@@  @@@@@             @@@@    @@@    @@@@     @@@@    @@@@       @@@@   @@@@        @@@@@   @@@@@       @@@@@   @@@@       @@@@   @@@@ 
  @@@@@            @@@@@             @@@@   @@@@    @@@@     @@@@@@@@@@@@       @@@@   @@@@        @@@@@   @@@@@       @@@@@   @@@@       @@@@   @@@@ 
  @@@@@   @    @   @@@@@             @@@@   @@@@    @@@@     @@@@@@@@@@@@       @@@@@@@@@@@        @@@@@   @@@@@       @@@@@   @@@@       @@@@@@@@@@@ 
  @@@@@            @@@@@             @@@@###@@@@@##@@@@@     @@@@    @@@@      @@@@@@@@@@@@       #@@@@@###@@@@@     ##@@@@@###@@@@       @@@@@@@@@@@
  @@@@@@@@@@@@@@@@@@@@@@             @@@@@@@@@@@@@@@@@@@     @@@@    @@@@      @@@@    @@@@@      @@@@@@@@@@@@@@     @@@@@@@@@@@@@@      @@@@     @@@@
  @@@@@@@@@@@@@@@@@@@@@@
  
  Whadda WPSE353 micro PIR sensor module example
  
  This example will print out a message and light up the built in LED when the sensor has detected motion

  For more information about the Whadda WPSE353 micro PIR sensor module, check the manual available at https://whadda.com
  
 
  Author: Midas Gossye (Whadda/Velleman)
  Date: 15/03/2021
  URL: https://github.com/WhaddaMakers/Micro_PIR_sensor
*/

const int sens_pin = 2; // Set pin number connected to sensor
const int LED_pin = 13;


void setup() {
  Serial.begin(9600);
  pinMode(sens_pin, INPUT);
  pinMode(LED_pin, OUTPUT);

  Serial.println("Connect the PIR sensor's S pin to Digital Pin 2");
  Serial.println("I will print out a message and light up the built-in LED when I detect something...");
  Serial.println();
}

void loop() {

  if(digitalRead(sens_pin) == HIGH) {
    Serial.println("I detected motion!");
    digitalWrite(LED_pin, HIGH);
    while(digitalRead(sens_pin) == HIGH)
    {
      delay(10);
    }
    digitalWrite(LED_pin, LOW);
  }

}
